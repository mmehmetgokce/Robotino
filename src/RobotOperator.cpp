#include "RobotOperator.h"
#include <iostream>

/**
 * @brief Constructs a new RobotOperator object.
 *
 * @param surname The surname of the operator.
 * @param code The initial access code for the operator.
 * @param den The initial access state of the operator.
 */
RobotOperator::RobotOperator(const std::string& surname, unsigned int code, bool den)
    : surname(surname), accessCode(code), accessState(den) {
}

/**
 * @brief Encrypts the provided code.
 *
 * @param code The code to encrypt.
 * @return The encrypted code.
 */
int RobotOperator::encryptCode(int code) {
    Encryption enc;
    return enc.encrypt(code);
}

/**
 * @brief Decrypts the provided code.
 *
 * @param code The encrypted code to decrypt.
 * @return The decrypted code.
 */
int RobotOperator::decryptCode(int code) {
    Encryption enc;
    return enc.decrypt(code);
}

/**
 * @brief Validates the provided access code.
 *
 * @param code The access code to validate.
 * @return true if the provided code matches the decrypted access code, otherwise false.
 */
bool RobotOperator::checkAccessCode(int code) {
    int decryptedCode = decryptCode(accessCode);
    if (decryptedCode == code) {
        accessState = true;
        return true;
    }
    return false;
}

/**
 * @brief Prints the details of the operator.
 */
void RobotOperator::print() const {
    std::cout << "Surname: " << surname << "\n";
    std::cout << "Access State: " << (accessState ? "Active" : "Inactive") << "\n";
}
