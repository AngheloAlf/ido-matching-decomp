#!/usr/bin/env python3

import argparse
from pathlib import Path
import spimdisasm


def configureSpimdisasm():
    spimdisasm.common.GlobalConfig.ALLOW_UNKSEGMENT = False
    spimdisasm.common.GlobalConfig.INPUT_FILE_TYPE = spimdisasm.common.InputFileType.ELF
    spimdisasm.common.GlobalConfig.EMIT_CPLOAD = False
    spimdisasm.common.GlobalConfig.REMOVE_POINTERS = True
    spimdisasm.common.GlobalConfig.IGNORE_BRANCHES = True


def doElf(elfFile: spimdisasm.elf32.Elf32File, elfBytes: bytearray, context: spimdisasm.common.Context):
    processedSegments, segmentPaths = spimdisasm.elfObjDisasm.getProcessedSections(context, elfFile, elfBytes, Path("dummy"), Path("-"), Path("-"))

    spimdisasm.elfObjDisasm.changeGlobalSegmentRanges(context, processedSegments)

    spimdisasm.elfObjDisasm.processGlobalOffsetTable(context, elfFile)

    spimdisasm.elfObjDisasm.injectAllElfSymbols(context, elfFile, processedSegments)

    processedFilesCount = 0
    for sect in processedSegments.values():
        processedFilesCount += len(sect)

    spimdisasm.frontendCommon.FrontendUtilities.analyzeProcessedFiles(processedSegments, segmentPaths, processedFilesCount)

    spimdisasm.frontendCommon.FrontendUtilities.nukePointers(processedSegments, segmentPaths, processedFilesCount)

    for textSection in processedSegments[spimdisasm.common.FileSectionType.Text]:
        for func in textSection.symbolList:
            print(func.getName())

    # Disassembles to stdout
    spimdisasm.frontendCommon.FrontendUtilities.writeProcessedFiles(processedSegments, segmentPaths, processedFilesCount)

    return processedSegments


def main():
    parser = argparse.ArgumentParser(description="")
    parser.add_argument("main_elf", help="")
    parser.add_argument("o_files", help="", nargs="+")

    args = parser.parse_args()

    configureSpimdisasm()

    mainElfPath = Path(args.main_elf)
    oFilesPaths = [Path(x) for x in args.o_files]

    context = spimdisasm.common.Context()

    print(mainElfPath)

    elfBytes = spimdisasm.common.Utils.readFileAsBytearray(mainElfPath)

    elfFile = spimdisasm.elf32.Elf32File(elfBytes)

    elfFile.handleHeaderIdent()
    elfFile.handleFlags()

    doElf(elfFile, elfBytes, context)

    for oPath in oFilesPaths:
        # TODO: maybe store somewhere?
        oContext = spimdisasm.common.Context()

        oBytes = spimdisasm.common.Utils.readFileAsBytearray(oPath)

        oElfFile = spimdisasm.elf32.Elf32File(oBytes)

        doElf(oElfFile, oBytes, oContext)

if __name__ == "__main__":
    main()
