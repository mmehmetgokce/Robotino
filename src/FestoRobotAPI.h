#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <windows.h>

/**
 * @file FestoRobotAPI.h
 * @date December, 2024
 * @brief Header file for controlling the Festo robot simulator.
 *
 * This file contains the class and function definitions to interact with
 * the Festo robot in a simulated environment. It provides methods for
 * connecting, moving, rotating, stopping, and retrieving sensor data from the robot.
 */

enum DIRECTION {
    FORWARD = 0, ///< Moves the robot forward.
    BACKWARD,    ///< Moves the robot backward.
    LEFT,        ///< Rotates or moves the robot left.
    RIGHT        ///< Rotates or moves the robot right.
};

using namespace std;

/**
 * @class FestoRobotAPI
 * @brief Class to interface with the Festo robot simulator.
 *
 * Provides functionalities for controlling the robot's movement and
 * retrieving its sensor data.
 */
class FestoRobotAPI {
public:
    /**
     * @brief Constructor for FestoRobotAPI.
     *
     * Initializes the API for controlling the robot simulator.
     */
    FestoRobotAPI();

    /**
     * @brief Connect to the robot simulator.
     */
    void connect();

    /**
     * @brief Disconnect from the robot simulator.
     */
    void disconnect();

    /**
     * @brief Move the robot in the specified direction.
     * @param direction The direction to move the robot. Possible values are {FORWARD, BACKWARD, LEFT, RIGHT}.
     */
    void move(DIRECTION direction);

    /**
     * @brief Rotate the robot in the specified direction.
     * @param direction The direction to rotate the robot. Possible values are {LEFT, RIGHT}.
     */
    void rotate(DIRECTION direction);

    /**
     * @brief Stop the robot's movement.
     */
    void stop();

    /**
     * @brief Get the range from an infrared sensor.
     * @param i The index of the sensor (0-8).
     * @return The distance measured by the sensor in meters.
     */
    double getIRRange(int i);

    /**
     * @brief Get the current coordinates and heading angle of the robot.
     * @param X Reference to store the x-coordinate of the robot.
     * @param Y Reference to store the y-coordinate of the robot.
     * @param TH Reference to store the heading angle of the robot in degrees.
     */
    void getXYTh(double& X, double& Y, double& TH);

    /**
     * @brief Retrieve the LIDAR range data.
     * @param ranges Pointer to an array to store the LIDAR range data.
     */
    void getLidarRange(float* ranges);

    /**
     * @brief Get the number of LIDAR range data points.
     * @return The number of LIDAR range data points.
     */
    int getLidarRangeNumber() const;
};
