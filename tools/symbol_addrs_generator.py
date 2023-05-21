#!/usr/bin/env python3

import argparse
from pathlib import Path
import spimdisasm


def main():
    parser = argparse.ArgumentParser(description="")
    parser.add_argument("context_file", help="")

    args = parser.parse_args()
    contextPath = Path(args.context_file)

    contextCsv = spimdisasm.common.Utils.readCsv(contextPath)

    header = contextCsv[0]
    spimdisasm.common.Utils.eprint(header)
    addressIndex = header.index("address")
    getNameIndex = header.index("getName")
    getTypeIndex = header.index("getType")
    accessTypeIndex = header.index("accessType")
    getSizeIndex = header.index("getSize")
    sectionTypeIndex = header.index("sectionType")
    isMaybeStringIndex = header.index("isMaybeString")

    lastSectionType = ""

    for row in contextCsv[1:]:
        if row[0] != "symbol":
            continue

        address = row[addressIndex]
        getName = row[getNameIndex]
        getType = row[getTypeIndex]
        accessType = row[accessTypeIndex]
        getSize = row[getSizeIndex]
        sectionType = row[sectionTypeIndex]
        isMaybeString = row[isMaybeStringIndex]

        if getType in {"@branchlabel", "@jumptablelabel", "@jumptable"}:
            continue

        if getName in {"$$.LazyResolver"}:
            continue

        if sectionType != lastSectionType:
            print(f"\n// {sectionType}\n")

        address = f"0x{int(address, 0):08X}"

        print(f"{getName} = {address}; //", end="")

        if getType != "" or isMaybeString != "False":
            if getType == "@function":
                getType = "func"
            if isMaybeString == "True":
                getType = "asciz"
            print(f" type:{getType}", end="")
        # print(f" accessType:{accessType}", end="")
        # print(f" size:{getSize}", end="")
        # print(f" sectionType:{sectionType}", end="")
        # print(f" isMaybeString:{isMaybeString}", end="")
        print()
        lastSectionType =sectionType


if __name__ == "__main__":
    main()
