#include "ride_system.h"



void testParseDriversFile(const std::string& filename) {
    std::vector<Driver> drivers = parseDriversFile(filename);

    // Print or inspect the drivers vector
    for (const auto& driver : drivers) {
        // Print relevant information for each driver
        std::cout << "Driver: " << driver.getDriverFirstName() << " " << driver.getDriverLastName() << std::endl;
        // Print other relevant information
    }
}

int main() {
    // Replace "test_drivers.txt" with the actual filename you created for testing
    testParseDriversFile("drivers.txt");

    return 0;
}
