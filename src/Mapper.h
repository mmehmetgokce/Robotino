#ifndef MAPPER_H
#define MAPPER_H

#include "MAP.h"
#include "RobotController.h"
#include "SensorInterface.h"

/**
 * @class Mapper
 * @brief Handles the mapping functionality of a robot system.
 * @author Muhammet Mehmet Gokce (gokcemehmet744@gmail.com)
 * @date December 2024
 * The Mapper class integrates sensor data and robot control mechanisms to
 * create, update, and display a map of the environment.
 */
class Mapper {
private:
    MAP map;                     ///< Map representation.
    RobotController* controller; ///< Pointer to the robot controller.
    SensorInterface* lidar;      ///< Pointer to the lidar sensor.

public:
    /**
     * @brief Constructor for the Mapper class.
     * @param ctrl Pointer to a RobotController instance.
     * @param sensor Pointer to a SensorInterface instance.
     *
     * Initializes the mapper with a default map size and links it to the robot
     * controller and sensor interfaces.
     */
    Mapper(RobotController* ctrl, SensorInterface* sensor)
        : controller(ctrl), lidar(sensor), map(10, 10, 1.0) {
    }

    /**
     * @brief Updates the map using data from connected sensors.
     */
    void updateMap();

    /**
     * @brief Records the current state of the map.
     * @return True if the map recording was successful.
     */
    bool recordMap();

    /**
     * @brief Displays the current map on the console.
     */
    void showMap();
};

#endif // MAPPER_H
