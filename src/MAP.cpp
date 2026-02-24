#include "MAP.h"

/*!
 * @brief Constructor for the MAP class.
 * @param numX Number of cells along the X-axis.
 * @param numY Number of cells along the Y-axis.
 * @param size Size of each grid cell.
 *
 * Initializes the map with a grid of specified dimensions and fills it with 0.
 */
MAP::MAP(int numX, int numY, double size)
    : numberX(numX), numberY(numY), gridSize(size) {
    grid.resize(numberX, std::vector<int>(numberY, 0)); ///< Initialize grid with zeros.
}

/*!
 * @brief Inserts a point into the map.
 * @param point A Point object containing coordinates to be marked in the map.
 *
 * Marks the grid cell corresponding to the given point's coordinates.
 */
void MAP::insertPoint(const Point& point) {
    int x = static_cast<int>(point.getX() / gridSize);
    int y = static_cast<int>(point.getY() / gridSize);
    if (x >= 0 && x < numberX && y >= 0 && y < numberY) {
        grid[x][y] = 1; ///< Mark the cell as occupied.
    }
}

/*!
 * @brief Gets the value of a specific grid cell.
 * @param indexX The X index of the grid cell.
 * @param indexY The Y index of the grid cell.
 * @return The value of the specified grid cell.
 */
int MAP::getGrid(int indexX, int indexY) const {
    return grid[indexX][indexY];
}

/*!
 * @brief Sets the value of a specific grid cell.
 * @param indexX The X index of the grid cell.
 * @param indexY The Y index of the grid cell.
 * @param value The value to be assigned to the grid cell.
 */
void MAP::setGrid(int indexX, int indexY, int value) {
    if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) {
        grid[indexX][indexY] = value;
    }
}

/*!
 * @brief Clears the map by resetting all cells to 0.
 */
void MAP::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

/*!
 * @brief Prints map information including grid size and dimensions.
 */
void MAP::printInfo() const {
    std::cout << "Grid Size: " << gridSize << "\n";
    std::cout << "Number of Cells (X x Y): " << numberX << " x " << numberY << "\n";
}

/*!
 * @brief Displays the map grid on the console.
 */
void MAP::showMap() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

/*!
 * @brief Overloads the << operator for the MAP class.
 * @param os The output stream object.
 * @param map The MAP object to be printed.
 * @return A reference to the output stream.
 *
 * Prints detailed map information including its grid content.
 */
std::ostream& operator<<(std::ostream& os, const MAP& map) {
    os << "MAP Information:\n";
    os << "Grid Size: " << map.gridSize << "\n";
    os << "Number of Cells (X x Y): " << map.numberX << " x " << map.numberY << "\n";
    os << "Grid Contents:\n";
    for (const auto& row : map.grid) {
        for (const auto& cell : row) {
            os << cell << " ";
        }
        os << "\n";
    }
    return os;
}

/*!
 * @brief Gets the number of grid cells along the X-axis.
 * @return The number of X-axis cells.
 */
int MAP::getNumberX() const {
    return numberX;
}

/*!
 * @brief Gets the number of grid cells along the Y-axis.
 * @return The number of Y-axis cells.
 */
int MAP::getNumberY() const {
    return numberY;
}

/*!
 * @brief Gets the size of each grid cell.
 * @return The grid cell size.
 */
double MAP::addGridSize() const {
    return gridSize;
}

/*!
 * @brief Sets the size of each grid cell.
 * @param size The new grid cell size.
 */
void MAP::setGridSize(double size) {
    gridSize = size;
}
