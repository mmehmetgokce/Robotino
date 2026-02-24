#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

/**
 * @class Menu
 * @brief Abstract base class for creating menu systems.
 * @author Yusuf Goc (yusufsalih987@gmail.com)
 * @date December 2024
 * The Menu class defines a blueprint for all menu implementations.
 * Derived classes must override the display and handleSelection methods.
 */
class Menu {
public:
    /**
     * @brief Displays the menu options.
     *
     * This is a pure virtual function that must be implemented by derived classes
     * to show the menu options to the user.
     */
    virtual void display() = 0;

    /**
     * @brief Handles the user selection.
     *
     * This is a pure virtual function that must be implemented by derived classes
     * to process user input and perform the corresponding actions.
     */
    virtual void handleSelection() = 0;

    /**
     * @brief Virtual destructor for the Menu class.
     *
     * Ensures proper cleanup for derived classes when using polymorphism.
     */
    virtual ~Menu() = default;
};

#endif // MENU_H
