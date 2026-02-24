#include "MainMenu.h"
#include "FestoRobotAPI.h"
#include "RobotController.h"
#include "RobotOperator.h"
#include "FestoRobotInterfaceAdapter.h" // Adapter sınıfı

int main() {
    FestoRobotAPI api; // Bağımsız FestoRobotAPI nesnesi
    RobotOperator robotOperator("robotino", 1234, true);

    // FestoRobotAPI'yi RobotInterface'e uyarlamak için bir adapter kullanıyoruz
    FestoRobotInterfaceAdapter robotInterface(&api);

    RobotController controller(&robotInterface, robotOperator);

    MainMenu mainMenu(&controller);

    while (true) {
        mainMenu.display();
        mainMenu.handleSelection();
    }

    return 0;
}
