#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "inttypes.h"
#include "ctype.h"
#include "dem.h"

typedef int UNK_TYPE;
typedef unsigned char UNK_TYPE1;
#define UNK_SIZE 1

#define STATIC static

// #define NON_EQUIVALENT
#ifndef putchar_locked
#define putchar_locked(x) putchar(x)
#endif

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
STATIC DEMARG* B_10000E3C;

#define ADV() if (B_10000DDC > 0) { \
            B_10000DD4 = *B_10000DD8++; \
        } else { \
            B_10000DD4 = '\0'; \
        } \
        B_10000DDC--


STATIC DEMARG *func_00402D50(void);


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
DEMCL* func_004011B4(void) {
    char* var_v1_2;
    int var_a3;
    int var_s0;
    char sp74[0x400];
    int var_a2;
    int var_s0_2;
    int sp68;
    DEMCL* temp_s5;
    DEMCL* sp60;
    DEMCL* sp5C;
    DEMARG* temp_v0;

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

    if (isdigit(B_10000DD4) && (B_10000DD8[var_a2] == 'Q') && isdigit(B_10000DD8[var_a2+1]) && (B_10000DD8[var_a2+2] == '_')) {
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
        temp_s5->rname = func_00400EF8(sp74);
        temp_s5->clargs = NULL;

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
            temp_s5->name = func_00400EF8(sp74);
        } else {
            if ((sp74[var_s0+4] != '_') || (sp74[var_s0+5] != '_')) {
                D_10000000 = 1;
                return NULL;
            }

            sp74[var_s0] = 0;
            temp_s5->name = func_00400EF8(sp74);

            var_s0 += 6;

            var_a3 = sp74[var_s0] - '0';
            if (!isdigit(sp74[var_s0])) {
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
            temp_s5->clargs = temp_v0;
        }

        temp_s5->next = NULL;
        if (sp60 != NULL) {
            sp5C->next = temp_s5;
            sp5C = temp_s5;
        } else {
            sp60 = temp_s5;
            sp5C = temp_s5;
        }
    }

    return sp60;
}
#else
DEMCL* func_004011B4(void);
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_004011B4.s")
#endif

STATIC DEMARG* func_00401A70(DEMARG* arg0) {
    DEMARG* temp_v0;

    if (arg0 == NULL) {
        func_00400DE4("bad argument to arg_copy()", NULL, NULL);
    }

    temp_v0 = func_00400E64(sizeof(DEMARG));
    temp_v0->mods = arg0->mods;
    temp_v0->base = arg0->base;
    temp_v0->arr = arg0->arr;
    temp_v0->func = arg0->func;
    temp_v0->clname = arg0->clname;
    temp_v0->mname = arg0->mname;
    temp_v0->lit = arg0->lit;
    temp_v0->ret = arg0->ret;
    temp_v0->next = NULL;
    return temp_v0;
}

