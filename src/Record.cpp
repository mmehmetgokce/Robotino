#include "Record.h"

/**
 * @brief Constructs a Record object with the specified file name.
 * @param name Name of the file to be associated with the Record object.
 */
Record::Record(const std::string& name) : fileName(name) {}

/**
 * @brief Destructor for the Record object.
 * Ensures the file is closed before the object is destroyed.
 */
Record::~Record() {
    if (file.is_open()) {
        file.close();
    }
}

/**
 * @brief Opens the file in read, write, and append mode.
 * @return True if the file is successfully opened, false otherwise.
 */
bool Record::openFile() {
    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief Closes the file if it is open.
 * @return True if the file was successfully closed, false otherwise.
 */
bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

/**
 * @brief Sets the name of the file to be associated with the Record object.
 * @param name The new file name.
 */
void Record::setFileName(const std::string& name) {
    fileName = name;
}

/**
 * @brief Reads a single line from the file.
 * @return The line read from the file, or an empty string if the read fails.
 */
std::string Record::readLine() {
    std::string line;
    if (file.is_open() && std::getline(file, line)) {
        return line;
    }
    return "";
}

/**
 * @brief Writes a single line to the file.
 * @param str The line to be written to the file.
 * @return True if the write operation is successful, false otherwise.
 */
bool Record::writeLine(const std::string& str) {
    if (file.is_open()) {
        file << str << std::endl;
        return true;
    }
    return false;
}

/**
 * @brief Overloads the << operator to write a line to the file.
 * @param str The line to be written to the file.
 * @return A reference to the Record object.
 */
Record& Record::operator<<(const std::string& str) {
    writeLine(str);
    return *this;
}

/**
 * @brief Overloads the >> operator to read a line from the file.
 * @param str A reference to the string to store the read line.
 * @return A reference to the Record object.
 */
Record& Record::operator>>(std::string& str) {
    str = readLine();
    return *this;
}
