#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * @class Record
 * @author Hayri Baran Vural (bgnvrl@gmail.com)
 * @date December 2024
 * @brief A class to handle file operations such as reading, writing, and managing file streams.
 */
class Record {
private:
    std::string fileName; ///< Name of the file to be managed.
    std::fstream file;    ///< File stream for handling file operations.

public:
    /**
     * @brief Constructs a Record object with an optional file name.
     * @param name Name of the file (default is an empty string).
     */
    Record(const std::string& name = "");

    /**
     * @brief Destructor that ensures the file is properly closed.
     */
    ~Record();

    /**
     * @brief Opens the file in read, write, and append mode.
     * @return True if the file is successfully opened, false otherwise.
     */
    bool openFile();

    /**
     * @brief Closes the file if it is open.
     * @return True if the file was successfully closed, false otherwise.
     */
    bool closeFile();

    /**
     * @brief Sets the file name for the Record object.
     * @param name The new file name.
     */
    void setFileName(const std::string& name);

    /**
     * @brief Reads a single line from the file.
     * @return The line read from the file, or an empty string if the read fails.
     */
    std::string readLine();

    /**
     * @brief Writes a single line to the file.
     * @param str The line to be written to the file.
     * @return True if the write operation is successful, false otherwise.
     */
    bool writeLine(const std::string& str);

    /**
     * @brief Overloads the << operator to write a line to the file.
     * @param str The line to be written to the file.
     * @return A reference to the Record object.
     */
    Record& operator<<(const std::string& str);

    /**
     * @brief Overloads the >> operator to read a line from the file.
     * @param str A reference to the string to store the read line.
     * @return A reference to the Record object.
     */
    Record& operator>>(std::string& str);
};

#endif // RECORD_H

