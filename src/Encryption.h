/**
 * @file Encryption.h
 * @author Hayri Baran Vural (bgnvrl@gmail.com)
 * @date December 2024
 * @brief Header file for the Encryption class.
 *
 * This file declares the Encryption class, which provides simple encryption
 * and decryption methods using XOR operations.
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

/**
 * @class Encryption
 * @brief Provides methods for simple encryption and decryption.
 */
class Encryption {
public:
    /**
     * @brief Encrypts a given integer value.
     * @param value The integer value to encrypt.
     * @return The encrypted integer.
     *
     * This method applies a simple XOR encryption using a predefined key.
     */
    int encrypt(int value);

    /**
     * @brief Decrypts a given integer value.
     * @param value The integer value to decrypt.
     * @return The decrypted integer.
     *
     * This method reverses the XOR encryption using the same predefined key.
     */
    int decrypt(int value);
};

#endif // ENCRYPTION_H
