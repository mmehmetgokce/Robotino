/**
 * @file Pose.h
 * @author Muhammet Mehmet Gokce (gokcemehmet744@gmail.com)
 * @date December, 2024
 * @brief Defines the Pose class for representing and manipulating 2D positions and orientations.
 *
 * The Pose class provides methods for managing 2D positions and orientations,
 * including distance and angle calculations, and operator overloading for position arithmetic.
 */

#ifndef POSE_H
#define POSE_H

#include <iostream>
#include <cmath>

/**
 * @class Pose
 * @brief Represents a 2D position (x, y) and orientation (theta in radians).
 *
 * The Pose class supports arithmetic operations, comparisons, and calculations
 * between poses in a 2D plane.
 */
class Pose {
private:
    double x;   /**< X-coordinate of the pose. */
    double y;   /**< Y-coordinate of the pose. */
    double th;  /**< Orientation (theta) in radians. */

public:
    /**
     * @brief Constructs a Pose object with default values (0, 0, 0).
     */
    Pose();

    /**
     * @brief Constructs a Pose object with specified values.
     * @param x Initial x-coordinate.
     * @param y Initial y-coordinate.
     * @param th Initial orientation (theta) in radians.
     */
    Pose(double x, double y, double th);

    /**
     * @brief Gets the x-coordinate of the pose.
     * @return The x-coordinate.
     */
    double getX() const;

    /**
     * @brief Sets the x-coordinate of the pose.
     * @param x The new x-coordinate value.
     */
    void setX(double x);

    /**
     * @brief Gets the y-coordinate of the pose.
     * @return The y-coordinate.
     */
    double getY() const;

    /**
     * @brief Sets the y-coordinate of the pose.
     * @param y The new y-coordinate value.
     */
    void setY(double y);

    /**
     * @brief Gets the orientation (theta) of the pose.
     * @return The orientation in radians.
     */
    double getTh() const;

    /**
     * @brief Sets the orientation (theta) of the pose.
     * @param th The new orientation value in radians.
     */
    void setTh(double th);

    /**
     * @brief Compares two poses for equality.
     * @param other The other pose to compare with.
     * @return True if the poses are equal, otherwise false.
     */
    bool operator==(const Pose& other) const;

    /**
     * @brief Adds two poses.
     * @param other The other pose to add.
     * @return A new Pose representing the sum.
     */
    Pose operator+(const Pose& other) const;

    /**
     * @brief Subtracts another pose from this pose.
     * @param other The other pose to subtract.
     * @return A new Pose representing the difference.
     */
    Pose operator-(const Pose& other) const;

    /**
     * @brief Adds another pose to this pose (in-place).
     * @param other The other pose to add.
     * @return A reference to this Pose.
     */
    Pose& operator+=(const Pose& other);

    /**
     * @brief Subtracts another pose from this pose (in-place).
     * @param other The other pose to subtract.
     * @return A reference to this Pose.
     */
    Pose& operator-=(const Pose& other);

    /**
     * @brief Compares two poses based on their coordinates.
     * @param other The other pose to compare with.
     * @return True if this pose is less than the other pose, otherwise false.
     */
    bool operator<(const Pose& other) const;

    /**
     * @brief Gets the position and orientation of the pose.
     * @param _x Reference to store the x-coordinate.
     * @param _y Reference to store the y-coordinate.
     * @param _th Reference to store the orientation.
     */
    void getPose(double& _x, double& _y, double& _th) const;

    /**
     * @brief Sets the position and orientation of the pose.
     * @param _x The new x-coordinate.
     * @param _y The new y-coordinate.
     * @param _th The new orientation.
     */
    void setPose(double _x, double _y, double _th);

    /**
     * @brief Calculates the Euclidean distance to another pose.
     * @param pos The other pose.
     * @return The distance to the other pose.
     */
    double findDistanceTo(const Pose& pos) const;

    /**
     * @brief Calculates the angle to another pose in radians.
     * @param pos The other pose.
     * @return The angle to the other pose in radians.
     */
    double findAngleTo(const Pose& pos) const;
};

#endif // POSE_H

