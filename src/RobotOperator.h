/**
 * @file RobotOperator.h
 * @author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December, 2024
 * @brief Header file defining the RobotOperator class.
 *
 * This file contains the declaration of the RobotOperator class, which handles
 * operator-related functionalities such as encrypting, decrypting, and validating access codes.
 */

#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"

/**
 * @class RobotOperator
 * @brief Represents a robot operator with access control.
 *
 * This class provides methods for managing and verifying access codes
 * for robot operators.
 */
class RobotOperator {
private:
    std::string surname;         ///< Surname of the operator.
    unsigned int accessCode;     ///< Access code for authentication.
    bool accessState;            ///< Access state (true for active, false for inactive).

public:
    /**
     * @brief Constructs a new RobotOperator object.
     *
     * @param surname The surname of the operator.
     * @param code The initial access code for the operator.
     * @param den The initial access state of the operator.
     */
    RobotOperator(const std::string& surname, unsigned int code, bool den);

    /**
     * @brief Validates the provided access code.
     *
     * @param code The access code to validate.
     * @return true if the provided code matches the decrypted access code, otherwise false.
     */
    bool checkAccessCode(int code);

    /**
     * @brief Prints the details of the operator.
     */
    void print() const;

    /**
     * @brief Encrypts the provided code.
     *
     * @param code The code to encrypt.
     * @return The encrypted code.
     */
    int encryptCode(int code);

    /**
     * @brief Decrypts the provided code.
     *
     * @param code The encrypted code to decrypt.
     * @return The decrypted code.
     */
    int decryptCode(int code);
};

#endif // ROBOTOPERATOR_H
