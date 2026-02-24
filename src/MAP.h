#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include <vector>
#include <iostream>

/**
 * @class MAP
 * @brief Represents a grid-based map.
 * @author Hayri Baran Vural (bgnvrl@gmail.com)
 * @date December 2024
 * The MAP class provides functionality for managing a grid-based map, allowing
 * points to be inserted, cleared, and visualized.
 */
class MAP {
private:
    std::vector<std::vector<int>> grid; ///< 2D grid representing the map.
    int numberX;                        ///< Number of grid cells along the X-axis.
    int numberY;                        ///< Number of grid cells along the Y-axis.
    double gridSize;                    ///< Size of each grid cell.

public:
    /**
     * @brief Constructor for the MAP class.
     * @param numX Number of cells along the X-axis.
     * @param numY Number of cells along the Y-axis.
     * @param size Size of each grid cell.
     */
    MAP(int numX, int numY, double size);

    /**
     * @brief Inserts a point into the map.
     * @param point A Point object to be added to the map.
     */
    void insertPoint(const Point& point);

    /**
     * @brief Gets the value of a specific grid cell.
     * @param indexX The X index of the cell.
     * @param indexY The Y index of the cell.
     * @return The value of the specified cell.
     */
    int getGrid(int indexX, int indexY) const;

    /**
     * @brief Sets the value of a specific grid cell.
     * @param indexX The X index of the cell.
     * @param indexY The Y index of the cell.
     * @param value The value to be assigned to the cell.
     */
    void setGrid(int indexX, int indexY, int value);

    /**
     * @brief Clears the map by resetting all cells to 0.
     */
    void clearMap();

    /**
     * @brief Prints information about the map.
     */
    void printInfo() const;

    /**
     * @brief Displays the grid content of the map.
     */
    void showMap() const;

    /**
     * @brief Gets the number of cells along the X-axis.
     * @return Number of cells in the X direction.
     */
    int getNumberX() const;

    /**
     * @brief Gets the number of cells along the Y-axis.
     * @return Number of cells in the Y direction.
     */
    int getNumberY() const;

    /**
     * @brief Gets the size of each grid cell.
     * @return The grid cell size.
     */
    double addGridSize() const;

    /**
     * @brief Sets the size of each grid cell.
     * @param size The new grid cell size.
     */
    void setGridSize(double size);

    /**
     * @brief Overloads the << operator to display map information.
     * @param os The output stream.
     * @param map The MAP object to be displayed.
     * @return The output stream with map information.
     */
    friend std::ostream& operator<<(std::ostream& os, const MAP& map);
};

#endif // MAP_H
