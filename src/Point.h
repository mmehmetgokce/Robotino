/**
 * @file Point.h
 * @author Muhammet Mehmet Gokce (gokcemehmet744@gmail.com)
 * @date December, 2024
 * @brief Defines the Point class for 2D coordinate operations.
 *
 * The Point class provides methods for managing and manipulating
 * 2D Cartesian coordinates, including distance and angle calculations.
 */

#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

/**
 * @class Point
 * @brief Represents a point in a 2D Cartesian coordinate system.
 *
 * The Point class includes methods for getting and setting coordinates,
 * comparing points, and calculating distances and angles between points.
 */
class Point {
private:
    double x; /**< X-coordinate of the point. */
    double y; /**< Y-coordinate of the point. */

public:
    /**
     * @brief Constructs a Point object.
     * @param xVal Initial x-coordinate. Defaults to 0.0.
     * @param yVal Initial y-coordinate. Defaults to 0.0.
     */
    Point(double xVal = 0.0, double yVal = 0.0);

    /**
     * @brief Gets the x-coordinate of the point.
     * @return The x-coordinate.
     */
    double getX() const;

    /**
     * @brief Sets the x-coordinate of the point.
     * @param xVal The new x-coordinate value.
     */
    void setX(double xVal);

    /**
     * @brief Gets the y-coordinate of the point.
     * @return The y-coordinate.
     */
    double getY() const;

    /**
     * @brief Sets the y-coordinate of the point.
     * @param yVal The new y-coordinate value.
     */
    void setY(double yVal);

    /**
     * @brief Compares this point with another point for equality.
     * @param other The other point to compare with.
     * @return True if the points have the same coordinates, otherwise false.
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Gets the coordinates of the point.
     * @param _x Reference to store the x-coordinate.
     * @param _y Reference to store the y-coordinate.
     */
    void getPoint(double& _x, double& _y) const;

    /**
     * @brief Sets the coordinates of the point.
     * @param _x The new x-coordinate value.
     * @param _y The new y-coordinate value.
     */
    void setPoint(double _x, double _y);

    /**
     * @brief Calculates the Euclidean distance to another point.
     * @param pos The other point.
     * @return The distance to the other point.
     */
    double findDistanceTo(const Point& pos) const;

    /**
     * @brief Calculates the angle (in degrees) to another point.
     * @param pos The other point.
     * @return The angle in degrees to the other point.
     */
    double findAngleTo(const Point& pos) const;
};

#endif // POINT_H

