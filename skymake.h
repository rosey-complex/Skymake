#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <filesystem>
#include "skylanders.h"

static uint16_t skylanderCRC16(uint16_t init_value, const uint8_t *buffer, uint32_t size) {
    static constexpr std::array<uint16_t, 256> CRC_CCITT_TABLE {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7, 0x8108, 0x9129, 0xA14A,
        0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF, 0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294,
        0x72F7, 0x62D6, 0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE, 0x2462,
        0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485, 0xA56A, 0xB54B, 0x8528, 0x9509,
        0xE5EE, 0xF5CF, 0xC5AC, 0xD58D, 0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695,
        0x46B4, 0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC, 0x48C4, 0x58E5,
        0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823, 0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948,
        0x9969, 0xA90A, 0xB92B, 0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
        0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A, 0x6CA6, 0x7C87, 0x4CE4,
        0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41, 0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B,
        0x8D68, 0x9D49, 0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70, 0xFF9F,
        0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78, 0x9188, 0x81A9, 0xB1CA, 0xA1EB,
        0xD10C, 0xC12D, 0xF14E, 0xE16F, 0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046,
        0x6067, 0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E, 0x02B1, 0x1290,
        0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256, 0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E,
        0xE54F, 0xD52C, 0xC50D, 0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
        0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C, 0x26D3, 0x36F2, 0x0691,
        0x16B0, 0x6657, 0x7676, 0x4615, 0x5634, 0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9,
        0xB98A, 0xA9AB, 0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3, 0xCB7D,
        0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A, 0x4A75, 0x5A54, 0x6A37, 0x7A16,
        0x0AF1, 0x1AD0, 0x2AB3, 0x3A92, 0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8,
        0x8DC9, 0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1, 0xEF1F, 0xFF3E,
        0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8, 0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93,
        0x3EB2, 0x0ED1, 0x1EF0};

    uint16_t crc = init_value;

    for (uint32_t i = 0; i < size; i++) {
        const uint16_t tmp = (crc >> 8) ^ buffer[i];
        crc = (crc << 8) ^ CRC_CCITT_TABLE[tmp];
    }

    return crc;
}

