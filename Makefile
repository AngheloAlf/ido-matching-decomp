# Build options can be changed by modifying the makefile or by building with 'make SETTING=value'.
# It is also possible to override the settings in Defaults in a file called .make_options as 'SETTING=value'.

-include .make_options

#### Defaults ####

# select the version and binaries of IDO toolchain to disassemble and build
VERSION ?= 7.1
# if WERROR is 1, pass -Werror to CC_CHECK, so warnings would be treated as errors
WERROR ?= 0
CC_CHECK_COMP ?= gcc

ifeq ($(VERSION),7.1)
#	IDO_TC      := cc acpp as0 as1 cfe ugen ujoin uld umerge uopt usplit
	IDO_TC      := cc cfe
else ifeq ($(VERSION),5.3)
#	IDO_TC      := cc acpp as0 as1 cfe copt ugen ujoin uld umerge uopt usplit
	IDO_TC      := c++filt
else
$(error Unknown or unsupported IDO version - $(VERSION))
endif


#### Tools ####
MIPS_BINUTILS_PREFIX ?= mips-linux-gnu-
ifneq ($(shell type $(MIPS_BINUTILS_PREFIX)ld >/dev/null 2>/dev/null; echo $$?), 0)
$(error Please install or build mips-linux-gnu)
endif

RECOMP  := tools/recomp
BUILD   := build
ASM     := asm
SYMBOLS := symbols
CONTEXT := context

CC       := $(RECOMP)/build/$(VERSION)/out/cc

AS         := $(MIPS_BINUTILS_PREFIX)as
LD         := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY    := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP    := $(MIPS_BINUTILS_PREFIX)objdump
MIPS_GCC   := $(MIPS_BINUTILS_PREFIX)gcc

DISASSEMBLER  := python3 -m spimdisasm.elfObjDisasm
DISASSEMBLER_FLAGS += --no-emit-cpload --Mreg-names o32 --no-use-fpccsr --aggressive-string-guesser --print-new-file-boundaries --asm-jtbl-label jlabel --asm-data-label dlabel
ASM_PROCESSOR := python3 tools/asm-processor/build.py

IINC       := -Iinclude -Iinclude/indy -Isrc

# Check code syntax with host compiler
CHECK_WARNINGS := -Wall -Wextra -Wno-unknown-pragmas -Wno-unused-variable -Wno-char-subscripts -Wno-unused-label -Wno-parentheses -Wno-unused-parameter
# Have CC_CHECK pretend to be a MIPS compiler
MIPS_BUILTIN_DEFS := -D_MIPS_FPSET=16 -D_MIPS_ISA=2 -D_ABIO32=1 -D_MIPS_SIM=_ABIO32 -D_MIPS_SZINT=32 -D_MIPS_SZLONG=32 -D_MIPS_SZPTR=32
MIPS_BUILTIN_DEFS += -D__EXTENSIONS__ -DLANGUAGE_C -D_LANGUAGE_C -D__INLINE_INTRINSICS
MIPS_BUILTIN_DEFS += -Dsgi -D__sgi -Dunix -Dmips -Dhost_mips -D__unix -D__host_mips -D_SVR4_SOURCE
MIPS_BUILTIN_DEFS += -D_MODERN_C -D_SGI_SOURCE -D__DSO__ -DSYSTYPE_SVR4 -D_SYSTYPE_SVR4 -D_LONGLONG
MIPS_BUILTIN_DEFS += -D__mips=2 -D_MIPSEB -DMIPSEB -D_CFE
MIPS_BUILTIN_DEFS += -DPERMUTER=1
#	The -MMD flags additionaly creates a .d file with the same name as the .o file.
CC_CHECK          := $(CC_CHECK_COMP)
CC_CHECK_FLAGS    := -MMD -fno-builtin -fsyntax-only -fsigned-char -std=c11 -m32 -DNON_MATCHING -DCC_CHECK=1
ifneq ($(WERROR), 0)
	CHECK_WARNINGS += -Werror
endif


LDFLAGS := -nostdlib -L$(RECOMP)/ido/$(VERSION)/usr/lib/ -lc


ASMPROCFLAGS := 
OPTFLAGS := -O1
MIPS_VERSION := -mips2
ASFLAGS := -march=vr4300 -32 -Iinclude -KPIC

IDO_WARNINGS := -fullwarn -woff 624,649,838,712,835
CFLAGS += -G 0 -KPIC -Xcpluscomm $(IINC) -nostdinc -Wab,-r4300_mul $(IDO_WARNINGS)


