#ifndef CRC64_H
#define CRC64_H
#include <string>
#include <stdint.h>

/**
 * @brief Find the CRC-64 of a string.
 * @param str The string to hash.
 */
uint64_t crc64 (const std::string& str);


/**
 * @brief Extend a previously-calculated CRC to include an int.

 * @param crc The previously-calculated CRC.
 * @param x The integer to add.
 * @return The new CRC.
 */
uint64_t crc64addint (uint64_t crc, unsigned int x);


/**
 * @brief Format a CRC-64 as a string.
 * @param crc The CRC to format.
 */
std::string crc64format (uint64_t crc);


/**
 * @brief Return a CRC-64 digest of a string.
 * @param str The string to hash.
 * @return The CRC-64 digest of the string.
 *         This is the hash code, expressed as hex as a string.
 */
std::string crc64digest (const std::string& str);


#endif // CRC64_H
