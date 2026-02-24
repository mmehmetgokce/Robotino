/**
 * @file FestoRobotInterface.cpp
 * @author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December 2024
 * @brief Implementation file for the FestoRobotInterface class.
 *
 * This file defines the methods of the FestoRobotInterface class,
 * providing functionalities to control a Festo robot.
 */

#include "FestoRobotInterface.h"
#include <iostream>

/**
 * @brief Constructs a FestoRobotInterface instance.
 * @param api Pointer to the FestoRobotAPI instance used to interact with the robot.
 */
FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* api) : robotAPI(api) {}

/**
 * @brief Rotates the robot to the left.
 */
void FestoRobotInterface::turnLeft() {
    robotAPI->rotate(LEFT);
    std::cout << "Robot turning left.\n";
}

/**
 * @brief Rotates the robot to the right.
 */
void FestoRobotInterface::turnRight() {
    robotAPI->rotate(RIGHT);
    std::cout << "Robot turning right.\n";
}

/**
 * @brief Moves the robot forward.
 */
void FestoRobotInterface::moveForward() {
    robotAPI->move(FORWARD);
    std::cout << "Robot moving forward.\n";
}

/**
 * @brief Moves the robot backward.
 */
void FestoRobotInterface::moveBackward() {
    robotAPI->move(BACKWARD);
    std::cout << "Robot moving backward.\n";
}

/**
 * @brief Moves the robot to the left.
 */
void FestoRobotInterface::moveLeft() {
    robotAPI->move(LEFT);
    std::cout << "Robot moving left.\n";
}

/**
 * @brief Moves the robot to the right.
 */
void FestoRobotInterface::moveRight() {
    robotAPI->move(RIGHT);
    std::cout << "Robot moving right.\n";
}

/**
 * @brief Stops the robot's motion.
 */
void FestoRobotInterface::stop() {
    robotAPI->stop();
    std::cout << "Robot stopped.\n";
}

/**
 * @brief Retrieves the current pose of the robot.
 * @return The current pose as a Pose object.
 */
Pose FestoRobotInterface::getPose() const {
    double x, y, th;
    robotAPI->getXYTh(x, y, th);
    return Pose(x, y, th);
}

/**
 * @brief Prints the robot's current position and orientation.
 */
void FestoRobotInterface::print() const {
    Pose pose = getPose();
    std::cout << "Robot Position:\n"
              << "X: " << pose.getX() << "\n"
              << "Y: " << pose.getY() << "\n"
              << "Theta: " << pose.getTh() << " radians\n";
}

/**
 * @brief Connects to the robot.
 * @return True if the connection is successful, false otherwise.
 */
bool FestoRobotInterface::connectRobot() {
    robotAPI->connect();
    std::cout << "Robot connected.\n";
    return true;
}

/**
 * @brief Disconnects from the robot.
 * @return True if the disconnection is successful, false otherwise.
 */
bool FestoRobotInterface::disconnectRobot() {
    robotAPI->disconnect();
    std::cout << "Robot disconnected.\n";
    return true;
}
