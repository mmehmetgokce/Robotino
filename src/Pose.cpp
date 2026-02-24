#include "Pose.h"

/**
 * @brief Constructs a Pose object with default values (x=0.0, y=0.0, th=0.0).
 */
Pose::Pose() : x(0.0), y(0.0), th(0.0) {}

/**
 * @brief Constructs a Pose object with specified values.
 * @param xVal Initial x-coordinate.
 * @param yVal Initial y-coordinate.
 * @param thVal Initial orientation (theta) in radians.
 */
Pose::Pose(double xVal, double yVal, double thVal) : x(xVal), y(yVal), th(thVal) {}

/**
 * @brief Gets the x-coordinate of the pose.
 * @return The x-coordinate of the pose.
 */
double Pose::getX() const { return x; }

/**
 * @brief Sets the x-coordinate of the pose.
 * @param xVal The new x-coordinate value.
 */
void Pose::setX(double xVal) { x = xVal; }

/**
 * @brief Gets the y-coordinate of the pose.
 * @return The y-coordinate of the pose.
 */
double Pose::getY() const { return y; }

/**
 * @brief Sets the y-coordinate of the pose.
 * @param yVal The new y-coordinate value.
 */
void Pose::setY(double yVal) { y = yVal; }

/**
 * @brief Gets the orientation (theta) of the pose in radians.
 * @return The orientation in radians.
 */
double Pose::getTh() const { return th; }

/**
 * @brief Sets the orientation (theta) of the pose.
 * @param thVal The new orientation value in radians.
 */
void Pose::setTh(double thVal) { th = thVal; }

/**
 * @brief Compares two poses for equality.
 * @param other The other pose to compare with.
 * @return True if the x, y, and theta values are equal, otherwise false.
 */
bool Pose::operator==(const Pose& other) const {
    return (x == other.x && y == other.y && th == other.th);
}

/**
 * @brief Adds the values of another pose to this pose.
 * @param other The pose to add.
 * @return A new Pose object representing the sum.
 */
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

/**
 * @brief Subtracts the values of another pose from this pose.
 * @param other The pose to subtract.
 * @return A new Pose object representing the difference.
 */
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

/**
 * @brief Adds the values of another pose to this pose (in-place).
 * @param other The pose to add.
 * @return A reference to this Pose object after the addition.
 */
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

/**
 * @brief Subtracts the values of another pose from this pose (in-place).
 * @param other The pose to subtract.
 * @return A reference to this Pose object after the subtraction.
 */
Pose& Pose::operator-=(const Pose& other) {
    x -= other.x;
    y -= other.y;
    th -= other.th;
    return *this;
}

/**
 * @brief Compares this pose with another pose for ordering based on x and y values.
 * @param other The pose to compare with.
 * @return True if this pose is considered "less than" the other, otherwise false.
 */
bool Pose::operator<(const Pose& other) const {
    return (x < other.x) || (y < other.y);
}

/**
 * @brief Gets the position and orientation values of the pose.
 * @param _x Reference to store the x-coordinate.
 * @param _y Reference to store the y-coordinate.
 * @param _th Reference to store the orientation (theta).
 */
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

/**
 * @brief Sets the position and orientation values of the pose.
 * @param _x The new x-coordinate value.
 * @param _y The new y-coordinate value.
 * @param _th The new orientation (theta) value.
 */
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

/**
 * @brief Calculates the Euclidean distance to another pose.
 * @param pos The pose to calculate the distance to.
 * @return The Euclidean distance to the other pose.
 */
double Pose::findDistanceTo(const Pose& pos) const {
    return std::sqrt(std::pow(x - pos.x, 2) + std::pow(y - pos.y, 2));
}

/**
 * @brief Calculates the angle to another pose in radians.
 * @param pos The pose to calculate the angle to.
 * @return The angle to the other pose in radians.
 */
double Pose::findAngleTo(const Pose& pos) const {
    return std::atan2(pos.y - y, pos.x - x);
}
