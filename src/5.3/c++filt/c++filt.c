#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "inttypes.h"
#include "ctype.h"

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

#define STATIC static

// #define NON_EQUIVALENT
#ifndef putchar_locked
#define putchar_locked(x) putchar(x)
#endif

typedef enum enum_dem_explain_arg0 {
    /*  1 */ ENUM_DEM_EXPLAIN_ARG_1 = 1,
    /*  2 */ ENUM_DEM_EXPLAIN_ARG_2,
    /*  3 */ ENUM_DEM_EXPLAIN_ARG_3,
    /*  4 */ ENUM_DEM_EXPLAIN_ARG_4,
    /*  5 */ ENUM_DEM_EXPLAIN_ARG_5,
    /*  6 */ ENUM_DEM_EXPLAIN_ARG_6,
    /*  7 */ ENUM_DEM_EXPLAIN_ARG_7,
    /*  8 */ ENUM_DEM_EXPLAIN_ARG_8,
    /*  9 */ ENUM_DEM_EXPLAIN_ARG_9,
    /* 10 */ ENUM_DEM_EXPLAIN_ARG_10,
    /* 11 */ ENUM_DEM_EXPLAIN_ARG_11,
    /* 12 */ ENUM_DEM_EXPLAIN_ARG_12,
    /* 13 */ ENUM_DEM_EXPLAIN_ARG_13,
    /* 14 */ ENUM_DEM_EXPLAIN_ARG_14,
    /* 15 */ ENUM_DEM_EXPLAIN_ARG_15,
    /* 16 */ ENUM_DEM_EXPLAIN_ARG_16
} enum_dem_explain_arg0;

struct struct_dem_printcl_arg0;

typedef struct struct_dem_printarglist_arg0 {
    /* 0x00 */ char* unk_00;
    /* 0x04 */ long* unk_04;                         /* inferred */
    /* 0x08 */ struct struct_dem_printarglist_arg0* unk_08; /* inferred */
    /* 0x0C */ struct struct_dem_printarglist_arg0* unk_0C; /* inferred */
    /* 0x10 */ struct struct_dem_printcl_arg0* unk_10;     /* inferred */
    /* 0x14 */ struct struct_dem_printcl_arg0** unk_14;                        /* inferred */
    /* 0x18 */ struct struct_dem_printarglist_arg0* unk_18;
    /* 0x1C */ char* unk_1C;
    /* 0x20 */ char unk_20;
} struct_dem_printarglist_arg0; // size = 0x24

typedef struct struct_dem_printcl_arg0 {
    /* 0x0 */ char *unk_00;
    /* 0x4 */ struct_dem_printarglist_arg0 *unk_04;
    /* 0x8 */ char *unk_08;
    /* 0xC */ struct struct_dem_printcl_arg0 *unk_0C;
} struct_dem_printcl_arg0; // size >= 0x10

typedef struct struct_demangle_sp24 {
    /* 0x00 */ char* unk_00;
    /* 0x04 */ char* unk_04;                           /* inferred */
    /* 0x08 */ struct_dem_printarglist_arg0* unk_08;  /* inferred */
    /* 0x0C */ struct_dem_printcl_arg0* unk_0C;
    /* 0x10 */ struct_dem_printarglist_arg0* unk_10;
    /* 0x14 */ int unk_14;
    /* 0x18 */ short unk_18;
    /* 0x1A */ char unk_1A;
} struct_demangle_sp24;                             /* size = 0x1C */


STATIC int D_10000000 = 0;
STATIC int D_10000004 = -1;

#define STACK_BUF_LEN 10

STATIC char* B_10000DD0;
STATIC char B_10000DD4;
STATIC char* B_10000DD8;
STATIC int B_10000DDC;
STATIC char* B_10000DE0[STACK_BUF_LEN];
STATIC int B_10000E08[STACK_BUF_LEN];
STATIC char B_10000E30[STACK_BUF_LEN];
STATIC struct_dem_printarglist_arg0* B_10000E3C;

#define ADV() if (B_10000DDC > 0) { \
            B_10000DD4 = *B_10000DD8++; \
        } else { \
            B_10000DD4 = '\0'; \
        } \
        B_10000DDC--


void dem_printarg(struct_dem_printarglist_arg0* arg0, char *arg1, int arg2);
void dem_printarglist(struct_dem_printarglist_arg0* arg0, char* arg1, int arg2);

STATIC struct_dem_printarglist_arg0 *func_00402D50(void);
void dem_printcl(struct_dem_printcl_arg0* arg0, char* arg1);


STATIC void func_00400DE4(const char* arg0, const char *arg1, const char *arg2) {
    char sp20[0x400];

    sprintf(sp20, arg0, arg1, arg2);
    fprintf(stderr, "demangle fatal error: %s\n", sp20);
    exit(1);
}

STATIC void* func_00400E64(int size) {
    char* var_v1;

    if (size <= 0) {
        func_00400DE4("bad argument to gs()", NULL, NULL);
    }


    while (((uintptr_t)B_10000DD0 % 4) ) {
        B_10000DD0++;
    }

    var_v1 = B_10000DD0;
    B_10000DD0 = var_v1 + size;
    return var_v1;
}

STATIC char* func_00400EF8(char* arg0) {
    char* temp_v0;

    if ((arg0 == NULL) || (arg0[0] == '\0')) {
        func_00400DE4("bad argument to copy()", NULL, NULL);
    }
    temp_v0 = func_00400E64(strlen(arg0) + 1);
    strcpy(temp_v0, arg0);
    return temp_v0;
}

STATIC void func_00400FA4(char* arg0, int arg1) {
    int var_a0;

    if ((arg0 == NULL) || (*arg0 == 0) || (arg1 <= 0)) {
        func_00400DE4("bad argument to push()", NULL, NULL);
    }

    if (D_10000004 + 1 >= STACK_BUF_LEN) {
        func_00400DE4("overflow of stack in push()", NULL, NULL);
    }

    D_10000004++;
    B_10000DE0[D_10000004] = B_10000DD8;
    B_10000E08[D_10000004] = B_10000DDC;
    B_10000E30[D_10000004] = B_10000DD4;
    B_10000DD8 = arg0;
    B_10000DDC = arg1;
    ADV();
}

STATIC void func_004010F8(void) {
    if (D_10000004 < 0) {
        func_00400DE4("bad argument to pop()", NULL, NULL);
    }

    B_10000DD8 = B_10000DE0[D_10000004];
    B_10000DDC = B_10000E08[D_10000004];
    B_10000DD4 = B_10000E30[D_10000004];
    D_10000004--;
}

