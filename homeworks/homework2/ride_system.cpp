
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "ride_system.h"
#include <vector>
#include <cmath>


std::vector<Driver> parseDriverFile(const std::string& filename){
    std::vector<Driver> drivers;
    std::ifstream driversFile(filename);

    if(driversFile.is_open()){
        std::string line;
        while (std::getline(driversFile, line)){
            std::istringstream iss(line);
            Driver driver;

            std::string firstName, lastName, gender, phone, vehicleType, currentState;
            int age;
            double rating, latitude, longitude;
            std::string riderFirstName, riderLastName, riderPhone;

            if (iss >> firstName >> lastName >> gender >> age >> phone >> rating >> latitude
             >> longitude >> vehicleType >> currentState >> riderFirstName >> riderLastName >> riderPhone){
                driver.setDriverFirstName(firstName);
                driver.setDriverLastName(lastName);
                driver.setDriverGender(gender);
                driver.setAge(age);
                driver.setDriver_Phone(phone);
                driver.setRating(rating);
                driver.setLatitude(latitude);
                driver.setLongitude(longitude);
                driver.setVehicleType(vehicleType);
                driver.setCurrent_state(currentState);
                driver.setAssignedRider(riderFirstName, riderLastName, riderPhone);

                drivers.push_back(driver);
            }
            else {
                std::cerr << "Error parsing line: " << line << std::endl;
            }
        }
    }
    return drivers;
}



std::vector<Rider> parseRidersFile(const std::string& filename){
    std::vector<Rider> riders;
    std::ifstream ridersFile(filename);

    if(ridersFile.is_open()){
        //std::string line;
        std::string firstName, lastName, gender, phone, pickupName, dropoffName, vehiclePref, currentState;
            int age;
            double rating, pickupLat, pickupLong, dropoffLat, dropoffLong;
            std::string driverFirstName, driverLastName, driverPhone;
            while(ridersFile>> firstName >> lastName >> gender >> age >> phone >> rating >> pickupName >> pickupLat 
            >> pickupLong >> dropoffName >> dropoffLat >> dropoffLong >> vehiclePref >> currentState >> driverFirstName 
            >> driverLastName >> driverPhone) {
                riders.push_back(Rider(firstName, lastName, gender, age, phone, rating, pickupName, pickupLat, pickupLong, 
                dropoffName, dropoffLat, dropoffLong, vehiclePref, currentState, driverFirstName, driverLastName, driverPhone));
            }
            
            // if (iss >> firstName >> lastName >> gender >> age >> phone >> rating >> pickupName >> pickupLat >> pickupLong >> dropoffName >> dropoffLat >> dropoffLong >> vehiclePref >> currentState >> driverFirstName >> driverLastName >> driverPhone) {
            //     Rider rider(firstName, lastName, gender, age, phone, rating, pickupName, pickupLat, pickupLong, dropoffName, dropoffLat, dropoffLong, vehiclePref, currentState, driverFirstName, driverLastName, driverPhone);
            //     riders.push_back(rider);
            // }
        // while (std::getline(ridersFile, line)) {
        //     //std::istringstream iss(line);
            
        // }
        ridersFile.close();
    }
    return riders;
}
int main(int argc, char* argv[]){
    //set up the command line arguments
    std::string driversFile = argv[1];
    std::string ridersFile = argv[2];
    std::string outputFile0 = argv[3];
    std::string outputFile1 = argv[4];
    std::string outputFile2 = argv[5];
    std::string RiderPhoneNumber = argv[6];
    std::string Request = argv[7];

    //calling the riderfileParse method
    std::vector<Rider> riders = parseRidersFile(ridersFile);



    //if the request is a cancel request then write out to the output0.txt file
    if (Request == "cancel"){
        std::ofstream output0(outputFile0);
        output0 << "" << std::endl;
        output0.close();
    }

/*
    //Parse the drivers file
    std::vector<Driver> drivers = parseDriversFile("drivers.txt");

    //Print out the drivers
    for (const auto& driver : drivers){
        //printing the information for each of the drivver
        std::cout << "Driver: " << driver.getDriverFirstName() << " " << driver.getDriverLastName() << std::endl;


    }

    return 0;

*/
}
