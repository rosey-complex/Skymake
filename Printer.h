#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>

class Printer {
public:
    int printHelp() {
        std::cout << "skymake <Options>\n"
                  << "\nOptions:\n"
                  << "        -h                        Print usage instructions.\n"
                  << "        -a <Skylander Name>       Auto mode.\n"
                  << "        -m <ID> <VarID(Hex)>      Manual Mode.\n"
                  << "                                *Use only if you know the IDs\n"
                  << "        -f <File or Directory>    Where to write the data\n"
                  << "        -s                        Avoid overwriting files\n"
                  << "                                 by adding a number in the\n"
                  << "                                 file name\n"
                  << "        -l                        List all available keywords\n"
                  << "                                 *Use with more or less\n";
        return 0;
    }

    int printErr(int errCode) {
        switch (errCode) {
            case -1: // usage error
                std::cerr << "! Error: missing options.\n"
                          << "* Try 'skymake -h' for usage instructions.\n";
                break;
            case -2: // not enough arguments
                std::cerr << "! Error: missing arguments.\n"
                          << "* Try 'skymake -h' for usage instructions.\n";
                break;
            case 2: // unknown skylander
                std::cerr << "! Error: Unknown Skylander." << std::endl;
                break;
            default:
                std::cerr << "! Unknown Error:\n"
                          << "* Try 'skymake -h' for usage instructions.\n";
                break;
        }
        return errCode;
    }

    void printWarn(int warnCode) {
        switch (warnCode) {
            case -1: // Imaginators/Sensei warning
                std::cerr << "* Warning: Senseis and Creation Crystals don't work in-game, yet..." << std::endl
                          << "* Creating Skylander anyway..." << std::endl;
                break;
            case 1: // File already exists
                std::cerr << "* Warning: file already exists!" << std::endl;
                break;
        }
    }

    int listAll() {
        for (const auto &[Name, IDs] : skylanderMap)
            std::cout << Name << " - (" << std::dec << IDs.first << ", 0x" << std::hex << IDs.second << ")" << std::endl;
        std::cout << "-- Imaginators (unsupported) --\n";
        for (const auto &[Name, IDs] : skylanderMap)
            std::cout << Name << " - (" << std::dec << IDs.first << ", 0x" << std::hex << IDs.second << ")" << std::endl;
        return 0;
    }
};
#endif