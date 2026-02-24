/**
 * @file SensorMenu.h
 * @author Muhammet Mehmet Gokce (gokcemehmet744@gmail.com)
 * @date December, 2024
 * @brief Header file defining the SensorMenu class.
 *
 * This file contains the declaration of the SensorMenu class, which provides a menu interface
 * for interacting with the robot's sensors through a RobotController.
 */

#ifndef SENSORMENU_H
#define SENSORMENU_H

#include "Menu.h"
#include "RobotController.h"

/**
 * @class SensorMenu
 * @brief Represents a menu for managing robot sensors.
 *
 * This class allows users to update sensor data, display sensor readings,
 * and navigate back to the main menu.
 */
class SensorMenu : public Menu {
private:
    RobotController* controller; ///< Pointer to the robot controller.

public:
    /**
     * @brief Constructs a new SensorMenu object.
     *
     * @param ctrl Pointer to a RobotController object for sensor interactions.
     */
    SensorMenu(RobotController* ctrl);

    /**
     * @brief Displays the sensor menu options.
     */
    void display() override;

    /**
     * @brief Handles user selection in the sensor menu.
     *
     * Processes user input to either update sensors, display sensor data,
     * or navigate back to the main menu.
     */
    void handleSelection() override;
};

#endif // SENSORMENU_H

