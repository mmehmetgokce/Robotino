/**
 * @file FestoRobotInterface.h
 * @author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December 2024
 * @brief Header file for the FestoRobotInterface class.
 *
 * This file declares the FestoRobotInterface class, which provides an interface
 * for controlling a Festo robot using the FestoRobotAPI.
 */

#ifndef FESTOROBOTINTERFACE_H
#define FESTOROBOTINTERFACE_H

#include "FestoRobotAPI.h"
#include "Pose.h"

/**
 * @class FestoRobotInterface
 * @brief Provides an interface for controlling a Festo robot.
 */
class FestoRobotInterface {
private:
    FestoRobotAPI* robotAPI; /**< Pointer to the Festo robot API instance. */

public:
    /**
     * @brief Constructs a FestoRobotInterface instance.
     * @param api Pointer to the FestoRobotAPI instance used to interact with the robot.
     */
    FestoRobotInterface(FestoRobotAPI* api);

    /**
     * @brief Rotates the robot to the left.
     */
    void turnLeft();

    /**
     * @brief Rotates the robot to the right.
     */
    void turnRight();

    /**
     * @brief Moves the robot forward.
     */
    void moveForward();

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward();

    /**
     * @brief Moves the robot to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the robot to the right.
     */
    void moveRight();

    /**
     * @brief Stops the robot's motion.
     */
    void stop();

    /**
     * @brief Retrieves the current pose of the robot.
     * @return The current pose as a Pose object.
     */
    Pose getPose() const;

    /**
     * @brief Prints the robot's current position and orientation.
     */
    void print() const;

    /**
     * @brief Connects to the robot.
     * @return True if the connection is successful, false otherwise.
     */
    bool connectRobot();

    /**
     * @brief Disconnects from the robot.
     * @return True if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot();
};

#endif // FESTOROBOTINTERFACE_H
