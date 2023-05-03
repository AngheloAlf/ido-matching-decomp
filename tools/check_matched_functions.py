#!/usr/bin/env python3

import argparse
from pathlib import Path
import spimdisasm


def configureSpimdisasm():
    spimdisasm.common.GlobalConfig.ALLOW_UNKSEGMENT = False
    spimdisasm.common.GlobalConfig.INPUT_FILE_TYPE = spimdisasm.common.InputFileType.ELF
    spimdisasm.common.GlobalConfig.EMIT_CPLOAD = False


def getFuncsFromElf(elfFile: spimdisasm.elf32.Elf32File, syms: spimdisasm.elf32.Elf32Syms, strTable: spimdisasm.elf32.Elf32StringTable):
    print(f"Symbols count: {len(syms)}")

    for sym in syms:
        if sym.stType != spimdisasm.elf32.Elf32SymbolTableType.FUNC.value:
            continue

        if sym.shndx == spimdisasm.elf32.Elf32SectionHeaderNumber.UNDEF.value:
            continue
        print(sym, strTable[sym.name])

    print(elfFile.progbits[spimdisasm.common.FileSectionType.Text])


def doElf(elfPath: Path):
    print(elfPath)

    context = spimdisasm.common.Context()

    originalElfBytes = spimdisasm.common.Utils.readFileAsBytearray(elfPath)

    elfFile = spimdisasm.elf32.Elf32File(originalElfBytes)

    elfFile.handleHeaderIdent()
    elfFile.handleFlags()


    # assert ogElf.dynsym is not None and ogElf.dynstr is not None
    # getFuncsFromElf(ogElf, ogElf.dynsym, ogElf.dynstr)


    processedSegments, segmentPaths = spimdisasm.elfObjDisasm.getProcessedSections(context, elfFile, originalElfBytes, elfPath, Path("-"), Path("-"))

    spimdisasm.elfObjDisasm.changeGlobalSegmentRanges(context, processedSegments)

    spimdisasm.elfObjDisasm.processGlobalOffsetTable(context, elfFile)

    spimdisasm.elfObjDisasm.injectAllElfSymbols(context, elfFile, processedSegments)

    processedFilesCount = 0
    for sect in processedSegments.values():
        processedFilesCount += len(sect)

    spimdisasm.frontendCommon.FrontendUtilities.analyzeProcessedFiles(processedSegments, segmentPaths, processedFilesCount)

    for textSection in processedSegments[spimdisasm.common.FileSectionType.Text]:
        for func in textSection.symbolList:
            print(func.getName())
            # print(func.)
    # print(processedSegments)
    # spimdisasm.frontendCommon.FrontendUtilities.writeProcessedFiles(processedSegments, segmentPaths, processedFilesCount)

    return elfFile, context, processedSegments


def main():
    parser = argparse.ArgumentParser(description="")
    parser.add_argument("main_elf", help="")
    parser.add_argument("o_files", help="", nargs="+")

    args = parser.parse_args()

    configureSpimdisasm()

    mainElfPath = Path(args.main_elf)
    oFilesPaths = [Path(x) for x in args.o_files]

    doElf(mainElfPath)

    for oFile in oFilesPaths:
        doElf(oFile)

if __name__ == "__main__":
    main()
