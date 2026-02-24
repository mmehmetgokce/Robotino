#include "Mapper.h"
#include <iostream>

/*!
 * @brief Updates the map using data from the lidar sensor.
 *
 * The method retrieves sensor data from the lidar and updates the map grid
 * by marking relevant cells based on sensor readings.
 */
void Mapper::updateMap() {
    lidar->update(); ///< Update sensor data.
    std::cout << "Updating map with sensor data...\n";

    for (int i = 0; i < 10; ++i) {
        double range = lidar->getSensorValue(i);
        if (range > 0.0) {
            map.setGrid(i, i, 1); ///< Example logic: Mark cells based on sensor values.
        }
    }
}

/*!
 * @brief Records the current map state.
 * @return True if the map was successfully recorded, otherwise false.
 *
 * This function simulates recording the map and returns success by default.
 */
bool Mapper::recordMap() {
    std::cout << "Recording map...\n";
    // Add map recording logic here.
    return true; ///< Example: Always returns success.
}

/*!
 * @brief Displays the current map grid.
 */
void Mapper::showMap() {
    std::cout << "Displaying map:\n";
    map.showMap();
}
