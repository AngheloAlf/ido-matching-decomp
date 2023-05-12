#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

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
#define UNK_SIZE 1


typedef struct struct_demangle_sp24 {
    /* 0x00 */ char* unk_0;
    /* 0x04 */ UNK_TYPE1 pad_4[8];                       /* maybe part of unk_0[3]? */
    /* 0x0C */ char **unk_C;
    /* 0x10 */ UNK_TYPE unk_10;                          /* inferred */
    /* 0x14 */ UNK_TYPE1 pad_14[6];                      /* maybe part of unk_10[2]? */
    /* 0x1A */ u8 unk_1A;                           /* inferred */
    /* 0x1B */ UNK_TYPE1 pad_1B[1];
} struct_demangle_sp24; // size = 0x1C


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

#if 0
? func_00400DE4(?*, ?, ?, void**);                  /* extern */
void* func_00400EF8(s8*, s32, s8*);                 /* extern */
? func_00400FA4(s8*, ?);                            /* extern */
s32 func_004011B4();                                /* extern */
s32 func_00401B48(?, ?, ?, u8*);                    /* extern */
s32 func_00402D50();                                /* extern */
extern s32 B_10000DD0;
extern u8 B_10000DD4;
extern s8* B_10000DD8;
extern s32 B_10000DDC;
extern s32 D_10000000;
extern s32 D_10000004;