#ifdef NON_EQUIVALENT
//#if 1
// STATIC
struct_dem_printcl_arg0* func_004011B4(void) {
    char* var_v1_2;
    int var_a3;
    int var_s0;
    char sp74[0x400];
    int var_a2;
    int var_s0_2;
    int sp68;
    struct_dem_printcl_arg0* temp_s5;
    struct_dem_printcl_arg0* sp60;
    struct_dem_printcl_arg0* sp5C;
    struct_dem_printarglist_arg0* temp_v0;

    sp60 = NULL;
    sp5C = NULL;

    sp68 = 1;
    var_a2 = 0;

    if (isdigit(B_10000DD8[0])) {
        var_a2 = 1;
        if (isdigit(B_10000DD8[1])) {
            var_a2 = 2;
        }
    }

    if ((isdigit(B_10000DD4)) && (B_10000DD8[var_a2] == 'Q') && (isdigit(B_10000DD8[var_a2+1])) && (B_10000DD8[var_a2+2] == '_')) {
        ADV();

        if (var_a2 != 0) {
            ADV();
        }

        if (var_a2 == 2) {
            ADV();
        }

        if (0) {}
    }

    if (B_10000DD4 == 'Q') {
        ADV();

        if (!isdigit(B_10000DD4)) {
            D_10000000 = 1;
            return NULL;
        }

        sp68 = B_10000DD4 - '0';

        if (sp68 <= 0) {
            D_10000000 = 1;
            return NULL;
        }

        ADV();

        if (B_10000DD4 != '_') {
            D_10000000 = 1;
            return NULL;
        }

        ADV();
    }

    while (sp68-- > 0) {
        if (!isdigit(B_10000DD4)) {
            D_10000000 = 1;
            return NULL;
        }

        var_a3 = B_10000DD4 - '0';
        ADV();

        if (isdigit(B_10000DD4)) {
            var_a3 = (var_a3 * 10) + (B_10000DD4 - '0');
            ADV();
        }

        if (isdigit(B_10000DD4)) {
            var_a3 = (var_a3 * 10) + (B_10000DD4 - '0');
            ADV();
        }

        if (var_a3 <= 0) {
            D_10000000 = 1;
            return NULL;
        }

        for (var_a2 = 0; var_a2 < var_a3; var_a2++) {
            if (!isalnum(B_10000DD4) && (B_10000DD4 != '_')) {
                D_10000000 = 1;
                return NULL;
            }

            sp74[var_a2] = B_10000DD4;
            ADV();
        }

        sp74[var_a2] = 0;
        temp_s5 = func_00400E64(0x10);
        temp_s5->unk_08 = func_00400EF8(sp74);
        temp_s5->unk_04 = NULL;

        for (var_s0 = 0; var_s0 < var_a2; var_s0++) {
            if ((sp74[var_s0] == '_') && (sp74[var_s0+1] == '_') && (sp74[var_s0+2] == 'p') && (sp74[var_s0+3] == 't')) {
                break;
            }
        }

        if (var_s0 == 0) {
            D_10000000 = 1;
            return NULL;
        }

        if (var_s0 == var_a2) {
            temp_s5->unk_00 = func_00400EF8(sp74);
        } else {
            if ((sp74[var_s0+4] != '_') || (sp74[var_s0+5] != '_')) {
                D_10000000 = 1;
                return NULL;
            }
            sp74[var_s0] = 0;
            temp_s5->unk_00 = func_00400EF8(sp74);

            var_s0 += 6;

            var_a3 = sp74[var_s0] - '0';
            if (!(isdigit(sp74[var_s0]))) {
                D_10000000 = 1;
                return NULL;
            }

            var_v1_2 = &sp74[var_s0];

            var_s0++;
            var_v1_2++;
            var_s0_2 = var_s0;

            if (isdigit(*var_v1_2)) {
                var_a3 = (var_a3 * 10) + (*var_v1_2 - '0');
                var_s0_2++;
                var_v1_2++;
            }

            if (isdigit(*var_v1_2)) {
                var_a3 = (var_a3 * 10) + (*var_v1_2 - '0');
                var_s0_2++;
                var_v1_2++;
            }

            if (var_a3 < 2) {
                D_10000000 = 1;
                return NULL;
            }

            if (*var_v1_2 != '_') {
                D_10000000 = 1;
                return NULL;
            }

            var_s0_2++;
            var_v1_2++;

            var_a3--;

            if (*var_v1_2 == 0) {
                D_10000000 = 1;
                return NULL;
            }

            func_00400FA4(&sp74[var_s0_2], var_a3);
            temp_v0 = func_00402D50();
            if ((temp_v0 == NULL) || (B_10000DD4 != 0)) {
                D_10000000 = 1;
                return NULL;
            }
            func_004010F8();
            temp_s5->unk_04 = temp_v0;
        }

        temp_s5->unk_0C = NULL;
        if (sp60 != NULL) {
            sp5C->unk_0C = temp_s5;
            sp5C = temp_s5;
        } else {
            sp60 = temp_s5;
            sp5C = temp_s5;
        }
    }

    return sp60;
}

#else
struct_dem_printcl_arg0* func_004011B4(void);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_004011B4.s")
#endif

STATIC struct_dem_printarglist_arg0* func_00401A70(struct_dem_printarglist_arg0* arg0) {
    struct_dem_printarglist_arg0* temp_v0;

    if (arg0 == NULL) {
        func_00400DE4("bad argument to arg_copy()", NULL, NULL);
    }
    temp_v0 = func_00400E64(sizeof(struct_dem_printarglist_arg0));
    temp_v0->unk_00 = arg0->unk_00;
    temp_v0->unk_20 = arg0->unk_20;
    temp_v0->unk_04 = arg0->unk_04;
    temp_v0->unk_08 = arg0->unk_08;
    temp_v0->unk_10 = arg0->unk_10;
    temp_v0->unk_14 = arg0->unk_14;
    temp_v0->unk_1C = arg0->unk_1C;
    temp_v0->unk_0C = arg0->unk_0C;
    temp_v0->unk_18 = 0;
    return temp_v0;
}