#ifdef NON_EQUIVALENT
//#if 1
DEMARG* func_00401B48(int arg0, DEMARG* arg1[], int* arg2) {
    char spFA4[0x100]; // arbitrary
    int var_t5; // spFA0
    int spF9C;
    DEMCL* spF98;
    DEMARG* spF90;
    DEMARG* spF8C;
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
    DEMCL *sp54[100];
    int sp50;
    int sp4C;
    int temp_a1;
    int var_a0_2;
    int var_a1;
    int var_a1_5;
    int var_v0_2;
    char* temp_a2;
    DEMARG* temp_v0;
    DEMARG* var_a0;
    DEMCL* temp_v0_4;
    DEMCL* temp_v0_8;

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
                var_a0->mods = func_00400EF8(spFA4);
            } else {
                var_a0->mods = 0;
            }
            if (&spB8C[var_ra] != spB8C) {
                B_10000E3C = var_a0;
                var_a0->lit = func_00400EF8(spB8C);
            } else {
                var_a0->lit = NULL;
            }
            if (sp9F0 > 0) {
                B_10000E3C = var_a0;
                var_a0->arr = func_00400E64(sp9F0 * 4);

                for (var_v0_2 = 0; var_v0_2 < sp9F0; var_v0_2++) {
                    var_a0->arr[var_v0_2] = sp9F4[var_v0_2];
                }
            } else {
                var_a0->arr = NULL;
            }

            var_a0->base = spF9C;
            var_a0->func = spF90;
            var_a0->ret = spF8C;
            var_a0->clname = spF98;
            if (sp50 > 0) {
                B_10000E3C = var_a0;
                var_a0->mname = func_00400E64((sp50 + 1) * 4);

                for (var_a1_4 = 0; var_a1_4 < sp50; var_a1_4++) {
                    var_a0->mname[var_a1_4] = sp54[var_a1_4];
                }

                var_a0->mname[sp50] = NULL;
            } else {
                var_a0->mname = NULL;
            }

            var_a0->next = NULL;
            B_10000E3C = var_a0;
            return var_a0;
        }
    }
}
#else
DEMARG* func_00401B48(int arg0, DEMARG* arg1[], int *arg2);

// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/func_00401B48.s")
#endif

STATIC DEMARG* func_00402D50(void) {
    DEMARG* var_s3 = NULL; // head
    DEMARG* var_s0 = NULL;
    int var_s1 = -1;
    DEMARG *sp3C[100];
    DEMARG* temp_v0;
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
            var_s0->next = temp_v0;
            var_s0 = temp_v0;
        }
    }
}

#define STR_EQUAL(a, b) ((*(a) == *(b)) && (strcmp((a), (b)) == 0))
#define STR_EQUAL_N(a, b) (strncmp((a), (b), sizeof((b)) - 1) == 0)

