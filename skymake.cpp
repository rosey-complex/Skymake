#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <mbedtls/entropy.h>
#include <mbedtls/hmac_drbg.h>
#include <filesystem>
#include "Figurines.h"

class entropySeededPRNG final
{
public:
  entropySeededPRNG()
  {
    mbedtls_entropy_init(&m_entropy);
    mbedtls_hmac_drbg_init(&m_context);
    const int ret = mbedtls_hmac_drbg_seed(
                        &m_context, mbedtls_md_info_from_type(MBEDTLS_MD_SHA256),
                        mbedtls_entropy_func, &m_entropy, nullptr, 0);
  }

  ~entropySeededPRNG()
  {
    mbedtls_hmac_drbg_free(&m_context);
    mbedtls_entropy_free(&m_entropy);
  }

  void Generate(void* buffer, std::size_t size)
  {
    const int ret = mbedtls_hmac_drbg_random(&m_context, static_cast<uint8_t*>(buffer), size);
  }

private:
  mbedtls_entropy_context m_entropy;
  mbedtls_hmac_drbg_context m_context;
};

static uint16_t skylanderCRC16(uint16_t init_value, const uint8_t* buffer, uint32_t size)
{
  static constexpr std::array<uint16_t, 256> CRC_CCITT_TABLE{
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

  for (uint32_t i = 0; i < size; i++)
  {
    const uint16_t tmp = (crc >> 8) ^ buffer[i];
    crc = (crc << 8) ^ CRC_CCITT_TABLE[tmp];
  }

  return crc;
}

bool CreateSkylander(const std::string& skylanderName, const std::string& targetDirectory, std::string genMode = "manual", const uint16_t customID = 0, const u_int16_t customVar = 0x0000) {
    
    std::string filePath;
    uint16_t SkyID = 0;
    uint16_t SkyVarID = 0;

    std::cout << "* Mode: " << genMode << std::endl;
    
    if (genMode == "manual") {
      //// Allows a user to create a skylander if they know the variant ID and skylander ID
      // Use a file name based on the provided IDs
      filePath = targetDirectory + "/" + std::to_string(customID) + "-" + std::to_string(customVar) + ".sky";
      // Set the IDs
      SkyID = customID;
      SkyVarID = customVar;
    }
    else {
      // Create the full file path for the .sky file
      filePath = targetDirectory + "/" + skylanderName + ".sky";

      // Lookup the Skylander data based on the given skylanderName
      bool isSensei = false;
      auto it = std::find_if(skylanderList.begin(), skylanderList.end(),
          [skylanderName](const std::pair<std::pair<uint16_t, uint16_t>, std::string>& entry) {
              return entry.second == skylanderName;
          });

      if (it != skylanderList.end()) {
          SkyID = it->first.first;
          SkyVarID = it->first.second;
      } else {

        // Check if provided skylander is from Imaginators
        auto it = std::find_if(senseiList.begin(), senseiList.end(),
          [skylanderName](const std::pair<std::pair<uint16_t, uint16_t>, std::string>& entry) {
              return entry.second == skylanderName;
          });
        if (it != senseiList.end()) {
          std::cerr << "* Warning: Sensei Skylanders don't work in-game, yet.\n* Creating Skylander anyway..." << std::endl;
          SkyID = it->first.first;
          SkyVarID = it->first.second;

          // may be useful for when Senseis get reverse-engineered
          isSensei = true;  
        }
        else {
          std::cerr << "! Error: Unknown Skylander." << std::endl
                    << "* Tip: if you know the ID and variant ID of the skylander" << std::endl
                    << "you are trying to create, use manual mode:" << std::endl
                    << "      skymake -m <ID> <Variant ID (Hexadecimal)> <Directory>" << std::endl;
          return false;
        }

      }
    }
    

    // Check if file already exists and warn the user about overwriting
    if (std::filesystem::exists(filePath)) {
      std::cerr << "* Warning: file " << filePath << " already exists!" << std::endl;
      std::cout << "* Overwriting..." << std::endl;
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
    for (uint32_t index = 1; index < 0x10; index++)
    {
      memcpy(&fileData[(index * 0x40) + 0x36], &otherBlocks, sizeof(otherBlocks));
    }
    
    // Set the NUID of the figure
    static thread_local entropySeededPRNG eSPRNG;
    eSPRNG.Generate(&fileData[0], 4);

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
    
    // Write the data to the .sky file
    skyFile.write(reinterpret_cast<const char*>(buf.data()), buf.size());
    skyFile.close();

    std::cout << "* Successfully wrote data to " << filePath << std::endl;
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage:  skymake <Skylander Name> <Directory>" << std::endl
                  << "        ---or---" << std::endl
                  << "        skymake -m <ID> <Variant ID (Hexadecimal)> <Directory>" << std::endl;
        return 1;
    }
    
    // if there is no -m, then just do the default behaviour
    if (strcmp(argv[1], "-m") == 0) {
      uint16_t ID = std::stoi(argv[2]);
      std::string varHexID = argv[3];
      std::string targetDirectory = argv[4];
      if (CreateSkylander("", targetDirectory, "manual", ID, (uint16_t)std::stoul(varHexID, nullptr, 0))) return 0;
      else return 1;
    }
    else {
      std::string skylanderName = argv[1];
      std::string targetDirectory = argv[2];
      if (CreateSkylander(skylanderName, targetDirectory, "auto")) return 0;
      else return 1;
    }
}
