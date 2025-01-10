#include <iostream>
#include <vector>
#include <cmath>

// Assume Rider and Driver classes are defined

// Function to calculate distance between two points
double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

// Function to find the closest available driver for a rider
bool findClosestDriver(const Rider& rider, const std::vector<Driver>& drivers, Driver& closestDriver) {
    double minDistance = std::numeric_limits<double>::max();

    for (const Driver& driver : drivers) {
        // Check if the driver is available and matches rider's preferences
        if (driver.getDriverstate() == "Available" && /* Add more conditions based on rider's preferences */) {
            double distance = calculateDistance(
                rider.getRiderPickupLatitude(), rider.getRiderPickupLongitude(),
                driver.getDriverLatitude(), driver.getDriverLongitude()
            );

            // If the distance is less than the current minimum, update the closest driver
            if (distance < minDistance) {
                minDistance = distance;
                closestDriver = driver;
            }
        }
    }

    // Check if a suitable driver was found
    return minDistance != std::numeric_limits<double>::max();
}

int main() {
    // Assume you have a vector of Rider objects and a vector of Driver objects
    std::vector<Rider> riders;
    std::vector<Driver> drivers;

    // Assume you have a Rider object for which you want to find a driver
    Rider myRider(/* initialize rider data */);

    // Declare a variable to store the closest driver
    Driver closestDriver;

    // Call the function to find the closest driver
    bool driverFound = findClosestDriver(myRider, drivers, closestDriver);

    if (driverFound) {
        std::cout << "Driver found: " << closestDriver.getDriverFirstName() << " " << closestDriver.getDriverLastName() << std::endl;
        // Update the state of the found driver or perform other actions
    } else {
        std::cout << "No available driver found for the rider." << std::endl;
    }

    return 0;
}