#ifdef NON_EQUIVALENT
struct_dem_printarglist_arg0* func_00401B48(int arg0, struct_dem_printarglist_arg0* arg1[], int* arg2) {
    char spFA4[0x100]; // arbitrary
    int var_t5; // spFA0
    int spF9C;
    struct_dem_printcl_arg0* spF98;
    struct_dem_printarglist_arg0* spF90;
    struct_dem_printarglist_arg0* spF8C;
    char spB8C[0x400];
    int var_ra; // spB88
    int spB84;
    UNK_TYPE sp9F4[100];
    int sp9F0;
    int var_a1_4; // sp9EC
    int sp9E8;
    int sp9E4;
    char sp5E4[0x400];
    char sp1E4[0x400];
    struct_dem_printcl_arg0 *sp54[100];
    int sp50;
    int sp4C;
    int temp_a1;
    int var_a0_2;
    int var_a1;
    int var_a1_5;
    int var_v0_2;
    char* temp_a2;
    struct_dem_printarglist_arg0* temp_v0;
    struct_dem_printarglist_arg0* var_a0;
    struct_dem_printcl_arg0* temp_v0_4;
    struct_dem_printcl_arg0* temp_v0_8;

    if (arg2 != NULL) {
        if (*arg2 > 0) {
            *arg2 = *arg2 - 1;
            return func_00401A70(B_10000E3C);
        }
    }

    var_t5 = 0;
    spF9C = 0;
    spF98 = NULL;
    spF90 = NULL;
    spF8C = NULL;
    var_ra = 0;
    spB84 = 0;
    sp9F0 = 0;
    sp9E8 = 0;
    sp50 = 0;

    while (1) {
        switch (B_10000DD4) {
            case 0x58:
                spB84 = 1;
                ADV();
                break;

            case 0x43:
            case 0x50:
            case 0x52:
            case 0x53:
            case 0x55:
            case 0x56:
                spFA4[var_t5] = B_10000DD4;
                var_t5 += 1;
                ADV();
                break;

            case 0x4C:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
            case 0x69:
            case 0x6C:
            case 0x72:
            case 0x73:
            case 0x76:
                spF9C = B_10000DD4;
                ADV();
                break;

            case 0x41:
                spFA4[var_t5] = B_10000DD4;
                var_t5 += 1;
                ADV();
                if (!(isdigit(B_10000DD4))) {
                    D_10000000 = 1;
                    return NULL;
                }

                var_a1_5 = B_10000DD4 - 0x30;
                ADV();
                while (isdigit(B_10000DD4)) {
                    var_a1_5 = ((var_a1_5 * 0xA) + B_10000DD4) - 0x30;
                    ADV();
                }

                if (B_10000DD4 != 0x5F) {
                    D_10000000 = 1;
                    return NULL;
                }
                ADV();
                sp9F4[sp9F0] = var_a1_5;
                sp9F0 += 1;
                break;

            case 0x46:
                spF9C = B_10000DD4;
                ADV();
                spF90 = func_00402D50();
                if (spF90 == NULL) {
                    D_10000000 = 1;
                    return NULL;
                }
                if (B_10000DD4 != 0x5F) {
                    D_10000000 = 1;
                    return NULL;
                }
                ADV();
                spF8C = func_00401B48(-1, NULL, NULL);
                if (spF8C == NULL) {
                    D_10000000 = 1;
                    return NULL;
                }
                break;

            case 0x4D:
                spFA4[var_t5] = B_10000DD4;
                var_t5++;
                sp9E8 = 1;
                ADV();
                temp_v0_8 = func_004011B4();
                sp54[sp50] = temp_v0_8;
                sp50 += 1;
                if (temp_v0_8 == NULL) {
                    D_10000000 = 1;
                    return NULL;
                }
                break;

            case 0x54:
                ADV();
    block_60:
                if (!(isdigit(B_10000DD4))) {
                    D_10000000 = 1;
                    return NULL;
                }
                temp_a1 = B_10000DD4 - 0x30;
                ADV();
                if (temp_a1 <= 0) {
                    D_10000000 = 1;
                    return NULL;
                }
                if ((arg1 == NULL) || (arg0 < (temp_a1 - 1))) {
                    D_10000000 = 1;
                    return NULL;
                }

                temp_v0 = func_00401A70(arg1[temp_a1-1]);
                B_10000E3C = temp_v0;
                return temp_v0;

            case 0x4E:
                ADV();
                if (!isdigit(B_10000DD4)) {
                    D_10000000 = 1;
                    return NULL;
                }
                if (arg2 == NULL) {
                    D_10000000 = 1;
                    return NULL;
                }
                *arg2 = B_10000DD4 - 0x31;
                if (*arg2 < 0) {
                    D_10000000 = 1;
                    return NULL;
                }
                ADV();
                goto block_60;

            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x38:
            case 0x39:
            case 0x51:
                spF98 = func_004011B4();
                if (spF98 == NULL) {
                    D_10000000 = 1;
                    return NULL;
                }
                spF9C = 0x43;
                break;

            default:
                return NULL;
        }

        if (spF9C != 0) {
            if ((spF9C != 0) && (spB84 != 0)) {
                sp9E4 = 0;
                if (B_10000DD4 == 0x4C) {
                    if (*B_10000DD8 == 0x4D) {
                        ADV();
                        ADV();

                        while ((B_10000DD4 != 0x5F) && (B_10000DD4 != 0)) {
                            ADV();
                        }
                        if (B_10000DD4 == 0) {
                            D_10000000 = 1;
                            return NULL;
                        }
                        ADV();

                        while ((B_10000DD4 != 0x5F) && (B_10000DD4 != 0)) {
                            ADV();
                        }

                        if (B_10000DD4 == 0) {
                            D_10000000 = 1;
                            return NULL;
                        }
                        ADV();
                        var_a1 = B_10000DD4 - 0x30;
                        ADV();
                        if (isdigit(B_10000DD4)) {
                            var_a1 = ((var_a1 * 0xA) + B_10000DD4) - 0x30;
                            ADV();
                        }
                        if (isdigit(B_10000DD4)) {
                            var_a1 = ((var_a1 * 0xA) + B_10000DD4) - 0x30;
                            ADV();
                        }
                        sp9E4 = 1;
                        goto block_172;
                    }
                }

                if (B_10000DD4 == 0x4C) {
                    ADV();
                    if (!isdigit(B_10000DD4)) {
                        D_10000000 = 1;
                        return NULL;
                    }

                    var_a1 = B_10000DD4 - 0x30;
                    ADV();
                    if (isdigit(B_10000DD4)) {
                        if (*B_10000DD8 == 0x5F) {
                            var_a1 = ((var_a1 * 0xA) + B_10000DD4) - 0x30;
                            ADV();
                            ADV();
                        }
                    }
                    if (B_10000DD4 == 0x6E) {
                        var_a1 -= 1;
                        ADV();
                        spB8C[0] = 0x2D;
                        var_ra = 1;
                    }
                    goto block_172;
                }
                if (B_10000DD4 == 0x30) {
                    var_a1 = 1;
                    goto block_172;
                }

                if (isdigit(B_10000DD4)) {
                    var_a1 = B_10000DD4 - 0x30;
                    ADV();
                    if (isdigit(B_10000DD4)) {
                        var_a1 = ((var_a1 * 0xA) + B_10000DD4) - 0x30;
                        ADV();
                    }
block_172:
                    var_a0_2 = -1;
                    if (var_a1 <= 0) {
                        D_10000000 = 1;
                        return NULL;
                    }

                    while (var_a1--) {
                        if (!(isalnum(B_10000DD4)) && (B_10000DD4 != 0x5F)) {
                            D_10000000 = 1;
                            return NULL;
                        }
                        temp_a2 = &spB8C[var_ra];
                        temp_a2[1-1] = B_10000DD4;
                        var_ra += 1;
                        ADV();
                        if ((var_a1 > 0) && (var_ra >= 2) && (temp_a2[-1] == 0x5F) && (temp_a2[-2] == 0x5F)) {
                            sp4C = sp50;
                            temp_v0_4 = func_004011B4();
                            var_a0_2 = sp4C;
                            sp54[sp50] = temp_v0_4;
                            var_ra -= 2;
                            sp50 += 1;
                            if (temp_v0_4 == NULL) {
                                D_10000000 = 1;
                                return NULL;
                            }
                            temp_a2[-1] = 0;
                            temp_a2[-2] = 0;
                            break;
                        }
                    }

                    spB8C[var_ra] = 0;
                    if (((sp9E8 != 0) && (sp9E4 != 0)) || (var_a0_2 >= 0)) {
                        dem_printcl(sp54[(var_a0_2 >= 0) ? var_a0_2 : 0], sp1E4);
                        sprintf(sp5E4, "%s::%s", sp1E4, spB8C);
                        strcpy(spB8C, sp5E4);
                        var_ra = strlen(spB8C);
                    }
                } else {
                    D_10000000 = 1;
                    return NULL;
                }
            }

            spFA4[var_t5] = 0;
            spB8C[var_ra] = 0;
            var_a0 = func_00400E64(0x24);

            if (&spFA4[var_t5] != spFA4) {
                B_10000E3C = var_a0;
                var_a0->unk_00 = func_00400EF8(spFA4);
            } else {
                var_a0->unk_00 = 0;
            }
            if (&spB8C[var_ra] != spB8C) {
                B_10000E3C = var_a0;
                var_a0->unk_1C = func_00400EF8(spB8C);
            } else {
                var_a0->unk_1C = NULL;
            }
            if (sp9F0 > 0) {
                B_10000E3C = var_a0;
                var_a0->unk_04 = func_00400E64(sp9F0 * 4);

                for (var_v0_2 = 0; var_v0_2 < sp9F0; var_v0_2++) {
                    var_a0->unk_04[var_v0_2] = sp9F4[var_v0_2];
                }
            } else {
                var_a0->unk_04 = NULL;
            }

            var_a0->unk_20 = spF9C;
            var_a0->unk_08 = spF90;
            var_a0->unk_0C = spF8C;
            var_a0->unk_10 = spF98;
            if (sp50 > 0) {
                B_10000E3C = var_a0;
                var_a0->unk_14 = func_00400E64((sp50 + 1) * 4);

                for (var_a1_4 = 0; var_a1_4 < sp50; var_a1_4++) {
                    var_a0->unk_14[var_a1_4] = sp54[var_a1_4];
                }

                var_a0->unk_14[sp50] = NULL;
            } else {
                var_a0->unk_14 = NULL;
            }

            var_a0->unk_18 = NULL;
            B_10000E3C = var_a0;
            return var_a0;
        }
    }
}
#else
struct_dem_printarglist_arg0* func_00401B48(int arg0, struct_dem_printarglist_arg0* arg1[], int *arg2);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00401B48.s")
#endif

