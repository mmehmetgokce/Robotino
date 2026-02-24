#include "MainMenu.h"

/*!
 * @brief Displays the main menu options to the user.
 *
 * This method prints the available options for the main menu, allowing the user
 * to choose among Connection, Motion, Sensor, or Quit.
 */
void MainMenu::display() {
    std::cout << "Main Menu\n";
    std::cout << "1. Connection\n";
    std::cout << "2. Motion\n";
    std::cout << "3. Sensor\n";
    std::cout << "4. Quit\n";
    std::cout << "Choose one: ";
}

/*!
 * @brief Handles the user's selection from the main menu.
 *
 * Depending on the user's input, this method initializes the corresponding submenu
 * (ConnectionMenu, MotionMenu, or SensorMenu) or exits the program. If the input
 * is invalid, an error message is displayed.
 */
void MainMenu::handleSelection() {
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
        ConnectionMenu connectionMenu(controller); ///< Initialize ConnectionMenu
        connectionMenu.display();
        connectionMenu.handleSelection();
        break;
    }
    case 2: {
        MotionMenu motionMenu(controller); ///< Initialize MotionMenu
        motionMenu.display();
        motionMenu.handleSelection();
        break;
    }
    case 3: {
        SensorMenu sensorMenu(controller); ///< Initialize SensorMenu
        sensorMenu.display();
        sensorMenu.handleSelection();
        break;
    }
    case 4:
        std::cout << "Exiting program.\n";
        exit(0); ///< Exit the program
    default:
        std::cout << "Invalid choice. Try again.\n";
        break;
    }
}
