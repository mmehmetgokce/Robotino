/**
 * @file ConnectionMenu.cpp
 * @author Yusuf Goc
 * @date December 2024
 * @brief Implementation file for the ConnectionMenu class.
 *
 * This file contains the definitions of the methods in the ConnectionMenu
 * class, which provide functionality for a menu to manage robot connections.
 */

#include "ConnectionMenu.h"

/**
 * @brief Constructs a ConnectionMenu instance.
 * @param ctrl Pointer to the RobotController instance used to manage the robot.
 */
ConnectionMenu::ConnectionMenu(RobotController* ctrl) : controller(ctrl) {}

/**
 * @brief Displays the connection menu.
 *
 * This method prints the options available in the connection menu to the console.
 */
void ConnectionMenu::display() {
    std::cout << "Connection Menu\n";
    std::cout << "1. Connect Robot\n";
    std::cout << "2. Disconnect Robot\n";
    std::cout << "3. Back\n";
    std::cout << "Choose one: ";
}

/**
 * @brief Handles the user's menu selection.
 *
 * This method processes the user's input and performs the corresponding action
 * based on the selected menu option.
 *
 * @details
 * - Option 1: Connects the robot using the RobotController instance.
 * - Option 2: Disconnects the robot using the RobotController instance.
 * - Option 3: Returns to the previous menu.
 * - Default: Displays an error message for invalid input.
 */
void ConnectionMenu::handleSelection() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            controller->connectRobot();
            std::cout << "Robot is connected.\n";
            break;
        case 2:
            controller->disconnectRobot();
            std::cout << "Robot is disconnected.\n";
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
    }
}
