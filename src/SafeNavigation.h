/**
 * @file SafeNavigation.h
 * @author Yusuf Goc (yusufsalih987@gmail.com)
 * @date December, 2024
 * @brief Header file defining the SafeNavigation class.
 *
 * This file contains the declaration of the SafeNavigation class, which ensures
 * safe navigation of a robot by integrating sensor data and a robot controller.
 */

#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H

#include "SensorInterface.h"
#include "RobotController.h"

/**
 * @enum MOVESTATE
 * @brief Represents the movement state of the robot.
 */
enum MOVESTATE {
    MOVING, ///< Robot is moving.
    STOP    ///< Robot is stopped.
};

/**
 * @class SafeNavigation
 * @brief Ensures safe navigation for a robot using sensor data and a controller.
 *
 * This class manages safe forward and backward movements by utilizing
 * sensor inputs to detect obstacles and controlling the robot's actions accordingly.
 */
class SafeNavigation {
private:
    SensorInterface* IR;            ///< Pointer to the sensor interface.
    RobotController* controller;    ///< Pointer to the robot controller.
    MOVESTATE state;                ///< Movement state of the robot.

public:
    /**
     * @brief Constructs a new SafeNavigation object.
     *
     * @param ir Pointer to a SensorInterface object for obstacle detection.
     * @param ctrl Pointer to a RobotController object for controlling robot movement.
     */
    SafeNavigation(SensorInterface* ir, RobotController* ctrl);

    /**
     * @brief Safely moves the robot forward.
     *
     * Checks the front sensors for obstacles before moving the robot forward.
     * Stops the robot if an obstacle is detected within 5 meters.
     */
    void moveForwardSafe();

    /**
     * @brief Safely moves the robot backward.
     *
     * Checks the rear sensors for obstacles before moving the robot backward.
     * Stops the robot if an obstacle is detected within 5 meters.
     */
    void moveBackwardSafe();
};

#endif // SAFENAVIGATION_H