int dem(char* arg0, void** arg1, s32 arg2) {
    u8 sp460;
    s32 sp45C;
    s32 sp458;
    u8* sp448;
    s8 sp40;
    s32 sp3C;
    u8* sp30;
    s32 temp_a1;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t6_2;
    s32 temp_t6_5;
    s32 temp_t7_2;
    s32 temp_t8;
    s32 temp_t8_2;
    s32 temp_t8_4;
    s32 temp_t8_6;
    s32 temp_t9_2;
    s32 temp_t9_4;
    s32 temp_v0_11;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a2;
    s32 var_v0_4;
    s32 var_v1_2;
    s32 var_v1_5;
    s8* temp_v0_10;
    s8* temp_v0_6;
    s8* temp_v0_9;
    s8* temp_v1_2;
    s8* var_a0;
    s8* var_a0_2;
    s8* var_a0_3;
    s8* var_v1;
    s8* var_v1_4;
    u8 temp_a0;
    u8 temp_a1_2;
    u8 temp_a1_3;
    u8 temp_a1_4;
    u8 temp_t6;
    u8 temp_t6_3;
    u8 temp_t6_4;
    u8 temp_t6_6;
    u8 temp_t6_7;
    u8 temp_t7;
    u8 temp_t8_3;
    u8 temp_t8_5;
    u8 temp_t8_7;
    u8 temp_t8_8;
    u8 temp_t9;
    u8 temp_t9_3;
    u8 temp_v0;
    u8 temp_v0_12;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v1;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 var_v0;
    u8 var_v0_3;
    u8 var_v1_3;
    u8* temp_a3;
    u8* var_a3;
    u8* var_t8;
    void* temp_a0_2;
    void* temp_v0_13;
    void* temp_v0_14;
    void* var_v0_2;

    if ((arg0 == NULL) || (arg1 == NULL) || (arg2 == 0)) {
        return -1;
    }
    if (arg0->unk_0 == 0) {
        return -1;
    }
    B_10000DD0 = arg2;
    D_10000004 = -1;
    D_10000000 = 0;
    arg1->unk_8 = 0;
    arg1->unk_C = 0;
    arg1->unk_1A = 0U;
    arg1->unk_10 = 0;
    arg1->unk_0 = NULL;
    arg1->unk_4 = NULL;
    arg1->unk_18 = (s16) -1;
    arg1->unk_14 = 0;
    temp_v1 = arg0->unk_0;
    if ((temp_v1 == 0x5F) && (arg0->unk_1 == 0x5F)) {
        var_a0 = arg0 + 2;
        temp_t8 = __ctype[arg0->unk_2].unk_1 & 4;
        if (temp_t8 != 0) {
            var_a1 = 0;
            if (temp_t8 != 0) {
                var_v0 = *var_a0;
                do {
                    var_a0 += 1;
                    temp_a1 = var_v0 + (var_a1 * 0xA);
                    var_v0 = *var_a0;
                    var_a1 = temp_a1 - 0x30;
                } while (__ctype[var_v0].unk_1 & 4);
            }
            if (*var_a0 != 0) {
                sp458 = var_a1;
                var_v0_2 = func_00400EF8(var_a0, var_a1, arg0);
                arg1->unk_18 = (s16) var_a1;
                goto block_187;
            }
            goto block_14;
        }
    }
block_14:
    if ((temp_v1 == 0x5F) && (arg0->unk_1 == 0x5F) && ((strncmp(arg0, "__sti__", 7U) == 0) || (strncmp(arg0, "__std__", 7U) == 0) || (strncmp(arg0, "__ptbl_vec__", 0xCU) == 0))) {
        arg1->unk_1A = (u8) arg0->unk_4;
        var_a0_2 = arg0 + 0xC;
        if (arg0->unk_2 == 0x73) {
            var_a0_2 = arg0 + 7;
        }
        var_v0_3 = (u8) *var_a0_2;
        if (var_v0_3 == 0x5F) {
            do {
                var_v0_3 = var_a0_2->unk_1;
                var_a0_2 += 1;
            } while (var_v0_3 == 0x5F);
        }
        var_v1 = var_a0_2;
        if ((var_v0_3 != 0) && (((u8) var_v1->unk_0 != 0x5F) || (var_v1->unk_1 != 0x63) || (var_a0_2->unk_2 != 0x5F))) {
loop_27:
            temp_v0 = var_v1->unk_1;
            var_v1 += 1;
            if (temp_v0 != 0) {
                if ((temp_v0 != 0x5F) || (var_v1->unk_1 != 0x63) || (var_v1->unk_2 != 0x5F)) {
                    goto loop_27;
                }
            }
        }
        *var_v1 = 0;
        if ((u8) var_a0_2->unk_0 == 0) {
            return -1;
        }
        arg1->unk_0 = func_00400EF8(var_a0_2);
        B_10000DD4 = 0;
        goto block_188;
    }
    temp_a1_2 = (u8) arg0->unk_0;
    var_a0_3 = arg0;
    var_v1_2 = 0;
    if ((temp_a1_2 != 0) && (((u8) var_a0_3->unk_0 != 0x5F) || (var_a0_3 == arg0) || (arg0->unk_-1 != 0x5F))) {
loop_38:
        temp_v0_2 = var_a0_3->unk_1;
        var_a0_3 += 1;
        if (temp_v0_2 != 0) {
            if ((temp_v0_2 != 0x5F) || (var_a0_3 == arg0) || (var_a0_3->unk_-1 != 0x5F)) {
                goto loop_38;
            }
        }
    }
    temp_v0_3 = (u8) var_a0_3->unk_0;
    if ((temp_v0_3 == 0x5F) && (var_a0_3->unk_1 == 0x70) && (var_a0_3->unk_2 == 0x74) && (var_a0_3->unk_3 == 0x5F) && (var_a0_3->unk_4 == 0x5F)) {
        var_v1_2 = 1;
    }
    if ((temp_v0_3 == 0x5F) && (var_a0_3->unk_1 == 0x5F) && (var_a0_3->unk_2 == 0x70) && (var_a0_3->unk_3 == 0x74) && (var_a0_3->unk_4 == 0x5F) && (var_a0_3->unk_5 == 0x5F)) {
        var_v1_2 = 1;
    }
    if ((var_v1_2 == 0) && (temp_a1_2 == 0x5F) && (arg0->unk_1 == 0x5F) && (arg0->unk_2 == 0x51) && (__ctype[arg0->unk_3].unk_1 & 4) && (arg0->unk_4 == 0x5F)) {
        var_v1_2 = 2;
    }
    if (var_v1_2 != 0) {
        D_10000004 = -1;
        D_10000000 = 0;
        if (var_v1_2 == 1) {
            sprintf(&sp40, "%d%s", strlen(arg0), arg0);
            func_00400FA4(&sp40, 0x270F);
        } else {
            func_00400FA4(arg0 + 2, 0x270F);
        }
        temp_v0_4 = func_004011B4();
        arg1->unk_C = temp_v0_4;
        if (temp_v0_4 == 0) {
            return -1;
        }
        B_10000DD4 = 0;
        goto block_188;
    }
    D_10000004 = -1;
    func_00400FA4(arg0, 0x270F);
    D_10000000 = 0;
    var_v1_3 = B_10000DD4;
    var_a2 = 0;
    sp460 = 0;
    if ((__ctype[var_v1_3].unk_1 & 7) || (var_v1_3 == 0x5F)) {
loop_71:
        (&sp460)[var_a2] = var_v1_3;
        var_a2 += 1;
        temp_a3 = &(&sp460)[var_a2];
        *temp_a3 = 0;
        temp_a0 = (u8) B_10000DD8->unk_0;
        if ((temp_a0 == 0) || ((temp_a0 == 0x5F) && (B_10000DD8->unk_1 == 0x5F) && (B_10000DD8->unk_2 != 0x5F))) {
            if (B_10000DDC > 0) {
                B_10000DD4 = temp_a0;
                B_10000DD8 += 1;
            } else {
                B_10000DD4 = 0;
            }
            B_10000DDC -= 1;
            goto block_91;
        }
        if (B_10000DDC > 0) {
            B_10000DD4 = temp_a0;
            B_10000DD8 += 1;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC -= 1;
        if (sp460 == *"__op") {
            sp45C = var_a2;
            sp30 = temp_a3;
            var_a2 = sp45C;
            if (strcmp((s8* ) &sp460, "__op") == 0) {
                temp_v1_2 = B_10000DD8 - 1;
                sp448 = (u8* ) temp_v1_2;
                temp_v0_5 = func_00401B48(-1, 0, 0, sp30);
                var_v1_4 = temp_v1_2;
                var_a3 = sp30;
                arg1->unk_8 = temp_v0_5;
                if (temp_v0_5 == 0) {
                    return -1;
                }
                temp_v0_6 = B_10000DD8 - 1;
                if ((u32) var_v1_4 < (u32) temp_v0_6) {
                    do {
                        temp_t6 = (u8) *var_v1_4;
                        var_v1_4 += 1;
                        var_a3 += 1;
                        var_a3->unk_-1 = temp_t6;
                    } while ((u32) var_v1_4 < (u32) temp_v0_6);
                }
                *var_a3 = 0;
                goto block_91;
            }
        }
        var_v1_3 = B_10000DD4;
        if (!((__ctype + var_v1_3)->unk_1 & 7) && (var_v1_3 != 0x5F)) {
            goto block_91;
        }
        goto loop_71;
    }
block_91:
    if (!(__ctype[sp460].unk_1 & 3) && (sp460 != 0x5F)) {
        return -1;
    }
    var_t8 = &__ctype[B_10000DD4];
    if (B_10000DD4 == 0x5F) {
        temp_a1_3 = (u8) B_10000DD8->unk_0;
        var_t8 = &__ctype[B_10000DD4];
        if (temp_a1_3 == 0x5F) {
            temp_t8_2 = B_10000DDC - 1;
            if (B_10000DDC > 0) {
                B_10000DD4 = temp_a1_3;
                B_10000DD8 += 1;
            } else {
                B_10000DD4 = 0;
            }
            B_10000DDC = temp_t8_2;
            if (temp_t8_2 > 0) {
                temp_t9 = (u8) B_10000DD8->unk_0;
                B_10000DD8 += 1;
                B_10000DD4 = temp_t9;
            } else {
                B_10000DD4 = 0;
            }
            B_10000DDC = temp_t8_2 - 1;
            if (B_10000DD4 == 0) {
                return -1;
            }
            var_t8 = &__ctype[B_10000DD4];
            goto block_105;
        }
    }
block_105:
    if ((var_t8->unk_1 & 4) || (B_10000DD4 == 0x51)) {
        temp_v0_7 = func_004011B4();
        arg1->unk_C = temp_v0_7;
        if (temp_v0_7 == 0) {
            return -1;
        }
        goto block_161;
    }
    if ((B_10000DD4 == 0x70) && (strncmp(B_10000DD8, "t__F", 4U) == 0)) {
        temp_t6_2 = B_10000DDC - 1;
        if (B_10000DDC > 0) {
            temp_t8_3 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t8_3;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC = temp_t6_2;
        if (temp_t6_2 > 0) {
            temp_t7 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t7;
        } else {
            B_10000DD4 = 0;
        }
        temp_t9_2 = temp_t6_2 - 1;
        B_10000DDC = temp_t9_2;
        if (temp_t9_2 > 0) {
            temp_t6_3 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t6_3;
        } else {
            B_10000DD4 = 0;
        }
        temp_t8_4 = temp_t9_2 - 1;
        B_10000DDC = temp_t8_4;
        if (temp_t8_4 > 0) {
            temp_t9_3 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t9_3;
        } else {
            B_10000DD4 = 0;
        }
        temp_t7_2 = temp_t8_4 - 1;
        B_10000DDC = temp_t7_2;
        if (temp_t7_2 > 0) {
            temp_t8_5 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t8_5;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC = temp_t7_2 - 1;
        if (!(__ctype[B_10000DD4].unk_1 & 4)) {
            return -1;
        }
        var_a1_2 = B_10000DD4 - 0x30;
        if (B_10000DDC > 0) {
            temp_t6_4 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t6_4;
        } else {
            B_10000DD4 = 0;
        }
        temp_t8_6 = B_10000DDC - 1;
        B_10000DDC = temp_t8_6;
        temp_t6_5 = __ctype[B_10000DD4].unk_1 & 4;
        var_v0_4 = temp_t6_5;
        if (temp_t6_5 != 0) {
            var_a1_2 = ((var_a1_2 * 0xA) + B_10000DD4) - 0x30;
            if (temp_t8_6 > 0) {
                temp_t8_7 = (u8) B_10000DD8->unk_0;
                B_10000DD8 += 1;
                B_10000DD4 = temp_t8_7;
            } else {
                B_10000DD4 = 0;
            }
            B_10000DDC = temp_t8_6 - 1;
            var_v0_4 = __ctype[B_10000DD4].unk_1 & 4;
        }
        if (var_v0_4 != 0) {
            var_a1_2 = ((var_a1_2 * 0xA) + B_10000DD4) - 0x30;
            if (B_10000DDC > 0) {
                temp_t6_6 = (u8) B_10000DD8->unk_0;
                B_10000DD8 += 1;
                B_10000DD4 = temp_t6_6;
            } else {
                B_10000DD4 = 0;
            }
            B_10000DDC -= 1;
        }
        if (var_a1_2 <= 0) {
            return -1;
        }
        var_a1_3 = var_a1_2 - 1;
        if (var_a1_2 > 0) {
loop_144:
            if (!(__ctype[B_10000DD4].unk_1 & 7) && (B_10000DD4 != 0x5F)) {
                return -1;
            }
            if (B_10000DDC > 0) {
                temp_t8_8 = (u8) B_10000DD8->unk_0;
                B_10000DD8 += 1;
                B_10000DD4 = temp_t8_8;
            } else {
                B_10000DD4 = 0;
            }
            temp_v0_8 = var_a1_3 > 0;
            var_a1_3 -= 1;
            B_10000DDC -= 1;
            if (temp_v0_8 == 0) {
                goto block_151;
            }
            goto loop_144;
        }
block_151:
        if ((B_10000DD4 != 0x5F) || (temp_a1_4 = (u8) B_10000DD8->unk_0, (temp_a1_4 != 0x5F))) {
            return -1;
        }
        temp_t9_4 = B_10000DDC - 1;
        if (B_10000DDC > 0) {
            B_10000DD4 = temp_a1_4;
            B_10000DD8 += 1;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC = temp_t9_4;
        if (temp_t9_4 > 0) {
            temp_t6_7 = (u8) B_10000DD8->unk_0;
            B_10000DD8 += 1;
            B_10000DD4 = temp_t6_7;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC = temp_t9_4 - 1;
        goto block_161;
    }
block_161:
    if ((sp460 == *"__vtbl") && (strcmp((s8* ) &sp460, "__vtbl") == 0)) {
        if ((B_10000DD4 == 0x5F) && ((u8) B_10000DD8->unk_0 == 0x5F) && (B_10000DD8->unk_1 != 0)) {
            arg1->unk_4 = func_00400EF8(B_10000DD8 + 1);
        }
        goto block_181;
    }
    temp_v1_3 = B_10000DD4;
    if (((temp_v1_3 == 0x43) || (temp_v1_3 == 0x53)) && (*B_10000DD8 == 0x46)) {
        arg1->unk_1A = temp_v1_3;
        temp_t0 = B_10000DDC;
        if (temp_t0 > 0) {
            temp_v0_9 = B_10000DD8;
            B_10000DD8 = temp_v0_9 + 1;
            B_10000DD4 = *temp_v0_9;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC = temp_t0 - 1;
    }
    if (B_10000DD4 == 0x46) {
        temp_t0_2 = B_10000DDC;
        if (temp_t0_2 > 0) {
            temp_v0_10 = B_10000DD8;
            B_10000DD8 = temp_v0_10 + 1;
            B_10000DD4 = *temp_v0_10;
        } else {
            B_10000DD4 = 0;
        }
        B_10000DDC = temp_t0_2 - 1;
        temp_v0_11 = func_00402D50();
        arg1->unk_10 = temp_v0_11;
        if (temp_v0_11 == 0) {
            return -1;
        }
        goto block_180;
    }
block_180:
block_181:
    if (((B_10000DD4 != 0) && ((sp460 != *"__vtbl") || (strcmp((s8* ) &sp460, "__vtbl") != 0))) || (D_10000000 != 0)) {
        return -1;
    }
    var_v0_2 = func_00400EF8((s8* ) &sp460);
block_187:
    arg1->unk_0 = var_v0_2;
block_188:
    temp_v0_12 = arg1->unk_1A;
    var_v1_5 = 0;
    switch (temp_v0_12) {                           /* irregular */
        case 0x69:
            var_v1_5 = 1;
            break;
        case 0x64:
            var_v1_5 = 2;
            break;
        case 0x62:
            var_v1_5 = 4;
            break;
        case 0x43:
            var_v1_5 = 8;
            break;
        case 0x53:
            var_v1_5 = 7;
            break;
        default:
            sp3C = 0;
            func_00400DE4("bad type set for p->sc", 0, 0, arg1);
            var_v1_5 = 0;
            break;
        case 0x0:
            if (arg1->unk_18 != -1) {
                var_v1_5 = 0xE;
            } else if (arg1->unk_10 != 0) {
                if (arg1->unk_8 != 0) {
                    var_v1_5 = 9;
                } else if (arg1->unk_C != NULL) {
                    temp_v0_13 = arg1->unk_0;
                    if ((temp_v0_13->unk_0 == 0x5F) && (temp_v0_13->unk_1 == 0x5F)) {
                        temp_v1_4 = temp_v0_13->unk_2;
                        if ((temp_v1_4 == 0x63) && (temp_v0_13->unk_3 == 0x74) && (temp_v0_13->unk_4 == 0)) {
                            var_v1_5 = 0xA;
                        } else if ((temp_v1_4 == 0x64) && (temp_v0_13->unk_3 == 0x74) && (temp_v0_13->unk_4 == 0)) {
                            var_v1_5 = 0xB;
                        } else {
                            var_v1_5 = 6;
                        }
                    } else {
                        var_v1_5 = 6;
                    }
                } else {
                    var_v1_5 = 5;
                }
            } else {
                temp_a0_2 = arg1->unk_0;
                if ((temp_a0_2 == NULL) && (temp_v0_14 = arg1->unk_C, (temp_v0_14 != NULL))) {
                    if (temp_v0_14->unk_4 != 0) {
                        var_v1_5 = 0x10;
                    } else {
                        var_v1_5 = 0xF;
                    }
                } else if (temp_a0_2 != NULL) {
                    var_v1_5 = 0xC;
                    if (arg1->unk_C != NULL) {
                        if ((temp_a0_2->unk_0 == 0x5F) && (temp_a0_2->unk_1 == 0x5F) && (temp_a0_2->unk_2 == 0x76) && (temp_a0_2->unk_3 == 0x74) && (temp_a0_2->unk_4 == 0x62) && (temp_a0_2->unk_5 == 0x6C) && (temp_a0_2->unk_6 == 0)) {
                            var_v1_5 = 3;
                        } else {
                            var_v1_5 = 0xD;
                        }
                    }
                }
            }
            break;
    }
    if (var_v1_5 == 0) {
        sp3C = var_v1_5;
        func_00400DE4("cannot characterize type of input", 0, 0, arg1);
    }
    arg1->unk_14 = var_v1_5;
    return 0;
}
#else
int dem(char*, struct_demangle_sp24*, char*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem.s")
#endif

void dem_printcl(char**, char*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printcl.s")

void dem_printarglist(UNK_TYPE, char*, int);
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

void dem_printfunc(struct_demangle_sp24*, char*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printfunc.s")

#ifdef NON_MATCHING
// stack issues
int dem_print(struct_demangle_sp24* arg0, char* arg1) {
    if ((arg0 == NULL) || (arg1 == NULL)) {
        return -1;
    }

    *arg1 = 0;
    if ((arg0->unk_0 == NULL) && (arg0->unk_C != 0)) {
        dem_printcl(arg0->unk_C, arg1);
    } else {
        if ((arg0->unk_1A == 0x69) || (arg0->unk_1A == 0x64)) {
            sprintf(arg1, "%s:__st%c", arg0->unk_0, arg0->unk_1A);
        } else if (arg0->unk_1A == 0x62) {
            sprintf(arg1, "%s:__ptbl_vec", arg0->unk_0);
        } else {
            int var_v1;
            char sp30[0x400];
            char* var_a2;

            if (arg0->unk_C != 0) {
                dem_printcl(arg0->unk_C, sp30);
                strcat(arg1, sp30);
                strcat(arg1, "::");
            }

            var_a2 = &sp30[strlen(sp30)-1];
            var_v1 = 0;
            for (; var_a2 >= sp30; var_a2--) {
                if (*var_a2 == '>') {
                    var_v1 += 1;
                } else if (*var_a2 == '<') {
                    var_v1 -= 1;
                } else if (*var_a2 == ':') {
                    if (var_v1 == 0) {
                        break;
                    }
                }
            }

            if ((arg0->unk_0[0] == *"__ct") && ((strcmp(arg0->unk_0, "__ct") == 0))) {
                strcat(arg1, &var_a2[1]);
            } else if ((arg0->unk_0[0] == *"__dt") && (strcmp(arg0->unk_0, "__dt") == 0)) {
                strcat(arg1, "~");
                strcat(arg1, &var_a2[1]);
            } else {
                dem_printfunc(arg0, sp30);
                strcat(arg1, sp30);
            }

            if (arg0->unk_10 != 0) {
                strcat(arg1, "(");
                dem_printarglist(arg0->unk_10, sp30, 0);
                strcat(arg1, sp30);
                strcat(arg1, ")");
            }

            if (arg0->unk_1A == 0x43) {
                strcat(arg1, " const");
            }
        }
    }

    return 0;
}
#else
int dem_print(struct_demangle_sp24*, char*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_print.s")
#endif

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_explain.s")

int demangle(char* arg0, char* dst) {
    char sp40[0x1000];
    struct_demangle_sp24 sp24;

    if ((arg0 == NULL) || (*arg0 == '\0') || (dst == NULL)) {
        return -1;
    }

    if (dem(arg0, &sp24, sp40) < 0) {
        strcpy(dst, arg0);
        return -1;
    }

    dem_print(&sp24, dst);
    return 0;
}

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

