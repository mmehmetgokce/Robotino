#include "SafeNavigation.h"
#include <iostream>

/**
 * @brief Constructs a new SafeNavigation object.
 *
 * @param ir Pointer to a SensorInterface object for obstacle detection.
 * @param ctrl Pointer to a RobotController object for controlling robot movement.
 */
SafeNavigation::SafeNavigation(SensorInterface* ir, RobotController* ctrl)
    : IR(ir), controller(ctrl), state(STOP) {
}

/**
 * @brief Safely moves the robot forward.
 *
 * Updates sensor data and checks the front sensor for obstacles.
 * If the distance to an obstacle is less than 5 meters, the robot stops.
 * Otherwise, the robot moves forward.
 */
void SafeNavigation::moveForwardSafe() {
    IR->update(); // Update sensor data
    if (IR->getSensorValue(0) < 5.0) { // If the front sensor detects an obstacle within 5 meters
        state = STOP;
        controller->stop();
        std::cout << "Obstacle detected! Stopping...\n";
    } else {
        state = MOVING;
        controller->moveForward();
        std::cout << "Moving forward safely...\n";
    }
}

/**
 * @brief Safely moves the robot backward.
 *
 * Updates sensor data and checks the rear sensor for obstacles.
 * If the distance to an obstacle is less than 5 meters, the robot stops.
 * Otherwise, the robot moves backward.
 */
void SafeNavigation::moveBackwardSafe() {
    IR->update(); // Update sensor data
    if (IR->getSensorValue(8) < 5.0) { // If the rear sensor detects an obstacle within 5 meters
        state = STOP;
        controller->stop();
        std::cout << "Obstacle detected! Stopping...\n";
    } else {
        state = MOVING;
        controller->moveBackward();
        std::cout << "Moving backward safely...\n";
    }
}
