#include "SensorMenu.h"

/**
 * @brief Constructs a new SensorMenu object.
 *
 * @param ctrl Pointer to a RobotController object for sensor interactions.
 */
SensorMenu::SensorMenu(RobotController* ctrl) : controller(ctrl) {}

/**
 * @brief Displays the sensor menu options.
 *
 * Prints the available options for managing robot sensors.
 */
void SensorMenu::display() {
    std::cout << "Sensor Menu\n";
    std::cout << "1. Update Sensors\n";
    std::cout << "2. Display Sensor Data\n";
    std::cout << "3. Back\n";
    std::cout << "Choose one: ";
}

/**
 * @brief Handles user selection in the sensor menu.
 *
 * Executes the appropriate action based on the user's choice:
 * - Updates sensor data.
 * - Displays sensor readings.
 * - Returns to the previous menu.
 */
void SensorMenu::handleSelection() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            controller->updateSensors();
            break;
        case 2:
            controller->print();
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
    }
}
