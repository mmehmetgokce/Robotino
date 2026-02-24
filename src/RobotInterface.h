#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include "Pose.h"

/**
 * @class RobotInterface
 * @author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December 2024
 * @brief An abstract base class defining the interface for controlling a robot.
 */
class RobotInterface {
protected:
    Pose* position;          ///< Pointer to a Pose object representing the robot's current position and orientation.
    bool connectionStatus;   ///< Boolean indicating the connection status of the robot.

public:
    /**
     * @brief Virtual destructor for the RobotInterface class.
     * Ensures proper cleanup of derived class resources.
     */
    virtual ~RobotInterface() {}

    /**
     * @brief Turns the robot to the left.
     * This function must be implemented by derived classes.
     */
    virtual void turnLeft() = 0;

    /**
     * @brief Turns the robot to the right.
     * This function must be implemented by derived classes.
     */
    virtual void turnRight() = 0;

    /**
     * @brief Moves the robot forward.
     * This function must be implemented by derived classes.
     */
    virtual void moveForward() = 0;

    /**
     * @brief Moves the robot backward.
     * This function must be implemented by derived classes.
     */
    virtual void moveBackward() = 0;

    /**
     * @brief Moves the robot to the left.
     * This function must be implemented by derived classes.
     */
    virtual void moveLeft() = 0;

    /**
     * @brief Moves the robot to the right.
     * This function must be implemented by derived classes.
     */
    virtual void moveRight() = 0;

    /**
     * @brief Stops all movements of the robot.
     * This function must be implemented by derived classes.
     */
    virtual void stop() = 0;

    /**
     * @brief Retrieves the current position and orientation (pose) of the robot.
     * @return A Pose object representing the robot's current position and orientation.
     * This function must be implemented by derived classes.
     */
    virtual Pose getPose() const = 0;

    /**
     * @brief Prints the robot's details, such as position and status.
     * This function must be implemented by derived classes.
     */
    virtual void print() const = 0;

    /**
     * @brief Establishes a connection with the robot.
     * @return True if the connection is successfully established, false otherwise.
     * This function must be implemented by derived classes.
     */
    virtual bool connectRobot() = 0;

    /**
     * @brief Terminates the connection with the robot.
     * @return True if the connection is successfully terminated, false otherwise.
     * This function must be implemented by derived classes.
     */
    virtual bool disconnectRobot() = 0;
};

#endif // ROBOTINTERFACE_H

