#include "stdio.h"

// _ftext

// func_00400BD0

// __start

// _mcount

// func_00400DE4

// func_00400E64

// func_00400EF8

// func_00400FA4

// func_004010F8

// func_004011B4

// func_00401A70

// func_00401B48

// func_00402D50

// dem

// dem_printcl

// dem_printarglist

// dem_printarg

// STR_100004A4

// STR_100004AC

// STR_100004B8

// STR_100004C0

// STR_100004CC

// STR_100004D4

// STR_100004E0

// STR_100004E8

// STR_100004F8

// STR_10000500

// STR_10000510

// STR_10000518

// STR_10000524

// STR_1000052C

// STR_10000538

// STR_10000540

// STR_1000054C

// STR_10000554

// STR_10000560

// STR_10000568

// STR_10000574

// STR_1000057C

// STR_10000588

// STR_10000590

// STR_1000059C

// STR_100005A4

// STR_100005B0

// STR_100005B8

// STR_100005C4

// STR_100005CC

// STR_100005D8

// STR_100005E0

// STR_100005EC

// STR_100005F4

// STR_10000600

// STR_10000608

// STR_10000614

// STR_1000061C

// STR_10000628

// STR_10000630

// STR_1000063C

// STR_10000644

// STR_10000650

// STR_10000658

// STR_10000664

// STR_1000066C

// STR_10000678

// STR_10000680

// STR_1000068C

// STR_10000694

// STR_100006A0

// STR_100006A8

// STR_100006B4

// STR_100006BC

// STR_100006C8

// STR_100006D0

// STR_100006DC

// STR_100006E4

// STR_100006F0

// STR_100006F8

// STR_10000704

// STR_1000070C

// STR_10000718

// STR_10000720

// STR_1000072C

// STR_10000734

// STR_10000740

// STR_10000748

// STR_10000754

// STR_1000075C

// STR_10000768

// STR_10000770

// STR_1000077C

// STR_10000784

// STR_10000790

// STR_10000798

// STR_100007A4

// STR_100007AC

// STR_100007B8

// STR_100007C0

// dem_printfunc

// dem_print

// dem_explain

// demangle

// func_004054C0
// static
void func_004054C0(FILE*);

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
// STR_10000CA0

