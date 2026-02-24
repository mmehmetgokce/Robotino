#ifndef FESTOROBOTSENSORINTERFACE_H
#define FESTOROBOTSENSORINTERFACE_H

#include "FestoRobotAPI.h"

/**
 * @file FestoRobotSensorInterface.h
 * @Author Muhammet Mehmet Gokce (gokcemehmet744@gmail.com)
 * @date December, 2024
 * @brief Abstract interface for interacting with the Festo robot sensors.
 *
 * This file defines the FestoRobotSensorInterface, an abstract class that provides
 * a structure for managing sensor data from the Festo robot.
 */

/**
 * @class FestoRobotSensorInterface
 * @brief Abstract class for handling Festo robot sensor data.
 *
 * This interface provides methods for updating and retrieving sensor data
 * from the FestoRobotAPI.
 */
class FestoRobotSensorInterface {
protected:
    FestoRobotAPI* robotAPI; ///< Pointer to the FestoRobotAPI instance for sensor operations.

public:
    /**
     * @brief Constructor for FestoRobotSensorInterface.
     * @param api Pointer to the FestoRobotAPI instance used for sensor operations.
     */
    FestoRobotSensorInterface(FestoRobotAPI* api) : robotAPI(api) {}

    /**
     * @brief Virtual destructor for FestoRobotSensorInterface.
     */
    virtual ~FestoRobotSensorInterface() {}

    /**
     * @brief Updates the sensor data.
     *
     * This method should be implemented to refresh the sensor readings
     * from the Festo robot.
     */
    virtual void update() = 0;

    /**
     * @brief Retrieves the range data from a specific sensor.
     * @param index The index of the sensor (0-based).
     * @return The range value of the specified sensor.
     */
    virtual double getRange(int index) const = 0;

    /**
     * @brief Overloads the [] operator to access sensor data.
     * @param index The index of the sensor (0-based).
     * @return The range value of the specified sensor.
     */
    virtual double operator[](int index) const = 0;

    /**
     * @brief Retrieves the value of a specific sensor.
     * @param index The index of the sensor (0-based).
     * @return The value of the specified sensor.
     */
    virtual double getSensorValue(int index) const = 0;
};

#endif // FESTOROBOTSENSORINTERFACE_H

