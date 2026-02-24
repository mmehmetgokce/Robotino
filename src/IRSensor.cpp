#include "IRSensor.h"

/*!
 * @brief Constructor for IRSensor.
 *
 * Initializes all IR sensor range values to 0.0.
 */
IRSensor::IRSensor() {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = 0.0; ///< Initialize sensor values to 0.0
    }
}

/*!
 * @brief Updates the IR sensor data.
 *
 * Simulates the retrieval of sensor data by assigning example values.
 */
void IRSensor::update() {
    std::cout << "Updating IR sensor values...\n";
    for (int i = 0; i < 9; ++i) {
        ranges[i] = static_cast<double>(i) * 2.5; ///< Assign example values to sensors
    }
}

/*!
 * @brief Retrieves the range value from a specific IR sensor.
 * @param index The index of the sensor (0-based, 0-8).
 * @return The range value of the specified sensor.
 * @throws std::out_of_range if the index is outside the valid range.
 */
double IRSensor::getRange(int index) const {
    if (index < 0 || index >= 9) {
        throw std::out_of_range("Index out of range for IR sensor.");
    }
    return ranges[index];
}

/*!
 * @brief Overloads the [] operator to access IR sensor data.
 * @param index The index of the sensor (0-based, 0-8).
 * @return The range value of the specified sensor.
 */
double IRSensor::operator[](int index) const {
    return getRange(index);
}

/*!
 * @brief Retrieves the value of a specific IR sensor.
 * @param index The index of the sensor (0-based, 0-8).
 * @return The range value of the specified sensor.
 */
double IRSensor::getSensorValue(int index) const {
    return getRange(index);
}