STATIC struct_dem_printarglist_arg0* func_00402D50(void) {
    struct_dem_printarglist_arg0* var_s3 = NULL; // head
    struct_dem_printarglist_arg0* var_s0 = NULL;
    int var_s1 = -1;
    struct_dem_printarglist_arg0 *sp3C[100];
    struct_dem_printarglist_arg0* temp_v0;
    int sp34 = 0;

    while (1) {
        temp_v0 = func_00401B48(var_s1, sp3C, &sp34);
        if (temp_v0 == NULL) {
            if (D_10000000 != 0) {
                return NULL;
            }
            return var_s3;
        }

        sp3C[++var_s1] = temp_v0;

        if (var_s0 == NULL) {
            var_s3 = temp_v0;
            var_s0 = temp_v0;
        } else {
            var_s0->unk_18 = temp_v0;
            var_s0 = temp_v0;
        }
    }
}

#define STR_EQUAL(a, b) ((*(a) == *(b)) && (strcmp((a), (b)) == 0))
#define STR_EQUAL_N(a, b) (strncmp((a), (b), sizeof((b)) - 1) == 0)

#ifdef NON_EQUIVALENT
//#if 1
int dem(char* arg0, struct_demangle_sp24* arg1, char* arg2) {
    // spXXX means that variable must belong in that stack position
    // spXXX? means I have no clue if the variable is real or its stack position
    char sp460[0x400];
    int var_a2; // sp45C
    unsigned int var_a1; // sp458
    int var_a1_2; // sp454 ?
    int var_v1_2; // sp450 ?
    char* var_a0; // sp44C ?
    char* temp_v1_2; // sp448
    char* var_a0_2; // sp444 ?
    char* var_a0_3; // sp440 ?
    char sp40[0x400];
    int var_v1_5; // sp3C
    char* var_v1; // sp38?
    int var_v0; // sp34?
    char* var_a3; //sp30

    char* temp_v0_6;

    if ((arg0 == NULL) || (arg1 == NULL) || (arg2 == NULL)) {
        return -1;
    }

    if (arg0[0] == 0) {
        return -1;
    }

    B_10000DD0 = arg2;
    D_10000004 = -1;
    D_10000000 = 0;
    arg1->unk_08 = NULL;
    arg1->unk_0C = NULL;
    arg1->unk_1A = 0;
    arg1->unk_10 = NULL;
    arg1->unk_00 = NULL;
    arg1->unk_04 = NULL;
    arg1->unk_18 = -1;
    arg1->unk_14 = 0;

    if ((arg0[0] == 0x5F) && (arg0[1] == 0x5F)) {
        var_a0 = arg0 + 2;
        var_v0 = arg0[2];
        if (isdigit(var_v0)) {
            var_a1 = 0;
            while (isdigit(var_v0)) {
                var_a0 += 1;
                var_a1 = var_v0 + (var_a1 * 0xA) - 0x30;
                var_v0 = *var_a0;
            }

            if (*var_a0 != 0) {
                arg1->unk_00 = func_00400EF8(var_a0);
                arg1->unk_18 = var_a1;
                goto block_187;
            }
        }
    }

    if ((arg0[0] == 0x5F) && (arg0[1] == 0x5F) && (STR_EQUAL_N(arg0, "__sti__") || STR_EQUAL_N(arg0, "__std__") || STR_EQUAL_N(arg0, "__ptbl_vec__"))) {
        arg1->unk_1A = arg0[4];
        var_a0_2 = (arg0[2] == 0x73) ? arg0 + 7 : arg0 + 0xC;

        while (*var_a0_2 == 0x5F) {
            var_a0_2 += 1;
        }

        var_v1 = var_a0_2;
        while ((var_v1[0] != 0) && ((var_v1[0] != 0x5F) || (var_v1[1] != 0x63) || (var_v1[2] != 0x5F))) {
            var_v1 += 1;
        }
        *var_v1 = 0;

        if (var_a0_2[0] == 0) {
            return -1;
        }
        arg1->unk_00 = func_00400EF8(var_a0_2);
        B_10000DD4 = 0;
    } else {
        var_a0_3 = arg0;
        var_v1_2 = 0;
        while ((var_a0_3[0] != 0) && ((var_a0_3[0] != 0x5F) || (var_a0_3 == arg0) || (var_a0_3[-1] != 0x5F))) {
            var_a0_3 += 1;
        }

        if ((var_a0_3[0] == 0x5F) && (var_a0_3[1] == 0x70) && (var_a0_3[2] == 0x74) && (var_a0_3[3] == 0x5F) && (var_a0_3[4] == 0x5F)) {
            var_v1_2 = 1;
        }
        if ((var_a0_3[0] == 0x5F) && (var_a0_3[1] == 0x5F) && (var_a0_3[2] == 0x70) && (var_a0_3[3] == 0x74) && (var_a0_3[4] == 0x5F) && (var_a0_3[5] == 0x5F)) {
            var_v1_2 = 1;
        }
        if ((var_v1_2 == 0) && (arg0[0] == 0x5F) && (arg0[1] == 0x5F) && (arg0[2] == 0x51) && (isdigit(arg0[3])) && (arg0[4] == 0x5F)) {
            var_v1_2 = 2;
        }

        if (var_v1_2 != 0) {
            D_10000004 = -1;
            D_10000000 = 0;
            if (var_v1_2 == 1) {
                sprintf(sp40, "%d%s", strlen(arg0), arg0);
                func_00400FA4(sp40, 0x270F);
            } else {
                func_00400FA4(arg0 + 2, 0x270F);
            }
            arg1->unk_0C = func_004011B4();
            if (arg1->unk_0C == NULL) {
                return -1;
            }
            B_10000DD4 = 0;
        } else {
            D_10000004 = -1;
            func_00400FA4(arg0, 0x270F);
            D_10000000 = 0;
            var_a2 = 0;
            sp460[0] = 0;
            while (isalnum(B_10000DD4) || (B_10000DD4 == 0x5F)) {
                sp460[var_a2] = B_10000DD4;
                var_a2 += 1;
                var_a3 = &sp460[var_a2];
                *var_a3 = 0;
                if ((*B_10000DD8 == 0) || ((*B_10000DD8 == 0x5F) && (B_10000DD8[1] == 0x5F) && (B_10000DD8[2] != 0x5F))) {
                    ADV();

                    break;
                }
                ADV();

                if (STR_EQUAL(sp460, "__op")) {
                    temp_v1_2 = B_10000DD8 - 1;
                    arg1->unk_08 = func_00401B48(-1, NULL, NULL);
                    if (arg1->unk_08 == NULL) {
                        return -1;
                    }

                    temp_v0_6 = B_10000DD8 - 1;
                    while ((u32) temp_v1_2 < (u32) temp_v0_6) {
                        *var_a3++ = *temp_v1_2++;
                    }
                    *var_a3 = 0;
                    break;
                }

            }

            if (!isalpha(sp460[0]) && (sp460[0] != 0x5F)) {
                return -1;
            }

            if ((B_10000DD4 == 0x5F) && (*B_10000DD8 == 0x5F)) {
                ADV();
                ADV();

                if (B_10000DD4 == 0) {
                    return -1;
                }
            }

            if ((isdigit(B_10000DD4)) || (B_10000DD4 == 0x51)) {
                arg1->unk_0C = func_004011B4();
                if (arg1->unk_0C == NULL) {
                    return -1;
                }
            } else if ((B_10000DD4 == 0x70) && STR_EQUAL_N(B_10000DD8, "t__F")) {
                ADV();
                ADV();
                ADV();
                ADV();
                ADV();

                if (!isdigit(B_10000DD4)) {
                    return -1;
                }
                var_a1_2 = B_10000DD4 - 0x30;
                ADV();

                if (isdigit(B_10000DD4)) {
                    var_a1_2 = ((var_a1_2 * 0xA) + B_10000DD4) - 0x30;
                    ADV();
                }

                if (isdigit(B_10000DD4)) {
                    var_a1_2 = ((var_a1_2 * 0xA) + B_10000DD4) - 0x30;
                    ADV();
                }

                if (var_a1_2 <= 0) {
                    return -1;
                }

                while (var_a1_2--) {
                    if (!(isalnum(B_10000DD4)) && (B_10000DD4 != 0x5F)) {
                        return -1;
                    }

                    ADV();
                }

                if ((B_10000DD4 != 0x5F) || (*B_10000DD8 != 0x5F)) {
                    return -1;
                }
                ADV();
                ADV();
            }
            if (STR_EQUAL(sp460, "__vtbl")) {
                if ((B_10000DD4 == 0x5F) && (*B_10000DD8 == 0x5F) && (B_10000DD8[1] != 0)) {
                    arg1->unk_04 = func_00400EF8(B_10000DD8 + 1);
                }
            } else {
                if (((B_10000DD4 == 0x43) || (B_10000DD4 == 0x53)) && (*B_10000DD8 == 0x46)) {
                    arg1->unk_1A = B_10000DD4;
                    ADV();
                }

                if (B_10000DD4 == 0x46) {
                    ADV();
                    arg1->unk_10 = func_00402D50();
                    if (arg1->unk_10 == NULL) {
                        return -1;
                    }
                }
            }

            if (((B_10000DD4 != 0) && !STR_EQUAL(sp460, "__vtbl")) || (D_10000000 != 0)) {
                return -1;
            }
            arg1->unk_00 = func_00400EF8(sp460);
        }
    }

block_187:
    var_v1_5 = 0;
    switch (arg1->unk_1A) {
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

        case 0x44: // dummy to force order
        //case 0x45:
        //case 0x46:
        //case 0x47:
        //case 0x48:
        //case 0x49:
        //case 0x4A:
        //case 0x4B:
        //case 0x4C:
        //case 0x4D:
        //case 0x4E:
        //case 0x4F:
        //case 0x50:
        //case 0x51:
        //case 0x52:
        //case 0x54:
        //case 0x55:
        //case 0x56:
        //case 0x57:
        //case 0x58:
        //case 0x59:
        //case 0x5A:
        //case 0x5B:
        //case 0x5C:
        //case 0x5D:
        //case 0x5E:
        //case 0x5F:
        //case 0x60:
        //case 0x61:
        //case 0x63:
        //case 0x65:
        //case 0x66:
        //case 0x67:
        //case 0x68:
        default:
            func_00400DE4("bad type set for p->sc", NULL, NULL);
            var_v1_5 = 0;
            break;

        case 0x0:
            if (arg1->unk_18 != -1) {
                var_v1_5 = 0xE;
            } else if (arg1->unk_10 != NULL) {
                if (arg1->unk_08 != NULL) {
                    var_v1_5 = 9;
                } else if (arg1->unk_0C != NULL) {
                    if ((arg1->unk_00[0] == 0x5F) && (arg1->unk_00[1] == 0x5F)) {
                        if ((arg1->unk_00[2] == 0x63) && (arg1->unk_00[3] == 0x74) && (arg1->unk_00[4] == 0)) {
                            var_v1_5 = 0xA;
                        } else if ((arg1->unk_00[2] == 0x64) && (arg1->unk_00[3] == 0x74) && (arg1->unk_00[4] == 0)) {
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
            } else if ((arg1->unk_00 == NULL) && (arg1->unk_0C != NULL)) {
                if (arg1->unk_0C->unk_04 != NULL) {
                    var_v1_5 = 0x10;
                } else {
                    var_v1_5 = 0xF;
                }
            } else if (arg1->unk_00 != NULL) {
                if (arg1->unk_0C != NULL) {
                    if (((arg1->unk_00[0] == 0x5F) && (arg1->unk_00[1] == 0x5F) && (arg1->unk_00[2] == 0x76) && (arg1->unk_00[3] == 0x74) && (arg1->unk_00[4] == 0x62) && (arg1->unk_00[5] == 0x6C) && (arg1->unk_00[6] == 0))) {
                        var_v1_5 = 3;
                    } else {
                        var_v1_5 = 0xD;
                    }
                } else {
                    var_v1_5 = 0xC;
                }
            }
            break;
    }

    if (var_v1_5 == 0) {
        func_00400DE4("cannot characterize type of input", NULL, NULL);
    }
    arg1->unk_14 = var_v1_5;
    return 0;
}
#else
int dem(char*, struct_demangle_sp24*, char*);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem.s")
#endif

void dem_printcl(struct_dem_printcl_arg0* arg0, char* arg1) {
    s32 var_s2;
    char sp44[0x400];

    if ((arg0 == NULL) || (arg1 == NULL)) {
        func_00400DE4("bad argument to dem_printcl()", NULL, NULL);
    }
    *arg1 = 0;
    var_s2 = 0;
    while (arg0 != NULL) {
        var_s2++;
        if (var_s2 >= 2) {
            strcat(arg1, "::");
        }
        strcat(arg1, arg0->unk_00);
        if (arg0->unk_04 != NULL) {
            if (arg1[strlen(arg1)-1] == 0x3C) {
                strcat(arg1, " ");
            }
            strcat(arg1, "<");
            dem_printarglist(arg0->unk_04, sp44, 0);
            strcat(arg1, sp44);
            if (arg1[strlen(arg1)-1] == 0x3E) {
                strcat(arg1, " ");
            }
            strcat(arg1, ">");
        }
        arg0 = arg0->unk_0C;
    }
}

void dem_printarglist(struct_dem_printarglist_arg0* arg0, char* arg1, int arg2) {
    if ((arg0 == NULL) || (arg1 == NULL) || (arg2 < 0) || (arg2 >= 2)) {
        func_00400DE4("bad argument to dem_printarglist()", NULL, NULL);
    }

    if ((arg0->unk_20 == 0x76) && (arg0->unk_00 == 0)&& (arg0->unk_18 != NULL) && (arg0->unk_18->unk_20 == 0x65) && (arg0->unk_18->unk_18 == 0)) {
        strcpy(arg1, "...");
    } else if ((arg0->unk_20 == 0x76) && (arg0->unk_00 == 0)) {
        strcpy(arg1, "void");
    } else {
        int var_s1;

        arg1[0] = 0;
        var_s1 = 0;
        while (arg0 != NULL) {
            char sp4C[0x400];
            var_s1++;

            if (var_s1 >= 2) {
                strcat(arg1, (arg0->unk_20 == 0x65) ? " " : ",");
            }

            dem_printarg(arg0, sp4C, arg2);
            strcat(arg1, sp4C);
            arg0 = arg0->unk_18;
        }
    }
}

#ifdef NON_EQUIVALENT
// #if 1
void dem_printarg(struct_dem_printarglist_arg0* arg0, char* arg1, int arg2) {
    char* sp1C84;
    char sp1884[0x400];
    char sp1484[0x400];
    char sp1084[0x400];
    char spC84[0x400];
    // spC80 ?
    char* var_s1;
    // spC7C ?
    char* var_s3;
    char sp87C[0x400];
    int sp878;
    // sp874 ?
    char* var_s0;
    char sp474[0x400];
    char sp74[0x400];
    // sp70 ?
    long temp_s0;
    int sp6C;
    int var_s0_5;
    int var_s5;

    if ((arg0 == NULL) || (arg1 == NULL) || (arg2 < 0) || ((arg2 >= 2))) {
        func_00400DE4("bad argument to dem_printarg()", NULL, NULL);
    }

    sp6C = arg2 == 0;
    switch (arg0->unk_20) {
    case 0x76:
        sp1C84 = "void";
        break;

    case 0x63:
        sp1C84 = "char";
        break;

    case 0x73:
        sp1C84 = "short";
        break;

    case 0x69:
        sp1C84 = "int";
        break;

    case 0x6C:
        sp1C84 = "long";
        break;

    case 0x4C:
        sp1C84 = "long long";
        break;

    case 0x66:
        sp1C84 = "float";
        break;

    case 0x64:
        sp1C84 = "double";
        break;

    case 0x72:
        sp1C84 = "long double";
        break;

    case 0x65:
        sp1C84 = "...";
        sp6C = 1;
        break;

    case 0x46:
        dem_printarg(arg0->unk_0C, spC84, 0);
        dem_printarglist(arg0->unk_08, sp1084, 0);
        break;

    case 0x43:
        dem_printcl(arg0->unk_10, sp1884);
        sp1C84 = sp1884;
        break;

    default:
        func_00400DE4("bad base type in dem_printarg()", NULL, NULL);
        break;
    }

    sp87C[0] = 0;
    var_s0 = arg0->unk_00;
    if (var_s0 == 0) {
        var_s0 = "";
    }

    var_s1 = var_s0;
    while (*var_s1 != 0) {
        if ((var_s1[0] == 0x43) && (var_s1[1] != 0x50) && (var_s1[1] != 0x52) && (var_s1[1] != 0x4D) && (var_s1[1] != 0x56) && ((var_s1[1] != 0) || (arg0->unk_20 != 0x46))) {
            strcat(sp87C, "const ");
            break;
        }

        var_s1 += 1;
    }

    var_s1 = var_s0;
    while (*var_s1 != 0) {
        if (*var_s1 == 0x55) {
            strcat(sp87C, "unsigned ");
            break;
        }

        var_s1 += 1;
    }

    var_s5 = 0;
    sp74[0] = 0;
    sp878 = 0;
    var_s1 = var_s0;
    while (*var_s1 != 0) {
        if (*var_s1 == 0x50) {
            sprintf(sp474, "*%s", sp74);
            strcpy(sp74, sp474);
        } else if (*var_s1 == 0x52) {
            sprintf(sp474, "&%s", sp74);
            strcpy(sp74, sp474);
        } else if (*var_s1 == 0x4D) {
            dem_printcl(arg0->unk_14[var_s5++], sp1484);
            sprintf(sp474, "%s::*%s", sp1484, sp74);
            strcpy(sp74, sp474);
        } else if ((*var_s1 == 0x43) && (((var_s1[1] == 0x50)) || ((var_s1[1] == 0x56) && (var_s1[2] == 0x50)))) {
            sprintf(sp474, " *const%s%s", (isalnum(sp74[0]) || (sp74[0] == 0x5F)) ? " " : "" , sp74);
            strcpy(sp74, sp474);
            var_s1 += 1;
            if (var_s1[0] == 0x56) {
                var_s1 += 1;
            }
        } else if ((*var_s1 == 0x43) && ( (var_s1[1] == 0x52) || ((var_s1[1] == 0x56) && (var_s1[2] == 0x52)))) {
            sprintf(sp474, " &const%s%s", (isalnum(sp74[0]) || (sp74[0] == 0x5F)) ? " " : "", sp74);
            strcpy(sp74, sp474);
            var_s1 += 1;
            if (var_s1[0] == 0x56) {
                var_s1 += 1;
            }
        } else if ((*var_s1 == 0x43) && (var_s1[1] == 0x4D)) {
            dem_printcl(arg0->unk_14[var_s5++], sp1484);
            sprintf(sp474, "%s::*const%s%s", sp1484, ((isalnum(sp74[0])) || (sp74[0] == 0x5F)) ? " " : "", sp74);
            strcpy(sp74, sp474);
            var_s1 += 1;
        } else if (*var_s1 == 0x41) {
            temp_s0 = arg0->unk_04[sp878++];

            var_s3 = (sp6C != 0) ? "" : "@";

            if (sp74[0] == 0) {
                sp6C = 1;
                sprintf(sp474, "%s[%ld]", var_s3, temp_s0);
            } else if ((sp74[0] == 0x28) || (sp74[0] == 0x5B)) {
                sprintf(sp474, "%s[%ld]", sp74, temp_s0);
            } else {
                sp6C = 1;
                sprintf(sp474, "(%s%s)[%ld]", sp74, var_s3, temp_s0);
            }
            strcpy(sp74, sp474);
        } else if ((*var_s1 != 0x55) && (*var_s1 != 0x43) && (*var_s1 != 0x53) && (*var_s1 != 0x56)) {
            func_00400DE4("bad value in modifier list", NULL, NULL);
        }
        var_s1 += 1;
    }

    var_s3 = (sp6C != 0) ? "" : "@";

    if (arg0->unk_20 == 0x46) {
        var_s0_5 = 0;
        if (sp74[0] == 0x20) {
            var_s0_5 = 1;
        }

        var_s1 = "";
        if ((arg0->unk_00 != 0) && (arg0->unk_00[strlen(arg0->unk_00)-1]  == 0x43)) {
            var_s1 = " const";
        }

        if (sp74[var_s0_5] != 0) {
            sprintf(arg1, "%s%s (%s%s)(%s)%s", sp87C, spC84, &sp74[var_s0_5], var_s3, sp1084, var_s1);
        } else {
            sprintf(arg1, "%s%s %s(%s)%s", sp87C, spC84, var_s3, sp1084, var_s1);
        }
    } else {
        sprintf(arg1, "%s%s%s%s%s", sp87C, sp1C84, ((sp74[0] == 0x28) || (isalnum(sp74[0])) || (sp74[0] == 0x5F)) ? " ": "", sp74, var_s3);
    }

    if (arg0->unk_1C != NULL) {
        if (isdigit(*arg0->unk_1C) || (*arg0->unk_1C == 0x2D)) {
            sprintf(sp474, "(%s)%s", arg1, arg0->unk_1C);
        } else {
            sprintf(sp474, "&%s", arg0->unk_1C);
        }
        strcpy(arg1, sp474);
    }
}
#else
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem_printarg.s")
#endif

typedef struct MangledMap {
    /* 0x0 */ const char* mangledName;
    /* 0x4 */ const char* demangled;
} MangledMap; // size = 0x8

STATIC struct MangledMap D_10000008[] = {
    { "__pp", "operator++" },
    { "__as", "operator=" },
    { "__vc", "operator[]" },
    { "__nw", "operator new" },
    { "__dl", "operator delete" },
    { "__rf", "operator->" },
    { "__ml", "operator*" },
    { "__mm", "operator--" },
    { "__oo", "operator||" },
    { "__md", "operator%" },
    { "__mi", "operator-" },
    { "__rs", "operator>>" },
    { "__ne", "operator!=" },
    { "__gt", "operator>" },
    { "__ge", "operator>=" },
    { "__or", "operator|" },
    { "__aa", "operator&&" },
    { "__nt", "operator!" },
    { "__apl", "operator+=" },
    { "__amu", "operator*=" },
    { "__amd", "operator%=" },
    { "__ars", "operator>>=" },
    { "__aor", "operator|=" },
    { "__cm", "operator," },
    { "__dv", "operator/" },
    { "__pl", "operator+" },
    { "__ls", "operator<<" },
    { "__eq", "operator==" },
    { "__lt", "operator<" },
    { "__le", "operator<=" },
    { "__ad", "operator&" },
    { "__er", "operator^" },
    { "__co", "operator~" },
    { "__ami", "operator-=" },
    { "__adv", "operator/=" },
    { "__als", "operator<<=" },
    { "__aad", "operator&=" },
    { "__aer", "operator^=" },
    { "__rm", "operator->*" },
    { "__cl", "operator()" },
    { NULL, NULL },
};

void dem_printfunc(struct_demangle_sp24* arg0, char* arg1) {
    int i;
    char buff[0x400];

    if ((arg0 == NULL) || (arg1 == NULL)) {
        func_00400DE4("bad argument to dem_printfunc()", NULL, NULL);
    }

    if ((arg0->unk_00[0] == '_') && (arg0->unk_00[1] == '_')) {
        if ((strncmp(arg0->unk_00, "__op", 4) == 0) && (arg0->unk_08 != NULL)) {
            dem_printarg(arg0->unk_08, buff, 0);
            sprintf(arg1, "operator %s", buff);
        } else {
            i = 0;
            while ((D_10000008[i].mangledName != NULL) && (strcmp(D_10000008[i].mangledName, arg0->unk_00) != 0)) {
                i++;
            }

            if (D_10000008[i].mangledName != NULL) {
                strcpy(arg1, D_10000008[i].demangled);
            } else {
                strcpy(arg1, arg0->unk_00);
            }
        }
    } else {
        strcpy(arg1, arg0->unk_00);
    }
}

int dem_print(struct_demangle_sp24* arg0, char* arg1) {
    char sp30[0x400];
    char* var_a2;
    int var_v1;

    if ((arg0 == NULL) || (arg1 == NULL)) {
        return -1;
    }

    *arg1 = '\0';
    if ((arg0->unk_00 == NULL) && (arg0->unk_0C != NULL)) {
        dem_printcl(arg0->unk_0C, arg1);
    } else if ((arg0->unk_1A == 'i') || (arg0->unk_1A == 'd')) {
        sprintf(arg1, "%s:__st%c", arg0->unk_00, arg0->unk_1A);
    } else if (arg0->unk_1A == 'b') {
        sprintf(arg1, "%s:__ptbl_vec", arg0->unk_00);
    } else {
        if (arg0->unk_0C != 0) {
            dem_printcl(arg0->unk_0C, sp30);
            strcat(arg1, sp30);
            strcat(arg1, "::");
        }

        var_v1 = strlen(sp30);
        var_a2 = &sp30[var_v1 - 1];

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

        if ((arg0->unk_00[0] == *"__ct") && (strcmp(arg0->unk_00, "__ct") == 0)) {
            strcat(arg1, &var_a2[1]);
        } else if ((arg0->unk_00[0] == *"__dt") && (strcmp(arg0->unk_00, "__dt") == 0)) {
            strcat(arg1, "~");
            strcat(arg1, &var_a2[1]);
        } else {
            dem_printfunc(arg0, sp30);
            strcat(arg1, sp30);
        }

        if (arg0->unk_10 != NULL) {
            strcat(arg1, "(");
            dem_printarglist(arg0->unk_10, sp30, 0);
            strcat(arg1, sp30);
            strcat(arg1, ")");
        }

        if (arg0->unk_1A == 'C') {
            strcat(arg1, " const");
        }
    }

    return 0;
}

const char* dem_explain(enum_dem_explain_arg0 arg) {
    switch (arg) {
        case ENUM_DEM_EXPLAIN_ARG_1:
            return "STATIC construction function";
        case ENUM_DEM_EXPLAIN_ARG_2:
            return "STATIC destruction function";
        case ENUM_DEM_EXPLAIN_ARG_3:
            return "virtual table";
        case ENUM_DEM_EXPLAIN_ARG_4:
            return "ptbl vector pointing to vtbls";
        case ENUM_DEM_EXPLAIN_ARG_5:
            return "function";
        case ENUM_DEM_EXPLAIN_ARG_6:
            return "member function";
        case ENUM_DEM_EXPLAIN_ARG_7:
            return "STATIC member function";
        case ENUM_DEM_EXPLAIN_ARG_8:
            return "constant member function";
        case ENUM_DEM_EXPLAIN_ARG_9:
            return "conversion operator member function";
        case ENUM_DEM_EXPLAIN_ARG_10:
            return "constructor";
        case ENUM_DEM_EXPLAIN_ARG_11:
            return "destructor";
        case ENUM_DEM_EXPLAIN_ARG_12:
            return "data";
        case ENUM_DEM_EXPLAIN_ARG_13:
            return "member data";
        case ENUM_DEM_EXPLAIN_ARG_14:
            return "local variable";
        case ENUM_DEM_EXPLAIN_ARG_15:
            return "class type";
        case ENUM_DEM_EXPLAIN_ARG_16:
            return "template type";
    }

    func_00400DE4("bad type passed to dem_explain()", NULL, NULL);
    return "";
}

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

STATIC void func_004054C0(FILE* arg0) {
    char sp458[0x400];
    char var_v0;
    char* temp_a0;
    char sp50[0x400];
    char* var_s0;

    while (fgets(sp458, 0x400, arg0) != NULL) {
        var_s0 = sp458;

        while (1) {
            while (*var_s0 && *var_s0 < 0x21) {
                putchar_locked(*var_s0);
                var_s0++;
            }

            if (!*var_s0) {
                break;
            }

            temp_a0 = var_s0;
            while (*var_s0 && *var_s0 >= 0x21) {
                var_s0++;
            }

            var_v0 = *var_s0;

            *var_s0 = 0;
            demangle(temp_a0, sp50);
            printf("%s", sp50);
            *var_s0 = var_v0;
        }
    }
}

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
