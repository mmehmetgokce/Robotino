/**
 * @file SensorInterface.h
 * @author Hayri Baran Vural (bgnvrl@gmail.com)
 * @date December, 2024
 * @brief Header file defining the SensorInterface class.
 *
 * This file contains the declaration of the SensorInterface abstract class,
 * which serves as a base class for various sensor implementations.
 */

#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

/**
 * @class SensorInterface
 * @brief Abstract base class for sensors.
 *
 * Provides a common interface for sensors, including methods for updating sensor data,
 * retrieving sensor types, and obtaining sensor values.
 */
class SensorInterface {
protected:
    std::string sensorType; ///< Type of the sensor.

public:
    /**
     * @brief Constructs a SensorInterface object with the given sensor type.
     *
     * @param type The type of the sensor.
     */
    SensorInterface(const std::string& type) : sensorType(type) {}

    /**
     * @brief Virtual destructor for SensorInterface.
     */
    virtual ~SensorInterface() {}

    /**
     * @brief Updates the sensor data.
     *
     * This method must be implemented by derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Retrieves the type of the sensor.
     *
     * @return A string representing the sensor type.
     */
    virtual std::string getSensorType() const { return sensorType; }

    /**
     * @brief Retrieves the value of a specific sensor.
     *
     * This method must be implemented by derived classes.
     *
     * @param index The index of the sensor value to retrieve.
     * @return The value of the sensor at the specified index.
     */
    virtual double getSensorValue(int index) const = 0;
};

#endif // SENSORINTERFACE_H
