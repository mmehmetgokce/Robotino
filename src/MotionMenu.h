/**
 * @file MotionMenu.h
 * @author Emirhan Unal (emirhan_60unal@hotmail.com)
 * @date December, 2024
 * @brief Defines the MotionMenu class for controlling robot motion.
 *
 * The MotionMenu class provides a user interface for controlling
 * various movement options of a robot, including moving forward,
 * turning, and interacting with walls.
 */

#ifndef MOTIONMENU_H
#define MOTIONMENU_H

#include "Menu.h"
#include "RobotController.h"

/**
 * @class MotionMenu
 * @brief A menu class for managing robot motion commands.
 *
 * The MotionMenu class extends the base Menu class and provides
 * options for moving the robot, turning, and handling wall interactions.
 */
class MotionMenu : public Menu {
private:
    RobotController* controller; /**< Pointer to the RobotController instance. */

public:
    /**
     * @brief Constructs a MotionMenu object.
     * @param ctrl A pointer to the RobotController instance used to control the robot.
     */
    MotionMenu(RobotController* ctrl);

    /**
     * @brief Displays the motion menu options to the user.
     */
    void display() override;

    /**
     * @brief Handles user input and executes corresponding robot motion commands.
     */
    void handleSelection() override;
};

#endif // MOTIONMENU_H

