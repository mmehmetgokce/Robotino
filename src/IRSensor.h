#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <iostream>
#include <stdexcept>
#include "SensorInterface.h"

/**
 * @file IRSensor.h
 * @Author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December, 2024
 * @brief Class for managing IR sensor data.
 *
 * This file defines the IRSensor class, which provides methods for updating
 * and retrieving infrared sensor data.
 */

/**
 * @class IRSensor
 * @brief A class to handle operations for IR sensors.
 *
 * The IRSensor class manages an array of 9 IR sensor values, providing
 * methods to update and access these values.
 */
class IRSensor {
private:
    double ranges[9]; ///< Array to store IR sensor range values.

public:
    /**
     * @brief Default constructor for IRSensor.
     *
     * Initializes all IR sensor range values to 0.0.
     */
    IRSensor();

    /**
     * @brief Parameterized constructor for IRSensor.
     * @param type A string indicating the type of the sensor.
     */
    IRSensor(std::string type);

    /**
     * @brief Updates the IR sensor data.
     *
     * This function refreshes the sensor values.
     */
    void update();

    /**
     * @brief Retrieves the range value from a specific IR sensor.
     * @param index The index of the sensor (0-based, 0-8).
     * @return The range value of the specified sensor.
     * @throws std::out_of_range if the index is outside the valid range.
     */
    double getRange(int index) const;

    /**
     * @brief Overloads the [] operator to access IR sensor data.
     * @param index The index of the sensor (0-based, 0-8).
     * @return The range value of the specified sensor.
     */
    double operator[](int index) const;

    /**
     * @brief Retrieves the value of a specific IR sensor.
     * @param index The index of the sensor (0-based, 0-8).
     * @return The range value of the specified sensor.
     */
    double getSensorValue(int index) const;
};

#endif // IRSENSOR_H

