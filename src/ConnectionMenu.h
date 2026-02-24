/**
 * @file ConnectionMenu.h
 * @author Yusuf Goc (yusufsalih987@gmail.com)
 * @date December 2024
 * @brief Header file for the ConnectionMenu class.
 *
 * This file declares the ConnectionMenu class, which is responsible
 * for displaying a connection menu and handling user input to manage
 * robot connections.
 */

#ifndef CONNECTIONMENU_H
#define CONNECTIONMENU_H

#include "RobotController.h"
#include <iostream>

/**
 * @class ConnectionMenu
 * @brief Provides a menu interface for managing robot connections.
 */
class ConnectionMenu {
public:
    /**
     * @brief Constructor for ConnectionMenu.
     * @param ctrl Pointer to the RobotController instance used to manage the robot.
     */
    ConnectionMenu(RobotController* ctrl);

    /**
     * @brief Displays the connection menu.
     */
    void display();

    /**
     * @brief Handles the user's menu selection.
     */
    void handleSelection();

private:
    RobotController* controller; /**< Pointer to the RobotController instance. */
};

#endif // CONNECTIONMENU_H

