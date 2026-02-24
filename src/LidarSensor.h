
#ifndef LIDARSENSOR_H
#define LIDARSENSOR_H

/**
 * @file LidarSensor.h
 * @Author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December, 2024
 * @brief Class for managing Lidar sensor data.
 *
 * This file defines the LidarSensor class, which provides methods for
 * updating, retrieving, and processing Lidar sensor data.
 */

/**
 * @class LidarSensor
 * @brief A class to handle operations for Lidar sensors.
 *
 * The LidarSensor class manages an array of range values for a Lidar sensor,
 * providing methods to update and access these values as well as compute angles.
 */
class LidarSensor {
private:
    double* ranges;       ///< Dynamically allocated array for sensor range values.
    int rangeNumber;      ///< Number of sensors (or range values).

public:
    /**
     * @brief Constructor for LidarSensor.
     * @param rangeNum Number of range values (sensor readings).
     */
    LidarSensor(int rangeNum);

    /**
     * @brief Destructor for LidarSensor.
     *
     * Releases the dynamically allocated memory for range values.
     */
    ~LidarSensor();

    /**
     * @brief Updates the Lidar sensor data.
     *
     * This function refreshes the sensor values.
     */
    void update();

    /**
     * @brief Retrieves the range value from a specific Lidar sensor.
     * @param index The index of the sensor (0-based).
     * @return The range value of the specified sensor.
     * @throws std::out_of_range if the index is outside the valid range.
     */
    double getRange(int index) const;

    /**
     * @brief Retrieves the maximum range value and its index.
     * @param index Reference to store the index of the maximum value.
     * @return The maximum range value.
     */
    double getMax(int& index) const;

    /**
     * @brief Retrieves the minimum range value and its index.
     * @param index Reference to store the index of the minimum value.
     * @return The minimum range value.
     */
    double getMin(int& index) const;

    /**
     * @brief Overloads the [] operator to access Lidar sensor data.
     * @param index Index of the sensor (0-based).
     * @return The range value of the specified sensor.
     */
    double operator[](int index) const;

    /**
     * @brief Calculates the angle of a specific Lidar sensor.
     * @param index The index of the sensor (0-based).
     * @return The angle of the specified sensor in degrees.
     * @throws std::out_of_range if the index is outside the valid range.
     */
    double getAngle(int index) const;

    /**
     * @brief Retrieves the value of a specific Lidar sensor.
     * @param index The index of the sensor (0-based).
     * @return The value of the specified sensor.
     */
    double getSensorValue(int index) const;
};

#endif // LIDARSENSOR_H
