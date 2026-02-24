#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <list>
#include "SensorInterface.h"
#include "RobotInterface.h"
#include "RobotOperator.h"
#include "Pose.h"

/**
 * @file RobotController.h
 * @author Yusuf Goc (yusufsalih987@gmail.com)
 * @date December 2024
 * @brief Manages the operations of a robot, including movement, sensor updates, and access control.
 */
class RobotController {
private:
    std::list<SensorInterface*> sensorList; ///< List of sensors attached to the robot.
    RobotInterface* robot;                  ///< Pointer to the robot interface for controlling the robot.
    RobotOperator robotOperator;            ///< Object managing robot operator access.

public:
    /**
     * @brief Constructs a RobotController object with a robot and operator details.
     * @param robot A pointer to the RobotInterface object controlling the robot.
     * @param operatorInfo The RobotOperator object for managing access control.
     */
    RobotController(RobotInterface* robot, const RobotOperator& operatorInfo);

    // Movement methods
    void turnLeft();   ///< Turns the robot to the left.
    void turnRight();  ///< Turns the robot to the right.
    void moveForward(); ///< Moves the robot forward.
    void moveBackward(); ///< Moves the robot backward.
    void moveLeft();   ///< Moves the robot to the left.
    void moveRight();  ///< Moves the robot to the right.
    void stop();       ///< Stops all robot movements.

    // Robot status methods
    Pose getPose() const; ///< Gets the current pose of the robot.
    void print() const;   ///< Prints the robot's details.

    // Robot connection methods
    bool connectRobot();    ///< Establishes a connection with the robot.
    bool disconnectRobot(); ///< Terminates the connection with the robot.

    // Sensor management methods
    void addSensor(SensorInterface* sensor); ///< Adds a sensor to the robot's sensor list.
    void updateSensors(); ///< Updates all sensors attached to the robot.

    // Access management methods
    bool openAccess(int code); ///< Opens access to the robot with the specified access code.
    bool closeAccess(int code); ///< Closes access to the robot with the specified access code.
};

#endif // ROBOTCONTROLLER_H

