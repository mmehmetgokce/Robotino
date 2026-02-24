#include "LidarSensor.h"
#include <cmath>

/*!
 * @brief Constructor for LidarSensor.
 * @param rangeNum Number of range values (sensor readings).
 *
 * Allocates dynamic memory for storing range values and initializes them to 0.0.
 */
LidarSensor::LidarSensor(int rangeNum) : rangeNumber(rangeNum) {
    ranges = new double[rangeNumber]; ///< Dynamic array allocation for sensor ranges
    for (int i = 0; i < rangeNumber; ++i) {
        ranges[i] = 0.0; ///< Initialize range values to 0.0
    }
}

/*!
 * @brief Destructor for LidarSensor.
 *
 * Releases the dynamically allocated memory for range values.
 */
LidarSensor::~LidarSensor() {
    delete[] ranges; ///< Free the allocated memory
}

/*!
 * @brief Updates the Lidar sensor data.
 *
 * Simulates retrieving sensor data by assigning example values.
 */
void LidarSensor::update() {
    std::cout << "Updating Lidar sensor values...\n";
    for (int i = 0; i < rangeNumber; ++i) {
        ranges[i] = static_cast<double>(i) * 1.5; ///< Assign example values to sensors
    }
}

/*!
 * @brief Retrieves the range value from a specific Lidar sensor.
 * @param index Index of the sensor (0-based).
 * @return The range value of the specified sensor.
 * @throws std::out_of_range if the index is outside the valid range.
 */
double LidarSensor::getRange(int index) const {
    if (index < 0 || index >= rangeNumber) {
        throw std::out_of_range("Index out of range for Lidar sensor.");
    }
    return ranges[index];
}

/*!
 * @brief Retrieves the maximum range value and its index.
 * @param index Reference to store the index of the maximum value.
 * @return The maximum range value.
 */
double LidarSensor::getMax(int& index) const {
    double maxVal = -std::numeric_limits<double>::infinity();
    for (int i = 0; i < rangeNumber; ++i) {
        if (ranges[i] > maxVal) {
            maxVal = ranges[i];
            index = i;
        }
    }
    return maxVal;
}

/*!
 * @brief Retrieves the minimum range value and its index.
 * @param index Reference to store the index of the minimum value.
 * @return The minimum range value.
 */
double LidarSensor::getMin(int& index) const {
    double minVal = std::numeric_limits<double>::infinity();
    for (int i = 0; i < rangeNumber; ++i) {
        if (ranges[i] < minVal) {
            minVal = ranges[i];
            index = i;
        }
    }
    return minVal;
}

/*!
 * @brief Overloads the [] operator to access Lidar sensor data.
 * @param index Index of the sensor (0-based).
 * @return The range value of the specified sensor.
 */
double LidarSensor::operator[](int index) const {
    return getRange(index);
}

/*!
 * @brief Calculates the angle of a specific Lidar sensor.
 * @param index Index of the sensor (0-based).
 * @return The angle of the specified sensor in degrees.
 * @throws std::out_of_range if the index is outside the valid range.
 */
double LidarSensor::getAngle(int index) const {
    if (index < 0 || index >= rangeNumber) {
        throw std::out_of_range("Index out of range for Lidar sensor angle.");
    }
    return (360.0 / rangeNumber) * index;
}

/*!
 * @brief Retrieves the value of a specific Lidar sensor.
 * @param index Index of the sensor (0-based).
 * @return The value of the specified sensor.
 */
double LidarSensor::getSensorValue(int index) const {
    return getRange(index);
}
