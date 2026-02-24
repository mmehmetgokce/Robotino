#include "RobotController.h"
#include <iostream>
#include "FestoRobotAPI.h"

FestoRobotAPI* robotino;

/**
 * @brief Turns the robot to the left for a predefined duration.
 * The robot will stop automatically after completing the turn.
 */
void RobotController::turnLeft() {
    robot->turnLeft();
    Sleep(540); // Wait for 540 milliseconds
    robotino->stop();
    std::cout << "Robot turning left.\n";
}

/**
 * @brief Turns the robot to the right for a predefined duration.
 * The robot will stop automatically after completing the turn.
 */
void RobotController::turnRight() {
    robot->turnRight();
    Sleep(540); // Wait for 540 milliseconds
    robotino->stop();
    std::cout << "Robot turning right.\n";
}

/**
 * @brief Moves the robot forward for a predefined duration.
 * The robot will stop automatically after completing the movement.
 */
void RobotController::moveForward() {
    robot->moveForward();
    Sleep(2000); // Wait for 2 seconds
    robotino->stop();
    std::cout << "Robot moving forward.\n";
}

/**
 * @brief Moves the robot backward for a predefined duration.
 * The robot will stop automatically after completing the movement.
 */
void RobotController::moveBackward() {
    robot->moveBackward();
    Sleep(2000); // Wait for 2 seconds
    robotino->stop();
    std::cout << "Robot moving backward.\n";
}

/**
 * @brief Moves the robot to the left for a predefined duration.
 * The robot will stop automatically after completing the movement.
 */
void RobotController::moveLeft() {
    robot->moveLeft();
    Sleep(550); // Wait for 550 milliseconds
    robotino->stop();
    std::cout << "Robot moving left.\n";
}

/**
 * @brief Moves the robot to the right for a predefined duration.
 * The robot will stop automatically after completing the movement.
 */
void RobotController::moveRight() {
    robot->moveRight();
    Sleep(550); // Wait for 550 milliseconds
    robotino->stop();
    std::cout << "Robot moving right.\n";
}

/**
 * @brief Stops all movements of the robot immediately.
 */
void RobotController::stop() {
    robot->stop();
    std::cout << "Robot stopped.\n";
}

/**
 * @brief Retrieves the current position and orientation (pose) of the robot.
 * @return A Pose object representing the robot's current position and orientation.
 */
Pose RobotController::getPose() const {
    return robot->getPose();
}

/**
 * @brief Prints the current status and details of the robot.
 */
void RobotController::print() const {
    robot->print();
}

/**
 * @brief Establishes a connection with the robot.
 * @return True if the connection is successfully established, false otherwise.
 */
bool RobotController::connectRobot() {
    if (robot->connectRobot()) {
        std::cout << "Robot connected successfully.\n";
        return true;
    }
    std::cout << "Failed to connect robot.\n";
    return false;
}

/**
 * @brief Terminates the connection with the robot.
 * @return True if the connection is successfully terminated, false otherwise.
 */
bool RobotController::disconnectRobot() {
    if (robot->disconnectRobot()) {
        std::cout << "Robot disconnected successfully.\n";
        return true;
    }
    std::cout << "Failed to disconnect robot.\n";
    return false;
}

/**
 * @brief Adds a sensor to the robot's sensor list for monitoring or control purposes.
 * @param sensor A pointer to the SensorInterface object representing the sensor to be added.
 */
void RobotController::addSensor(SensorInterface* sensor) {
    sensorList.push_back(sensor);
    std::cout << "Sensor added.\n";
}

/**
 * @brief Updates all sensors in the robot's sensor list to retrieve the latest data.
 */
void RobotController::updateSensors() {
    for (SensorInterface* sensor : sensorList) {
        sensor->update();
    }
    std::cout << "All sensors updated.\n";
}

/**
 * @brief Opens access to the robot's controls based on an access code.
 * @param code The access code to be verified.
 * @return True if the access code is valid and access is granted, false otherwise.
 */
bool RobotController::openAccess(int code) {
    if (robotOperator.checkAccessCode(code)) {
        std::cout << "Access granted.\n";
        return true;
    }
    std::cout << "Access denied.\n";
    return false;
}

/**
 * @brief Closes access to the robot's controls based on an access code.
 * @param code The access code to be verified.
 * @return True if the access code is valid and access is successfully closed, false otherwise.
 */
bool RobotController::closeAccess(int code) {
    if (robotOperator.checkAccessCode(code)) {
        std::cout << "Access closed.\n";
        return true;
    }
    std::cout << "Failed to close access.\n";
    return false;
}
