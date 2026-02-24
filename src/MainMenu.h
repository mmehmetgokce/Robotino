#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "ConnectionMenu.h"
#include "MotionMenu.h"
#include "SensorMenu.h"

/**
 * @file MainMenu.h
 * @author Yusuf Goc (yusufsalih987@gmail.com)
 * @date December 2024
 * @brief Main menu interface for the application.
 *
 * The MainMenu class provides an interface for the user to interact with the
 * application, offering options to navigate to Connection, Motion, or Sensor menus,
 * or to quit the program.
 */

/**
 * @class MainMenu
 * @brief A class representing the main menu of the application.
 *
 * The MainMenu class handles displaying the main menu options and processing
 * user selections, which may involve transitioning to submenus or exiting the application.
 */
class MainMenu {
private:
    Controller& controller; ///< Reference to the main Controller object.

public:
    /**
     * @brief Constructor for MainMenu.
     * @param ctrl Reference to the Controller object.
     */
    explicit MainMenu(Controller& ctrl) : controller(ctrl) {}

    /**
     * @brief Displays the main menu options.
     *
     * This method prints the menu options to the console for the user to choose from.
     */
    void display();

    /**
     * @brief Handles the user's menu selection.
     *
     * Processes the user's input and transitions to the appropriate submenu
     * or exits the program based on the selected option.
     */
    void handleSelection();
};

#endif // MAINMENU_H
