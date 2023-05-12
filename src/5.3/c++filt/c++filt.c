#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

typedef signed char            s8;
typedef unsigned char          u8;
typedef signed short int       s16;
typedef unsigned short int     u16;
typedef signed int             s32;
typedef unsigned int           u32;
typedef signed long long int   s64;
typedef unsigned long long int u64;

typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float  f32;
typedef double f64;

typedef s32 UNK_TYPE;
typedef u8 UNK_TYPE1;

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/_ftext.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00400BD0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/__start.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/_mcount.s")


// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00400DE4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00400E64.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00400EF8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00400FA4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_004010F8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_004011B4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00401A70.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00401B48.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00402D50.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printcl.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printarglist.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printarg.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004A4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004AC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004B8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004C0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004CC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004D4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004E0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004E8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100004F8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000500.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000510.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000518.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000524.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000052C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000538.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000540.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000054C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000554.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000560.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000568.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000574.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000057C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000588.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000590.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000059C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005A4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005B0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005B8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005C4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005CC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005D8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005E0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005EC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100005F4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000600.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000608.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000614.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000061C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000628.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000630.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000063C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000644.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000650.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000658.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000664.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000066C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000678.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000680.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000068C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000694.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006A0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006A8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006B4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006BC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006C8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006D0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006DC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006E4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006F0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100006F8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000704.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000070C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000718.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000720.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000072C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000734.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000740.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000748.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000754.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000075C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000768.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000770.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_1000077C.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000784.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000790.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000798.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100007A4.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100007AC.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100007B8.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_100007C0.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printfunc.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_print.s")

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_explain.s")

int demangle(char*, char*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/demangle.s")

#ifdef NON_MATCHING
// static
void func_004054C0(FILE* arg0) {
    char sp458[0x400];
    char sp50[0x458-0x50];
    char* var_s0;
    char* temp_a0;
    int var_v0;

    while (fgets(sp458, 0x400, arg0) != NULL) {
        var_s0 = sp458;

        while (1) {
            while ((*var_s0 != 0) && (*var_s0 < 0x21)) {
                putc_locked(*var_s0, stdout);

                var_s0 += 1;
            }

            if (*var_s0 == 0) {
                break;
            }

            temp_a0 = var_s0;
            while ((*var_s0 != 0) && (*var_s0 >= 0x21)) {
                var_s0 += 1;
            }

            var_v0 = *var_s0;

            *var_s0 = 0;
            demangle(temp_a0, sp50);
            printf("%s", sp50);
            *var_s0 = var_v0;
        }
    }
}
#else
// static
void func_004054C0(FILE*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_004054C0.s")
#endif

int main(int argc, char** argv) {
    int ret = 0;

    if (argc < 2) {
        func_004054C0(stdin);
    } else {
        int i;

        for (i = 1; i < argc; i++) {
            FILE* f = fopen(argv[i], "r");

            if (f == NULL) {
                fprintf(stderr, "cannot open %s for reading\n", argv[i]);
                ret++;
            } else {
                func_004054C0(f);
                fclose(f);
            }
        }
    }

    exit(ret);
    return 0;
}


// releaseid
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/STR_10000CA0.s")