bool CreateSkylander(const std::string &skylanderName, const std::string &targetFile, bool Sw[], const uint16_t customID = 0, const uint16_t customVar = 0x0000) {
    /*
    Sw[0]   - Unsafe/Safe Mode
    Sw[1]   - Auto/Manual Mode
    */

    std::string filePathNoExtension;
    std::string filePath;
    uint16_t SkyID = 0;
    uint16_t SkyVarID = 0;
    bool isFromSI = false;

    // Manual (ID Explicit) Mode 
    if (Sw[1]) {
        //// Allows a user to create a skylander if they know the variant ID and skylander ID
        // Use a file name based on the provided IDs
        filePath = targetFile + "/" + std::to_string(customID) + "-" + std::to_string(customVar) + ".sky";

        // Set the IDs
        SkyID = customID;
        SkyVarID = customVar;
    }
    // Auto (ID Imlicit) Mode
    else {
        filePath = targetFile + "/" + skylanderName + ".sky";
        // Lookup the Skylander data based on the given skylanderName
        auto it = imaginatorsMap.find(skylanderName);
        if (it != imaginatorsMap.end()) {
            isFromSI = true;
            std::pair<uint16_t, uint16_t> IDs = imaginatorsMap[skylanderName];
            SkyID = IDs.first;
            SkyVarID = IDs.second;
        }
        else {
            auto it = skylanderMap.find(skylanderName);
            if (it != skylanderMap.end()) {
                std::pair<uint16_t, uint16_t> IDs = skylanderMap[skylanderName];
                SkyID = IDs.first;
                SkyVarID = IDs.second;
                std::cout << "* Found: " << skylanderName;
            }
            else {
                return false;
            }
        }
    }
    // File Path without extension
    filePathNoExtension = filePath;
    for (uint8_t i = 0; i <= 3; i++) filePathNoExtension.pop_back();

    // Check if file already exists and warn the user about overwriting
    if (std::filesystem::exists(filePath)) {
        // Avoid overwriting by adding a number before the file extension
        if (Sw[0]) {
            for (uint32_t n = 0; n <= UINT32_MAX; n++) {
                if (!(std::filesystem::exists(filePathNoExtension + "." + std::to_string(n) + ".sky"))) {
                    filePath = filePathNoExtension + "." + std::to_string(n) + ".sky";
                    break;
                }
            }
            std::cout << "* Avoiding overwrite by writing to " << filePath << std::endl;
        }
        else std::cout << "* Overwriting..." << std::endl;
    }
    else std::cout << "* Creating file " << filePath << std::endl;

    //// Skylander figurine data file creation

    // Create empty file
    std::ofstream skyFile(filePath, std::ios::binary);
    skyFile.clear();

    // Create data buffer
    std::array<uint8_t, 0x40 * 0x10> buf{};
    const auto fileData = buf.data();

    // Set the block permissions
    uint32_t firstBlock = 0x690F0F0F;
    uint32_t otherBlocks = 0x69080F7F;
    memcpy(&fileData[0x36], &firstBlock, sizeof(firstBlock));
    for (uint32_t index = 1; index < 0x10; index++) {
        memcpy(&fileData[(index * 0x40) + 0x36], &otherBlocks, sizeof(otherBlocks));
    }

    if (isFromSI) {
        // Set the skylander info
        memcpy(&fileData[0x10], &SkyID, sizeof(SkyID));
        memcpy(&fileData[0x1C], &SkyVarID, sizeof(SkyVarID));

        std::tuple< 
                    uint32_t,                        // NUID
                    std::pair<uint64_t, uint64_t>,  // 0x20
                    std::pair<uint64_t, uint64_t>,  // 0x40
                    std::pair<uint64_t, uint64_t>,  // 0x220
                    std::pair<uint64_t, uint64_t>,  // 0x3E0
                    std::pair<uint8_t, uint8_t>  // Magic Numbers
                    > BFIMBytes = BFIM[skylanderName];
        // Declare the bytes as varables and unpack th tuple
        uint32_t NUID;
        std::pair<uint64_t, uint64_t> Bx2X, Bx4X, Bx22X, Bx3EX;
        std::pair<uint8_t, uint8_t> magicNums;
        std::tie(NUID, Bx2X, Bx4X, Bx22X, Bx3EX, magicNums) = BFIMBytes;

        // Convert values to big endian format
        NUID =     htobe32(NUID);
        Bx2X.first =    htobe64(Bx2X.first);
        Bx4X.first =    htobe64(Bx4X.first);
        Bx22X.first =   htobe64(Bx22X.first);
        Bx3EX.first =   htobe64(Bx3EX.first);
        Bx2X.second =   htobe64(Bx2X.second);
        Bx4X.second =   htobe64(Bx4X.second);
        Bx22X.second =  htobe64(Bx22X.second);
        Bx3EX.second =  htobe64(Bx3EX.second);
        //// Write the bytes
        // NUID
        memcpy(&fileData[0x0], &NUID, sizeof(NUID));
        
        // The BCC (Block Check Character)
        fileData[4] = fileData[0] ^ fileData[1] ^ fileData[2] ^ fileData[3];

        // ATQA
        fileData[5] = 0x81;
        fileData[6] = 0x01;

        // SAK
        fileData[7] = 0x0F;

        // Specific bytes
        fileData[0x8] = 0xC4;
        fileData[0x3F] = 0x51;

        // Magic Bytes
        fileData[0x9] = magicNums.first;
        fileData[0xF] = magicNums.second;

        // Set checksum
        uint16_t checksum = skylanderCRC16(0xFFFF, fileData, 0x1E);
        memcpy(&fileData[0x1E], &checksum, sizeof(checksum));

        // 0x20
        memcpy(&fileData[0x20], &Bx2X.first, sizeof(Bx2X.first));
        memcpy(&fileData[0x28], &Bx2X.second, sizeof(Bx2X.second));
        
        // 0x40
        memcpy(&fileData[0x40], &Bx4X.first, sizeof(Bx4X.first));
        memcpy(&fileData[0x48], &Bx4X.second, sizeof(Bx4X.second));
        // 0x220
        memcpy(&fileData[0x220], &Bx22X.first, sizeof(Bx22X.first));
        memcpy(&fileData[0x228], &Bx22X.second, sizeof(Bx22X.second));
        // 0x3E0
        memcpy(&fileData[0x3E0], &Bx3EX.first, sizeof(Bx3EX.first));
        memcpy(&fileData[0x3E8], &Bx3EX.second, sizeof(Bx3EX.second));
    }
    else {
        // Set the NUID of the figure
        srand (time(NULL));
        uint32_t RandNUID = rand();
        memcpy(&fileData[0], &RandNUID, sizeof(RandNUID));

        // The BCC (Block Check Character)
        fileData[4] = fileData[0] ^ fileData[1] ^ fileData[2] ^ fileData[3];

        // ATQA
        fileData[5] = 0x81;
        fileData[6] = 0x01;

        // SAK
        fileData[7] = 0x0F;

        // Set the skylander info
        memcpy(&fileData[0x10], &SkyID, sizeof(SkyID));
        memcpy(&fileData[0x1C], &SkyVarID, sizeof(SkyVarID));

        // Set checksum
        uint16_t checksum = skylanderCRC16(0xFFFF, fileData, 0x1E);
        memcpy(&fileData[0x1E], &checksum, sizeof(checksum));
    }

    // Write the data to the .sky file
    skyFile.write(reinterpret_cast<const char *>(buf.data()), buf.size());
    skyFile.close();

    return true;
}