#ifdef NON_EQUIVALENT
//#if 1
int dem(char* s, DEM* p, char* buf) {
    // spXXX means that variable must belong in that stack position
    // spXXX? means I have no clue if the variable is real or its stack position
    char sp460[0x400];
    int var_a2; // sp45C
    unsigned int var_a1; // sp458
    int var_a1_2; // sp454 ?
    int var_v1_2; // sp450 ?
    char* var_a0; // sp44C ?
    char* temp_v1_2; // sp448
    short t;
    char var_v0; // sp34?
    char* var_a0_3; // sp440 ?
    char sp40[0x400];
    enum DEM_TYPE var_v1_5; // sp3C

    if ((s == NULL) || (p == NULL) || (buf == NULL)) {
        return -1;
    }

    if (!s[0]) {
        return -1;
    }

    B_10000DD0 = buf;
    D_10000004 = -1;
    D_10000000 = 0;
    p->fargs = NULL;
    p->cl = NULL;
    p->sc = '\0';
    p->args = NULL;
    p->f = NULL;
    p->vtname = NULL;
    p->slev = -1;
    p->type = DEM_NONE;

    if ((s[0] == 0x5F) && (s[1] == 0x5F)) {
        var_a0 = s + 2;
        var_v0 = *var_a0;

        if (isdigit(var_v0)) {
            for (var_a1 = 0; isdigit(var_v0); ) {
                var_v0 = *var_a0;
                var_a1 = var_v0 + (var_a1 * 0xA) - 0x30;
                var_a0++;
                var_v0 = *var_a0;
            }

            if (*var_a0) {
                p->f = func_00400EF8(var_a0);
                p->slev = var_a1;
                goto block_187;
            }
        }
    }

    if ((s[0] == 0x5F) && (s[1] == 0x5F) && (STR_EQUAL_N(s, "__sti__") || STR_EQUAL_N(s, "__std__") || STR_EQUAL_N(s, "__ptbl_vec__"))) {
        p->sc = s[4];
        var_a0 = (s[2] == 0x73) ? s + 7 : s + 12;

        while (*var_a0 == 0x5F) {
            var_a0++;
        }

        var_a0_3 = var_a0;
        while ((var_a0_3[0]) && ((var_a0_3[0] != 0x5F) || (var_a0_3[1] != 0x63) || (var_a0_3[2] != 0x5F))) {
            var_a0_3++;
        }
        *var_a0_3 = 0;

        if (!var_a0[0]) {
            return -1;
        }

        p->f = func_00400EF8(var_a0);
        B_10000DD4 = 0;
        goto block_187;
    }

    var_a0_3 = s;
    var_v1_2 = 0;

    while ((var_a0_3[0]) && ((var_a0_3[0] != 0x5F) || (var_a0_3 == s) || (var_a0_3[-1] != 0x5F))) {
        var_a0_3++;
    }

    if ((var_a0_3[0] == 0x5F) && (var_a0_3[1] == 0x70) && (var_a0_3[2] == 0x74) && (var_a0_3[3] == 0x5F) && (var_a0_3[4] == 0x5F)) {
        var_v1_2 = 1;
    }

    if ((var_a0_3[0] == 0x5F) && (var_a0_3[1] == 0x5F) && (var_a0_3[2] == 0x70) && (var_a0_3[3] == 0x74) && (var_a0_3[4] == 0x5F) && (var_a0_3[5] == 0x5F)) {
        var_v1_2 = 1;
    }

    if ((!var_v1_2) && (s[0] == 0x5F) && (s[1] == 0x5F) && (s[2] == 0x51) && (isdigit(s[3])) && (s[4] == 0x5F)) {
        var_v1_2 = 2;
    }

    if (var_v1_2) {
        D_10000004 = -1;
        D_10000000 = 0;
        if (var_v1_2 == 1) {
            sprintf(sp40, "%d%s", strlen(s), s);
            func_00400FA4(sp40, 0x270F);
        } else {
            func_00400FA4(s + 2, 0x270F);
        }
        p->cl = func_004011B4();
        if (p->cl == NULL) {
            return -1;
        }
        B_10000DD4 = 0;
        goto block_187;
    }

    D_10000004 = -1;
    func_00400FA4(s, 0x270F);
    D_10000000 = 0;
    var_a2 = 0;
    sp460[0] = 0;
    while (isalnum(B_10000DD4) || (B_10000DD4 == 0x5F)) {
        sp460[var_a2++] = B_10000DD4;
        sp460[var_a2] = 0;
        if (!B_10000DD8[0] || (B_10000DD8[0] == 0x5F) && (B_10000DD8[1] == 0x5F) && (B_10000DD8[2] != 0x5F)) {
            ADV();
            break;
        }
        ADV();

        if (STR_EQUAL(sp460, "__op")) {
            temp_v1_2 = B_10000DD8 - 1;

            p->fargs = func_00401B48(-1, NULL, NULL);
            if (p->fargs == NULL) {
                return -1;
            }

            while (temp_v1_2 < B_10000DD8 - 1) {
                sp460[var_a2++] = *temp_v1_2++;
            }

            sp460[var_a2] = 0;
            break;
        }

    }

    if (!isalpha(sp460[0]) && (sp460[0] != 0x5F)) {
        return -1;
    }

    if ((B_10000DD4 == 0x5F) && (B_10000DD8[0] == 0x5F)) {
        ADV();
        ADV();

        if (!B_10000DD4) {
            return -1;
        }
    }

    if ((isdigit(B_10000DD4)) || (B_10000DD4 == 0x51)) {
        p->cl = func_004011B4();
        if (p->cl == NULL) {
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

        // huh?
        for (; var_a1_2-- > 0; ) {
            if (!isalnum(B_10000DD4) && B_10000DD4 != 0x5F) {
                return -1;
            }

            ADV();
            var_a1_2 &= 0xFFFFFFFF;
            var_a1_2 &= 0xFFFFFFFF;
        }

        if ((B_10000DD4 != 0x5F) || (B_10000DD8[0] != 0x5F)) {
            return -1;
        }

        ADV();
        ADV();
    }

    if (STR_EQUAL(sp460, "__vtbl")) {
        if ((B_10000DD4 == 0x5F) && (B_10000DD8[0] == 0x5F) && (B_10000DD8[1])) {
            p->vtname = func_00400EF8(B_10000DD8 + 1);
        }
    } else {
        if (((B_10000DD4 == 0x43) || (B_10000DD4 == 0x53)) && (B_10000DD8[0] == 0x46)) {
            p->sc = B_10000DD4;
            ADV();
        }

        if (B_10000DD4 == 0x46) {
            ADV();
            p->args = func_00402D50();
            if (p->args == NULL) {
                return -1;
            }
        }

        var_a1 = B_10000DD4;
    }

    var_a1 = B_10000DD4;

    if ((var_a1 && !STR_EQUAL(sp460, "__vtbl")) || (D_10000000)) {
        return -1;
    }

    p->f = func_00400EF8(sp460);


block_187:
    t = p->sc;
    var_v1_5 = 0;
    if (t) {
        switch (t) {
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
                func_00400DE4("bad type set for p->sc", NULL, NULL);
                var_v1_5 = 0;
                break;
        }
    } else {
        if (p->slev != -1) {
            var_v1_5 = 14;
        } else if (p->args != NULL) {
            if (p->fargs != NULL) {
                var_v1_5 = 9;
            } else if (p->cl != NULL) {
                if ((p->f[0] == 0x5F) && (p->f[1] == 0x5F)) {
                    if ((p->f[2] == 0x63) && (p->f[3] == 0x74) && (!p->f[4])) {
                        var_v1_5 = 10;
                    } else if ((p->f[2] == 0x64) && (p->f[3] == 0x74) && (!p->f[4])) {
                        var_v1_5 = 11;
                    } else {
                        var_v1_5 = 6;
                    }
                } else {
                    var_v1_5 = 6;
                }
            } else {
                var_v1_5 = 5;
            }
        } else if (p->f == NULL) {
            if (p->cl != NULL) {
                if (p->cl->clargs != NULL) {
                    var_v1_5 = 16;
                } else {
                    var_v1_5 = 15;
                }
            }
        } else if (p->f != NULL) {
            if (p->cl != NULL) {
                if (((p->f[0] == 0x5F) && (p->f[1] == 0x5F) && (p->f[2] == 0x76) && (p->f[3] == 0x74) && (p->f[4] == 0x62) && (p->f[5] == 0x6C) && (!p->f[6]))) {
                    var_v1_5 = 3;
                } else {
                    var_v1_5 = 13;
                }
            } else {
                var_v1_5 = 12;
            }
        }
    }

    if (!var_v1_5) {
        func_00400DE4("cannot characterize type of input", NULL, NULL);
    }

    p->type = var_v1_5;
    return 0;
}
#else
// #pragma GLOBAL_ASM("asm/5.3/functions/c++filt/c++filt/dem.s")
#endif

void dem_printcl(DEMCL* p, char* buf) {
    int var_s2;
    char sp44[0x400];

    if ((p == NULL) || (buf == NULL)) {
        func_00400DE4("bad argument to dem_printcl()", NULL, NULL);
    }

    *buf = '\0';
    var_s2 = 0;
    while (p != NULL) {
        var_s2++;
        if (var_s2 >= 2) {
            strcat(buf, "::");
        }

        strcat(buf, p->name);
        if (p->clargs != NULL) {
            if (buf[strlen(buf)-1] == 0x3C) {
                strcat(buf, " ");
            }

            strcat(buf, "<");
            dem_printarglist(p->clargs, sp44, 0);
            strcat(buf, sp44);
            if (buf[strlen(buf)-1] == '>') {
                strcat(buf, " ");
            }
            strcat(buf, ">");
        }

        p = p->next;
    }
}

void dem_printarglist(DEMARG* p, char* buf, int sv) {
    if ((p == NULL) || (buf == NULL) || (sv < 0) || (sv >= 2)) {
        func_00400DE4("bad argument to dem_printarglist()", NULL, NULL);
    }

    if ((p->base == 0x76) && (p->mods == 0)&& (p->next != NULL) && (p->next->base == 0x65) && (p->next->next == 0)) {
        strcpy(buf, "...");
    } else if ((p->base == 0x76) && (p->mods == 0)) {
        strcpy(buf, "void");
    } else {
        int var_s1;

        buf[0] = '\0';
        var_s1 = 0;
        while (p != NULL) {
            char sp4C[0x400];
            var_s1++;

            if (var_s1 >= 2) {
                strcat(buf, (p->base == 0x65) ? " " : ",");
            }

            dem_printarg(p, sp4C, sv);
            strcat(buf, sp4C);
            p = p->next;
        }
    }
}

#ifdef NON_EQUIVALENT
// #if 1
void dem_printarg(DEMARG* p, char* buf, int f) {
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

    if ((p == NULL) || (buf == NULL) || (f < 0) || ((f >= 2))) {
        func_00400DE4("bad argument to dem_printarg()", NULL, NULL);
    }

    sp6C = f == 0;
    switch (p->base) {
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
        dem_printarg(p->ret, spC84, 0);
        dem_printarglist(p->func, sp1084, 0);
        break;

    case 0x43:
        dem_printcl(p->clname, sp1884);
        sp1C84 = sp1884;
        break;

    default:
        func_00400DE4("bad base type in dem_printarg()", NULL, NULL);
        break;
    }

    sp87C[0] = 0;
    var_s0 = p->mods;
    if (var_s0 == 0) {
        var_s0 = "";
    }

    var_s1 = var_s0;
    while (*var_s1 != 0) {
        if ((var_s1[0] == 0x43) && (var_s1[1] != 0x50) && (var_s1[1] != 0x52) && (var_s1[1] != 0x4D) && (var_s1[1] != 0x56) && ((var_s1[1] != 0) || (p->base != 0x46))) {
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
            dem_printcl(p->mname[var_s5++], sp1484);
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
            dem_printcl(p->mname[var_s5++], sp1484);
            sprintf(sp474, "%s::*const%s%s", sp1484, ((isalnum(sp74[0])) || (sp74[0] == 0x5F)) ? " " : "", sp74);
            strcpy(sp74, sp474);
            var_s1 += 1;
        } else if (*var_s1 == 0x41) {
            temp_s0 = p->arr[sp878++];

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

    if (p->base == 0x46) {
        var_s0_5 = 0;
        if (sp74[0] == 0x20) {
            var_s0_5 = 1;
        }

        var_s1 = "";
        if ((p->mods != 0) && (p->mods[strlen(p->mods)-1]  == 0x43)) {
            var_s1 = " const";
        }

        if (sp74[var_s0_5] != 0) {
            sprintf(buf, "%s%s (%s%s)(%s)%s", sp87C, spC84, &sp74[var_s0_5], var_s3, sp1084, var_s1);
        } else {
            sprintf(buf, "%s%s %s(%s)%s", sp87C, spC84, var_s3, sp1084, var_s1);
        }
    } else {
        sprintf(buf, "%s%s%s%s%s", sp87C, sp1C84, ((sp74[0] == 0x28) || (isalnum(sp74[0])) || (sp74[0] == 0x5F)) ? " ": "", sp74, var_s3);
    }

    if (p->lit != NULL) {
        if (isdigit(*p->lit) || (*p->lit == 0x2D)) {
            sprintf(sp474, "(%s)%s", buf, p->lit);
        } else {
            sprintf(sp474, "&%s", p->lit);
        }
        strcpy(buf, sp474);
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

void dem_printfunc(DEM* dp, char* buf) {
    int i;
    char buff[0x400];

    if ((dp == NULL) || (buf == NULL)) {
        func_00400DE4("bad argument to dem_printfunc()", NULL, NULL);
    }

    if ((dp->f[0] == '_') && (dp->f[1] == '_')) {
        if ((strncmp(dp->f, "__op", 4) == 0) && (dp->fargs != NULL)) {
            dem_printarg(dp->fargs, buff, 0);
            sprintf(buf, "operator %s", buff);
        } else {
            i = 0;
            while ((D_10000008[i].mangledName != NULL) && (strcmp(D_10000008[i].mangledName, dp->f) != 0)) {
                i++;
            }

            if (D_10000008[i].mangledName != NULL) {
                strcpy(buf, D_10000008[i].demangled);
            } else {
                strcpy(buf, dp->f);
            }
        }
    } else {
        strcpy(buf, dp->f);
    }
}

int dem_print(DEM* p, char* buf) {
    char sp30[0x400];
    char* var_a2;
    int var_v1;

    if ((p == NULL) || (buf == NULL)) {
        return -1;
    }

    *buf = '\0';
    if ((p->f == NULL) && (p->cl != NULL)) {
        dem_printcl(p->cl, buf);
    } else if ((p->sc == 'i') || (p->sc == 'd')) {
        sprintf(buf, "%s:__st%c", p->f, p->sc);
    } else if (p->sc == 'b') {
        sprintf(buf, "%s:__ptbl_vec", p->f);
    } else {
        if (p->cl != 0) {
            dem_printcl(p->cl, sp30);
            strcat(buf, sp30);
            strcat(buf, "::");
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

        if ((p->f[0] == *"__ct") && (strcmp(p->f, "__ct") == 0)) {
            strcat(buf, &var_a2[1]);
        } else if ((p->f[0] == *"__dt") && (strcmp(p->f, "__dt") == 0)) {
            strcat(buf, "~");
            strcat(buf, &var_a2[1]);
        } else {
            dem_printfunc(p, sp30);
            strcat(buf, sp30);
        }

        if (p->args != NULL) {
            strcat(buf, "(");
            dem_printarglist(p->args, sp30, 0);
            strcat(buf, sp30);
            strcat(buf, ")");
        }

        if (p->sc == 'C') {
            strcat(buf, " const");
        }
    }

    return 0;
}

char* dem_explain(enum DEM_TYPE t) {
    switch (t) {
        case DEM_STI:
            return "STATIC construction function";

        case DEM_STD:
            return "STATIC destruction function";

        case DEM_VTBL:
            return "virtual table";

        case DEM_PTBL:
            return "ptbl vector pointing to vtbls";

        case DEM_FUNC:
            return "function";

        case DEM_MFUNC:
            return "member function";

        case DEM_SMFUNC:
            return "STATIC member function";

        case DEM_CMFUNC:
            return "constant member function";

        case DEM_OMFUNC:
            return "conversion operator member function";

        case DEM_CTOR:
            return "constructor";

        case DEM_DTOR:
            return "destructor";

        case DEM_DATA:
            return "data";

        case DEM_MDATA:
            return "member data";

        case DEM_LOCAL:
            return "local variable";

        case DEM_CTYPE:
            return "class type";

        case DEM_TTYPE:
            return "template type";

        default:
            func_00400DE4("bad type passed to dem_explain()", NULL, NULL);
            return "";
    }
}

int demangle(const char *in, char *out) {
    char sp40[0x1000];
    DEM sp24;

    if ((in == NULL) || (*in == '\0') || (out == NULL)) {
        return -1;
    }

    if (dem((void*)in, &sp24, sp40) < 0) {
        strcpy(out, in);
        return -1;
    }

    dem_print(&sp24, out);
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
