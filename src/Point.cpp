#include "Point.h"

/**
 * @brief Constructs a Point object with specified coordinates.
 * @param xVal Initial x-coordinate.
 * @param yVal Initial y-coordinate.
 */
Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}

/**
 * @brief Gets the x-coordinate of the point.
 * @return The x-coordinate.
 */
double Point::getX() const {
    return x;
}

/**
 * @brief Sets the x-coordinate of the point.
 * @param xVal The new x-coordinate value.
 */
void Point::setX(double xVal) {
    x = xVal;
}

/**
 * @brief Gets the y-coordinate of the point.
 * @return The y-coordinate.
 */
double Point::getY() const {
    return y;
}

/**
 * @brief Sets the y-coordinate of the point.
 * @param yVal The new y-coordinate value.
 */
void Point::setY(double yVal) {
    y = yVal;
}

/**
 * @brief Compares this point with another point for equality.
 * @param other The other point to compare with.
 * @return True if the points have the same coordinates, otherwise false.
 */
bool Point::operator==(const Point& other) const {
    return (x == other.x && y == other.y);
}

/**
 * @brief Gets the coordinates of the point.
 * @param _x Reference to store the x-coordinate.
 * @param _y Reference to store the y-coordinate.
 */
void Point::getPoint(double& _x, double& _y) const {
    _x = x;
    _y = y;
}

/**
 * @brief Sets the coordinates of the point.
 * @param _x The new x-coordinate value.
 * @param _y The new y-coordinate value.
 */
void Point::setPoint(double _x, double _y) {
    x = _x;
    y = _y;
}

/**
 * @brief Calculates the Euclidean distance to another point.
 * @param pos The other point.
 * @return The distance to the other point.
 */
double Point::findDistanceTo(const Point& pos) const {
    return std::sqrt(std::pow(x - pos.x, 2) + std::pow(y - pos.y, 2));
}

/**
 * @brief Calculates the angle (in degrees) to another point.
 * @param pos The other point.
 * @return The angle in degrees to the other point.
 */
double Point::findAngleTo(const Point& pos) const {
    return std::atan2(pos.y - y, pos.x - x) * (180.0 / 3.14); // Converts radians to degrees.
}