# -- Location of original IDO binaries
IRIX_BASE    ?= $(RECOMP)/ido
IRIX_USR_DIR ?= $(IRIX_BASE)/$(VERSION)/usr

# We use a sentinel file for disassembling each binary
DISASM_TARGETS := $(foreach binary,$(IDO_TC),$(ASM)/$(VERSION)/$(binary)/.disasm)


SRC_DIRS := $(shell find src/$(VERSION) -type d)
ASM_DIRS := $(shell find asm/$(VERSION) -type d -not -path "asm/$(VERSION)/functions*")

C_FILES  := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES  := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))

O_FILES  := $(foreach f,$(C_FILES:.c=.o),$(BUILD)/$(f)) \
            $(foreach f,$(S_FILES:.s=.o),$(BUILD)/$(f))

# Automatic dependency files
DEP_FILES := $(O_FILES:.o=.d) \
             $(O_FILES:.o=.asmproc.d)

# create build directories
$(shell mkdir -p $(foreach dir,$(SRC_DIRS) $(ASM_DIRS),$(BUILD)/$(dir)))


$(BUILD)/src/%.o: CC := $(ASM_PROCESSOR) $(ASM_PROC_FLAGS) $(CC) -- $(AS) $(ASFLAGS) --


build/src/7.1/mld/%.o: OPTFLAGS := -O2
build/src/5.3/%.o: MIPS_VERSION := -mips1
build/src/5.3/c++filt/c++filt.o: OPTFLAGS := -O2

# Targets

.PHONY: all clean distclean setup disasm
.DEFAULT_GOAL:= all

all: $(ELFS) $(O_FILES)

clean:
	$(RM) -r $(BUILD)

distclean: clean
	$(MAKE) -C $(RECOMP) clean
	$(RM) -r $(ASM)

setup:
	$(MAKE) -C $(RECOMP) setup
	$(MAKE) -C $(RECOMP) DEBUG=0 VERSION=7.1
	$(MAKE) -C $(RECOMP) DEBUG=0 VERSION=5.3

disasm: $(DISASM_TARGETS)


$(BUILD)/$(ASM)/$(VERSION)/%.elf: $(O_FILES)
	$(LD) $(BUILD)/$(ASM)/$(VERSION)/$*/*.o $(LDFLAGS) --no-check-sections --accept-unknown-input-arch --allow-shlib-undefined -Map $(BUILD)/$(ASM)/$(VERSION)/$*.map -o $@ || (rm -f $@ && exit 1)

$(BUILD)/$(ASM)/%.o: $(ASM)/%.s
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD)/%.o: %.c
	$(CC_CHECK) $(CC_CHECK_FLAGS) $(IINC) $(CHECK_WARNINGS) $(MIPS_BUILTIN_DEFS) -o $@ $<
	$(CC) -c $(CFLAGS) $(MIPS_VERSION) $(OPTFLAGS) -o $@ $<


## Disassembly

# cc is special and is stored in a different folder
$(ASM)/$(VERSION)/cc/.disasm: $(IRIX_USR_DIR)/bin/cc
	$(DISASSEMBLER) $(DISASSEMBLER_FLAGS) --file-splits $(SYMBOLS)/$(VERSION)/cc.splits.csv --split-functions $(ASM)/$(VERSION)/functions/cc --save-context $(CONTEXT)/$(VERSION)/cc.csv $< $(dir $@)

$(ASM)/$(VERSION)/%/.disasm: $(IRIX_USR_DIR)/lib/%
	$(DISASSEMBLER) $(DISASSEMBLER_FLAGS) --file-splits $(SYMBOLS)/$(VERSION)/$*.splits.csv --split-functions $(ASM)/$(VERSION)/functions/$* --save-context $(CONTEXT)/$(VERSION)/$*.csv $(IRIX_USR_DIR)/lib/$* $(ASM)/$(VERSION)/$*

$(ASM)/$(VERSION)/%/.disasm: $(IRIX_USR_DIR)/lib/c++/%
	$(DISASSEMBLER) $(DISASSEMBLER_FLAGS) --file-splits $(SYMBOLS)/$(VERSION)/$*.splits.csv --split-functions $(ASM)/$(VERSION)/functions/$* --save-context $(CONTEXT)/$(VERSION)/$*.csv $(IRIX_USR_DIR)/lib/c++/$* $(ASM)/$(VERSION)/$*



print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

-include $(DEP_FILES)
