/**
 * @file Encryption.cpp
 * @brief Implementation file for the Encryption class.
 *
 * This file defines the methods for simple encryption and decryption
 * using XOR operations.
 */

#include "Encryption.h"

/**
 * @brief Encrypts a given integer value.
 * @param value The integer value to encrypt.
 * @return The encrypted integer.
 *
 * This method applies XOR encryption using the key 0xAAAA.
 */
int Encryption::encrypt(int value) {
    return value ^ 0xAAAA; // XOR operation for encryption
}

/**
 * @brief Decrypts a given integer value.
 * @param value The integer value to decrypt.
 * @return The decrypted integer.
 *
 * This method reverses the XOR encryption using the same key 0xAAAA.
 */
int Encryption::decrypt(int value) {
    return value ^ 0xAAAA; // XOR operation for decryption
}
