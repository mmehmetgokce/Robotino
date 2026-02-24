#include "MotionMenu.h"

/**
 * @brief Constructs a MotionMenu object with the specified RobotController.
 * @param ctrl A pointer to the RobotController instance.
 */
MotionMenu::MotionMenu(RobotController* ctrl) : controller(ctrl) {}

/**
 * @brief Displays the available motion commands to the user.
 */
void MotionMenu::display() {
    std::cout << "Motion Menu\n";
    std::cout << "1. Move Robot\n";
    std::cout << "2. Safe Move Robot\n";
    std::cout << "3. Turn Left\n";
    std::cout << "4. Turn Right\n";
    std::cout << "5. Forward\n";
    std::cout << "6. Move Distance\n";
    std::cout << "7. Close Wall\n";
    std::cout << "8. Quit\n";
    std::cout << "Choose one: ";
}

/**
 * @brief Handles user input and executes robot commands based on the selected option.
 *
 * Prompts the user for input, processes the choice, and invokes the appropriate
 * motion command on the RobotController.
 */
void MotionMenu::handleSelection() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            controller->moveForward();
            break;
        case 2:
            controller->moveBackward();
            break;
        case 3:
            controller->turnLeft();
            break;
        case 4:
            controller->turnRight();
            break;
        case 5:
            controller->moveForward();
            break;
        case 6: {
            double distance;
            std::cout << "Enter distance to move: ";
            std::cin >> distance;
            controller->moveForward(); /**< Placeholder for distance-based motion logic. */
            break;
        }
        case 7:
            std::cout << "Detecting and moving close to wall...\n";
            controller->moveBackward(); /**< Placeholder for close-to-wall detection logic. */
            break;
        case 8:
            std::cout << "Exiting Motion Menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
    }
}
