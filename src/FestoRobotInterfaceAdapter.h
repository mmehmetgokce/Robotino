#ifndef FESTOROBOTINTERFACEADAPTER_H
#define FESTOROBOTINTERFACEADAPTER_H

#include "RobotInterface.h"
#include "FestoRobotAPI.h"

/**
 * @file FestoRobotInterfaceAdapter.h
 * @Author Emirhan Ünal (emirhan_60unal@hotmail.com)
 * @date December, 2024
 * @brief Adapter class to interface with the Festo robot using the RobotInterface.
 *
 * This file defines the FestoRobotInterfaceAdapter class, which adapts the
 * FestoRobotAPI to conform to the RobotInterface.
 */

/**
 * @class FestoRobotInterfaceAdapter
 * @brief Adapter class to connect the FestoRobotAPI with the RobotInterface.
 *
 * This class implements the RobotInterface functions by utilizing the
 * functionalities provided by FestoRobotAPI.
 */
class FestoRobotInterfaceAdapter : public RobotInterface {
private:
    FestoRobotAPI* api; ///< Pointer to the FestoRobotAPI instance.

public:
    /**
     * @brief Constructor for FestoRobotInterfaceAdapter.
     * @param api Pointer to the FestoRobotAPI instance to be adapted.
     */
    explicit FestoRobotInterfaceAdapter(FestoRobotAPI* api) : api(api) {}

    /**
     * @brief Turns the robot left.
     */
    void turnLeft() override { api->rotate(LEFT); }

    /**
     * @brief Turns the robot right.
     */
    void turnRight() override { api->rotate(RIGHT); }

    /**
     * @brief Moves the robot forward.
     */
    void moveForward() override { api->move(FORWARD); }

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward() override { api->move(BACKWARD); }

    /**
     * @brief Moves the robot to the left.
     */
    void moveLeft() override { api->move(LEFT); }

    /**
     * @brief Moves the robot to the right.
     */
    void moveRight() override { api->move(RIGHT); }

    /**
     * @brief Stops the robot's movement.
     */
    void stop() override { api->stop(); }

    /**
     * @brief Retrieves the robot's current pose.
     * @return A Pose object containing the robot's position and heading angle.
     */
    Pose getPose() const override {
        double x, y, th;
        api->getXYTh(x, y, th);
        return Pose(x, y, th);
    }

    /**
     * @brief Prints the robot's current pose to the console.
     */
    void print() const override {
        Pose pose = getPose();
        std::cout << "X: " << pose.getX() << ", Y: " << pose.getY() << ", Th: " << pose.getTh() << std::endl;
    }

    /**
     * @brief Connects the robot to the simulator.
     * @return True if the connection is successful.
     */
    bool connectRobot() override { api->connect(); return true; }

    /**
     * @brief Disconnects the robot from the simulator.
     * @return True if the disconnection is successful.
     */
    bool disconnectRobot() override { api->disconnect(); return true; }
};

#endif // FESTOROBOTINTERFACEADAPTER_H

