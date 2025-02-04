#include "rider.h"
#include "driver.h"
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <cmath> 
#include <regex>
#include <limits>
#include <iomanip>
using namespace std;

#define M_PI 3.14159265358979323846
                                                                                                   
//calculate the distance between the driver and rider
double calculateDistance(double driverLatitude, double driverLongitude, double RiderPickupLatitude,
 double RiderPickupLongitude){
    const double radiusOfEarth = 6371.0; // Earth's radius in kilometers
    // convert latitude and longitude from degrees to radians
    driverLatitude *= M_PI / 180.0;
    driverLongitude *= M_PI / 180.0;
    RiderPickupLatitude *= M_PI / 180.0;
    RiderPickupLongitude *= M_PI / 180.0;
    // Haversine formula
    double dLat = RiderPickupLatitude - driverLatitude;
    double dLon = RiderPickupLongitude - driverLongitude;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + cos(driverLatitude) * cos(RiderPickupLatitude) 
    * sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    // distance in kilometers
    double distanceKM = radiusOfEarth * c;
    // convert it to distance in miles
    double distanceMiles = distanceKM * 0.621371;
    return distanceMiles;
}
//parsing the driver file function
std::vector<Rider> parseRidersFile(const std::string& filename){
    
    std::ifstream ridersFile(filename);
    std::vector <Rider> riders;
    
    if (ridersFile.is_open()) {
        std::string RiderFirstname, 
                    RiderLastname, 
                    RiderGender, 
                    RiderAge , 
                    RiderPhoneNumber,
                    RiderRating, 
                    RiderPickupLocation;
        double RiderPickupLatitude, RiderPickupLongitude;
        std::string RiderDropoffLocation;
        double RiderDropoffLatitude, RiderDropoffLongitude;
        std::string RiderVehiclePreference, 
                    RiderCurrentState, 
                    RassignedDriverFirstName, 
                    RassignedDriverLastName,
                    RassignedDriverPhoneNumber;
        while (ridersFile >> 
                RiderFirstname >> 
                RiderLastname >> 
                RiderGender >> 
                RiderAge>> 
                RiderPhoneNumber >>
                RiderRating >> 
                RiderPickupLocation >> 
                RiderPickupLatitude >> 
                RiderPickupLongitude >> 
                RiderDropoffLocation >>
                RiderDropoffLatitude >> 
                RiderDropoffLongitude >> 
                RiderVehiclePreference >> 
                RiderCurrentState >> 
                RassignedDriverFirstName >> 
                RassignedDriverLastName >> 
                RassignedDriverPhoneNumber) {
                riders.push_back(Rider(RiderFirstname, RiderLastname, RiderGender,
                                        RiderAge, RiderPhoneNumber, RiderRating,
                                        RiderPickupLocation,RiderPickupLatitude, 
                                        RiderPickupLongitude, RiderDropoffLocation, 
                                        RiderDropoffLatitude,RiderDropoffLongitude, 
                                        RiderVehiclePreference,
                                        RiderCurrentState, RassignedDriverFirstName, 
                                        RassignedDriverLastName,
                                        RassignedDriverPhoneNumber));
        }
    }
    return riders;
    
}

bool checkDriverFound(std::vector<Driver>& driver, std::string& RiderPhoneNumber){
    for(unsigned int i = 0; i < driver.size(); i ++) {
        if (driver[i].getDriver_Phone() == RiderPhoneNumber) {
            return true;
        }
    }
    return false;
}



bool checkRiderFound(std::vector<Rider>& rider, std::string& RiderPhoneNumber){
    for(unsigned int i = 0; i < rider.size(); i ++) {
        if (rider[i].getRider_Phone() == RiderPhoneNumber) {
            return true;
        }
    }
    return false;
}

//parsing the driver file function
std::vector<Driver> parseDriverFile(const std::string& filename){
    std::ifstream driversFile(filename);
    std::vector<Driver> drivers;
    
    if (driversFile.is_open()){
        std::string driverFirstName, 
                    driverLastName, 
                    driverGender, 
                    driverAge, 
                    driverPhoneNumber, 
                    driverRating;
        double driverLatitude, driverLongitude;
        std::string driverVehicleType, 
                    driverCurrentState, 
                    DassignedRiderFirstName,
                    DassignedRiderLastName, 
                    DassignedRiderPhoneNumber;
        while (driversFile >>  
            driverFirstName >> 
            driverLastName >> 
            driverGender >> 
            driverAge >> 
            driverPhoneNumber >> 
            driverRating >> 
            driverLatitude >>
            driverLongitude >> 
            driverVehicleType >> 
            driverCurrentState >> 
            DassignedRiderFirstName >>
            DassignedRiderLastName >> 
            DassignedRiderPhoneNumber){
            drivers.push_back(Driver(driverFirstName, driverLastName, driverGender, 
                            driverAge, driverPhoneNumber, 
                            driverRating, driverLatitude, driverLongitude, 
                            driverVehicleType, driverCurrentState, 
                            DassignedRiderFirstName, DassignedRiderLastName, 
                            DassignedRiderPhoneNumber));
        } 
        } else{
            std::cerr<<"Error: Cannot open file '" << filename << "'." << std::endl;
    
    }
    return drivers;

}



//if the phone number provided from the command line is not in the format of 
//xxx-xxx-xxxx, your program should print
// the following message to the output0.txt file:
//Phone number is invalid.
//checking if phone number is valid using std:: regex
bool isValidPhoneNumber(const std::string& phoneNumber){
    std::regex pattern("(\\d{3})-(\\d{3})-(\\d{4})");
    return std::regex_match(phoneNumber, pattern);
}


//writing the request function from the command line
void writeRequest(const std::string driversFile, const std:: string ridersFile,
                const std::string& outputFile0, const std::string& outputFile1, 
                const std::string& outputFile2, const std::string& RiderPhoneNumber){
    // Now to load the drivers and the riders from the files
    std::vector<Driver> drivers;
    drivers = parseDriverFile(driversFile);
    std::vector<Rider> riders;
    riders = parseRidersFile(ridersFile);





    // Declare output files outside the loop and open it
    std::ofstream output0(outputFile0);
    std::ofstream output1(outputFile1);
    std::ofstream output2(outputFile2);
    
    //declare a rider object to store the rider information
    Rider Riderobject;
    //declare a driver object to store the driver information
    Driver Driverobject;
    // interate through the driver object to test


    // now to find the rider in the riders vector
    for (Rider& rider : riders) {
        // if rider is found
        if (rider.getRider_Phone() == RiderPhoneNumber) {
            Riderobject = rider;
            break;
        }

    }
    bool driver_found1 = false;
    /*
    here i am doing to run through the driver vector, try to match the vehicle preference 
    and find the closest driver, set a minimum distance to  random number and see if you 
    can find the closest driver distance through that way, if the vehicle
    preference does not match, output" driver not found due to vehicle preference"
    if the driver is found, set the bool driver_found to true, and set the driver state to 
    "Driver_on_the_way", set 
    the RassignedDriverFirstName to the driver's first name, set the RassignedDriverLastName
     to the driver's last name, 
    set the RassignedDriverPhoneNumber to the driver's phone number
    if the driver is not found, output "No driver found for rider"
    assign a varible smallest driver distance, run all the available drivers that have the same 
    preference as the 
    rider and which ever is the smallest distance, they are the driver for the rider
    */
    double smallestDriverDistance = std::numeric_limits<double>::max();
    Driver closestDriver;
    for (Driver& driver : drivers) {
        if (driver.getVehicleType() == Riderobject.getRiderVehiclePreference() &&
                                        driver.getDriverstate() == "Available") {
            double distanceMiles = calculateDistance(driver.getDriverLatitude(), 
                                    driver.getDriverLongitude(), 
            Riderobject.getRiderPickupLatitude(), Riderobject.getRiderPickupLongitude());
            if (distanceMiles < smallestDriverDistance) {
                smallestDriverDistance = distanceMiles;
                closestDriver = driver;
                driver_found1 = true;
            }
        }
    }
    
    closestDriver.setDassignedRiderFirstName(Riderobject.getRiderFirstName());
    closestDriver.setDassignedRiderLastName(Riderobject.getRiderLastName());
    closestDriver.setDassignedRiderPhoneNumber(Riderobject.getRider_Phone());
    Riderobject.setRassignedDriverFirstName(closestDriver.getDriverFirstName());

    
    Driver driver;
    double distanceMiles = calculateDistance(closestDriver.getDriverLatitude(), 
                            closestDriver.getDriverLongitude(), 
                            Riderobject.getRiderPickupLatitude(), 
                            Riderobject.getRiderPickupLongitude());
    distanceMiles = distanceMiles * 10;
    distanceMiles = floor(distanceMiles);
    distanceMiles = distanceMiles / 10;
    if(Riderobject.getRiderCurrentState() == "Driver_on_the_way" ){
    output0 << "You have already requested a ride and your driver is on the way to the pickup location." << std::endl;
    
    }else if(Riderobject.getRiderCurrentState() == "During_the_trip"){
            output0 << "You can not request a ride at this moment as you are already on a trip." << std::endl;
    }

    else if(smallestDriverDistance != std::numeric_limits<double>::max()&& driver_found1 == true 
            && Riderobject.getRiderCurrentState() != "Driver_on_the_way" 
            && Riderobject.getRiderCurrentState() != "During_the_trip"){
        Riderobject.setRiderCurrentState("Driver_on_the_way");
        closestDriver.setDriverstate("On_the_way_to_pickup");
        output0 << "Ride requested for rider " << Riderobject.getRiderFirstName();
        if (std::string("aeiou").find(std::tolower(Riderobject.getRiderVehiclePreference()[0])) != std::string::npos) {
            output0 << ", looking for an " << 
                        Riderobject.getRiderVehiclePreference() << 
                        " vehicle." << std::endl;
        } else {
            output0 << ", looking for a " << 
            Riderobject.getRiderVehiclePreference() << 
            " vehicle." << std::endl;
        }
    
        output0 << "Pick Up Location: " << Riderobject.getRiderPickupLocation() << 
                ", Drop Off Location: "<< Riderobject.getRiderDropoffLocation() << 
                "."<< std::endl;
        output0<< "We have found the closest driver "<< 
                Riderobject.getRassignedDriverFirstName()<<"("<<
                closestDriver.getDriverRating()<<")"<< " for you."<< std::endl;
        output0<< Riderobject.getRassignedDriverFirstName() << " is now "<< 
                distanceMiles <<" miles away from you."<<  std::endl;
    }else if(driver_found1 == false){
        output0 << "Ride requested for rider " << Riderobject.getRiderFirstName();
        if (std::string("aeiou").find(std::tolower(Riderobject.getRiderVehiclePreference()[0])) != std::string::npos) {
            output0 << ", looking for an " << Riderobject.getRiderVehiclePreference() << 
                    " vehicle."<< std::endl;
        } else {
            output0 << ", looking for a " << Riderobject.getRiderVehiclePreference() << 
                        " vehicle." << std::endl;
        }
    
        output0 << "Pick Up Location: " << Riderobject.getRiderPickupLocation() << 
                ", Drop Off Location: "<< 
                Riderobject.getRiderDropoffLocation() << 
                "."<< std::endl;
        output0<< "Sorry we can not find a driver for you at this moment."<< std::endl;
    }
    


    //update the driver file
     //putting the driver.txt file as updated into the output1.txt file in the below for loop
for(std::vector<Driver>::size_type i = 0; i < drivers.size(); ++i ){
    // Update the driver state or other fields
    if(drivers[i].getDriver_Phone() == closestDriver.getDriver_Phone()){
        drivers[i].setDriverstate(closestDriver.getDriverstate());
        drivers[i].setDassignedRiderFirstName(Riderobject.getRiderFirstName());
        drivers[i].setDassignedRiderLastName(Riderobject.getRiderLastName());
        drivers[i].setDassignedRiderPhoneNumber(Riderobject.getRider_Phone());

        
    }

    // Print the updated driver information to output1.txt
    output1 << drivers[i].getDriverFirstName() << ' ' << drivers[i].getDriverLastName() << ' ' << 
                drivers[i].getDriverGender() << ' ' <<drivers[i].getDriverage() << ' ' << 
                drivers[i].getDriver_Phone() << ' ' << drivers[i].getDriverRating() << ' ' << 
                drivers[i].getDriverLatitude() << ' ' << drivers[i].getDriverLongitude() << ' ' <<
                drivers[i].getVehicleType() << ' ' << 
                drivers[i].getDriverstate() << ' ' << 
                drivers[i].getDassignedRiderFirstName() << ' ' << 
                drivers[i].getDassignedRiderLastName() << ' ' << 
                drivers[i].getDassignedRiderPhoneNumber() << std::endl;
}

    //update the rider file
    //putting the rider.txt file as updated into the output2.txt file in the below for loop
    for (std::vector<Rider>::size_type i = 0; i < riders.size(); ++i) {
    // Update the rider state or other fields
    if (riders[i].getRider_Phone() == Riderobject.getRider_Phone()) {
        riders[i].setRiderCurrentState("Driver_on_the_way");
        riders[i].setRassignedDriverFirstName(closestDriver.getDriverFirstName());
        riders[i].setRassignedDriverLastName(closestDriver.getDriverLastName());
        riders[i].setRassignedDriverPhoneNumber(closestDriver.getDriver_Phone());

        // Debug statements
        // output2 << "Rider updated: " << riders[i].getRider_Phone() << std::endl;
        // output2 << "New state: " << riders[i].getRiderCurrentState() << std::endl;
        // output2 << "New assigned driver: " << riders[i].getRassignedDriverFirstName() << " " <<
        // riders[i].getRassignedDriverLastName() << " "
        // << riders[i].getRassignedDriverPhoneNumber() << std::endl;


    }


    // Print the updated rider information to output2.txt
    output2 << riders[i].getRiderFirstName() << ' ' << riders[i].getRiderLastName() << ' ' << 
                riders[i].getRiderGender() << ' ' << 
                riders[i].getRiderage() << ' ' << riders[i].getRider_Phone() << ' ' << 
                riders[i].getRiderRating() << ' ' << 
                riders[i].getRiderPickupLocation() << ' ' << riders[i].getRiderPickupLatitude() 
                << ' ' << riders[i].getRiderPickupLongitude() << ' ' 
                << riders[i].getRiderDropoffLocation() << ' ' 
                << riders[i].getRiderDropoffLatitude() << ' ' 
                << riders[i].getRiderDropoffLongitude() << ' ' 
                << riders[i].getRiderVehiclePreference() << ' ' 
                << riders[i].getRiderCurrentState() << ' ' 
                << riders[i].getRassignedDriverFirstName() << ' ' 
                << riders[i].getRassignedDriverLastName() << ' ' 
                << riders[i].getRassignedDriverPhoneNumber() << std::endl;
    
}

    }
                
                
//cancel function
void writeCancel(const std::string& driversFile, const std:: string& ridersFile,
                const std::string& outputFile0, const std::string& outputFile1, 
                const std::string& outputFile2, const std::string& RiderPhoneNumber,
                std::vector<Driver>& drivers, std::vector<Rider>& riders){
/*
In this function i am:
                    start out with rider
                    check rider state, 
                    then move on to driver
                    check driver state
                    if both are good, then cancel the ride
                    cancel rider: first access riders phone in drivers object
                    search for that phone numbre in the riders object list
                    now request the ride for that rider
                    find that ride and make the changes to the rider variable
                    now reseat the driver variables to available and nulls
                    generate output as needed

*/


    Rider Riderobject;
    Driver closestDriver;


    // Declare output files outside the loop and open it
    //cout << "test4"<< endl;
    std::ofstream output0(outputFile0);
    std::ofstream output1(outputFile1);
    std::ofstream output2(outputFile2);

        std::vector<Driver> matchedDrivers; // Create a vector to store matched drivers
        bool rider_cancel_found = false;
        bool driver_cancel_found = false;
        for (Rider rider : riders) {
            // if rider is found
            if (rider.getRider_Phone() == RiderPhoneNumber) {
                Riderobject = rider;

                rider_cancel_found = true;
                    if(Riderobject.getRiderCurrentState() != "Driver_on_the_way"){
                        output0 << "You can only cancel a ride request if your driver is currently on the way to the pickup location." << std::endl;
                    }
                    if(Riderobject.getRiderCurrentState()== "Driver_on_the_way") {
                        output0 << "Ride request for rider " << Riderobject.getRiderFirstName() << 
                        " is now canceled by the rider." << std::endl;
                        std::string riderPNUMBER = Riderobject.getRider_Phone();
                        //get the rider object from the driver that got matched
                        for (Driver driver : drivers) {
                            if (driver.getDassignedRiderPhoneNumber() == riderPNUMBER) {
                                closestDriver = driver;
                                break;
                            }
                        }
                        
                        // cout << closestDriver.getDriverstate() << endl;
                        // cout << closestDriver.getDriverFirstName() << endl;
                        // cout << closestDriver.getDassignedRiderFirstName() << endl;
                        //get and update the driver
                        closestDriver.setDriverstate("Available");
                        closestDriver.setDassignedRiderFirstName("null");
                        closestDriver.setDassignedRiderLastName("null");
                        closestDriver.setDassignedRiderPhoneNumber("null");
                        // cout << closestDriver.getDassignedRiderFirstName() << endl;
                        //update the rider
                        Riderobject.setRassignedDriverFirstName("null");
                        Riderobject.setRassignedDriverLastName("null");
                        Riderobject.setRassignedDriverPhoneNumber("null");
                        Riderobject.setRiderCurrentState("Ready_to_request");
                        //cout << closestDriver.getDriverstate() << endl;
                    }

                    //update the driver file
                    //putting the driver.txt file as updated into the output1.txt file in
                    //the below for loop
                    for(std::vector<Driver>::size_type i = 0; i < drivers.size(); ++i ){
                        // Update the driver state or other fields
                        if(drivers[i].getDriver_Phone() == closestDriver.getDriver_Phone()){
                            drivers[i].setDriverstate(closestDriver.getDriverstate());
                            drivers[i].setDassignedRiderFirstName(closestDriver.getDassignedRiderFirstName());
                            drivers[i].setDassignedRiderLastName(closestDriver.getDassignedRiderLastName());
                            drivers[i].setDassignedRiderPhoneNumber(closestDriver.getDassignedRiderPhoneNumber());

                        }
                        // Print the updated driver information to output1.txt
                        output1 << drivers[i].getDriverFirstName() << ' ' << drivers[i].getDriverLastName() << ' ' << 
                                    drivers[i].getDriverGender() << ' ' << drivers[i].getDriverage() << ' ' << 
                                    drivers[i].getDriver_Phone() << ' ' << drivers[i].getDriverRating() << ' ' << 
                                    drivers[i].getDriverLatitude() << ' ' << drivers[i].getDriverLongitude() << ' ' << 
                                    drivers[i].getVehicleType() << ' ' << drivers[i].getDriverstate() << ' ' <<
                                    drivers[i].getDassignedRiderFirstName() << ' ' <<
                                    drivers[i].getDassignedRiderLastName() << ' ' << 
                                    drivers[i].getDassignedRiderPhoneNumber() << std::endl;
                    }
                    //update the rider file
                    //putting the rider.txt file as updated into the output2.txt file in the below for loop
                    for (std::vector<Rider>::size_type i = 0; i < riders.size(); ++i) {
                        // Update the rider state or other fields
                        if (riders[i].getRider_Phone() == Riderobject.getRider_Phone()) {
                            riders[i].setRiderCurrentState("Ready_to_request");
                            riders[i].setRassignedDriverFirstName(Riderobject.getRassignedDriverFirstName());
                            riders[i].setRassignedDriverLastName(Riderobject.getRassignedDriverLastName());
                            riders[i].setRassignedDriverPhoneNumber(Riderobject.getRassignedDriverPhoneNumber());
                        }
                        // Print the updated rider information to output2.txt
                        output2 << riders[i].getRiderFirstName() << ' ' << riders[i].getRiderLastName() << ' ' <<
                        riders[i].getRiderGender() << ' ' << riders[i].getRiderage() << ' ' << 
                        riders[i].getRider_Phone() << ' ' << riders[i].getRiderRating() << ' ' <<
                        riders[i].getRiderPickupLocation() << ' ' << 
                        riders[i].getRiderPickupLatitude() << ' ' << 
                        riders[i].getRiderPickupLongitude() << ' ' <<
                        riders[i].getRiderDropoffLocation() << ' ' <<
                        riders[i].getRiderDropoffLatitude() << ' ' << 
                        riders[i].getRiderDropoffLongitude() << ' ' << 
                        riders[i].getRiderVehiclePreference() << ' ' << 
                        riders[i].getRiderCurrentState() << ' ' << 
                        riders[i].getRassignedDriverFirstName() << ' ' << 
                        riders[i].getRassignedDriverLastName() << ' ' << 
                        riders[i].getRassignedDriverPhoneNumber() << std::endl;
                    }
                    

                break;
            }
        }
        if(rider_cancel_found == false){
            Driver matchedDriver; // Create a variable to hold the matched driver
            std::string driver_current_phone = "null";
            for (Driver driver : drivers) {
                // If driver is found
                if (driver.getDriver_Phone() == RiderPhoneNumber) {
                    driver_current_phone = driver.getDriver_Phone();

                    matchedDriver = driver; // Store the matched driver
                    driver_cancel_found = true;
                    if(matchedDriver.getDriverstate() != "On_the_way_to_pickup"){
                        //cout << closestDriver.getDriverstate() << endl;
                        //cout << "test"<< endl;
                    output0 << "You can only cancel a ride request if you are currently on the way to the pickup location." << std::endl;
 
                }else{
                    std::string riderPNUMBER = matchedDriver.getDassignedRiderPhoneNumber();
                    //get the rider object from the driver that got matched
                    for (Rider r : riders) {
                        if (r.getRider_Phone() == riderPNUMBER) {
                            Riderobject = r;
                            break;
                        }
                    }
                    



                    output0 << "Your driver " << 
                    matchedDriver.getDriverFirstName() << 
                    " has canceled the ride request. We will now find a new driver for you." 
                    << std::endl;
                    // now i am going to find the index of the matched driver in the drivers vector
                    long unsigned int index = 0;
                    for (Driver driver : drivers) {
                        if (driver.getDriver_Phone() == matchedDriver.getDriver_Phone()) {
                            break;
                        }
                        index++;
                    }
                    // cout << index << endl;
                    matchedDriver.setDriverstate("Available");
                    // cout << matchedDriver.getDriverstate() << endl;
                    matchedDriver.setDassignedRiderFirstName("null");
                    matchedDriver.setDassignedRiderLastName("null");
                    matchedDriver.setDassignedRiderPhoneNumber("null");
                    output0 << "Ride requested for rider " << Riderobject.getRiderFirstName();
                    if (std::string("aeiou").find(std::tolower(Riderobject.getRiderVehiclePreference()[0])) != std::string::npos) {
                        output0 << ", looking for an " << 
                                    Riderobject.getRiderVehiclePreference() << 
                                    " vehicle." << std::endl;
                    } else {
                        output0 << ", looking for a " << 
                                    Riderobject.getRiderVehiclePreference() << 
                                    " vehicle." << std::endl;
                    }
                    output0 << "Pick Up Location: " << 
                            Riderobject.getRiderPickupLocation() << 
                            ", Drop Off Location: "<< Riderobject.getRiderDropoffLocation() << 
                            "."<< std::endl;
                    //set up for new driver
                    double smallestDriverDistance = std::numeric_limits<double>::max();
                    Driver closestDriver;
                    for (Driver& driver : drivers) {
                        if (driver.getVehicleType() == Riderobject.getRiderVehiclePreference() && driver.getDriverstate() == "Available") {
                            double distanceMiles = calculateDistance(driver.getDriverLatitude(),
                                                                    driver.getDriverLongitude(),
                                                                    Riderobject.getRiderPickupLatitude(), 
                                                                    Riderobject.getRiderPickupLongitude());
                            if (distanceMiles < smallestDriverDistance) {
                                smallestDriverDistance = distanceMiles;
                                closestDriver = driver;
                            }
                        }
                    }

                    closestDriver.setDassignedRiderFirstName(Riderobject.getRiderFirstName());
                    closestDriver.setDassignedRiderLastName(Riderobject.getRiderLastName());
                    closestDriver.setDassignedRiderPhoneNumber(Riderobject.getRider_Phone());
                    Riderobject.setRassignedDriverFirstName(closestDriver.getDriverFirstName());
                    Riderobject.setRassignedDriverLastName(closestDriver.getDriverLastName());
                    Riderobject.setRassignedDriverPhoneNumber(closestDriver.getDriver_Phone());
                    Riderobject.setRiderCurrentState("Driver_on_the_way");
                    closestDriver.setDriverstate("On_the_way_to_pickup");

                    double miles_distance = calculateDistance(closestDriver.getDriverLatitude(),
                                                                closestDriver.getDriverLongitude(),
                                                                Riderobject.getRiderPickupLatitude(),
                                                                Riderobject.getRiderPickupLongitude());
                    miles_distance = miles_distance * 10;
                    miles_distance = floor(miles_distance);
                    miles_distance = miles_distance / 10;
                    output0<< "We have found the closest driver "<< 
                            Riderobject.getRassignedDriverFirstName()<<
                            "("<<closestDriver.getDriverRating()<<")"<< 
                            " for you."<< std::endl;
                    output0<< Riderobject.getRassignedDriverFirstName() << 
                            " is now "<< miles_distance <<" miles away from you."<<  std::endl;



                    //driver
                    for(std::vector<Driver>::size_type i = 0; i < drivers.size(); ++i ){
                        // Update the driver state or other fields
                        if (drivers[i].getDriver_Phone() == matchedDriver.getDriver_Phone() && i == index){
                            drivers[i].setDriverstate("Available");
                            drivers[i].setDassignedRiderFirstName("null");
                            drivers[i].setDassignedRiderLastName("null");
                            drivers[i].setDassignedRiderPhoneNumber("null");

                        }
                        else if(drivers[i].getDriver_Phone() == closestDriver.getDriver_Phone()){
                            
                            drivers[i].setDriverstate(closestDriver.getDriverstate());
                            drivers[i].setDassignedRiderFirstName(Riderobject.getRiderFirstName());
                            drivers[i].setDassignedRiderLastName(Riderobject.getRiderLastName());
                            drivers[i].setDassignedRiderPhoneNumber(Riderobject.getRider_Phone());
                            
                            
                        }
                        // Print the updated driver information to output1.txt
                        output1 << drivers[i].getDriverFirstName() << ' ' << 
                        drivers[i].getDriverLastName() << ' ' <<
                        drivers[i].getDriverGender() << ' ' << 
                        drivers[i].getDriverage() << ' ' << 
                        drivers[i].getDriver_Phone() << ' ' << 
                        drivers[i].getDriverRating() << ' ' << 
                        drivers[i].getDriverLatitude() << ' ' << 
                        drivers[i].getDriverLongitude() << ' ' << 
                        drivers[i].getVehicleType() << ' ' << 
                        drivers[i].getDriverstate() << ' ' << 
                        drivers[i].getDassignedRiderFirstName() << ' ' << 
                        drivers[i].getDassignedRiderLastName() << ' ' << 
                        drivers[i].getDassignedRiderPhoneNumber() << std::endl;
                    }
                    //rider
                    for (std::vector<Rider>::size_type i = 0; i < riders.size(); ++i) {
                        // Update the rider state or other fields
                        if (riders[i].getRider_Phone() == Riderobject.getRider_Phone()) {
                            riders[i].setRiderCurrentState("Driver_on_the_way");
                            riders[i].setRassignedDriverFirstName(closestDriver.getDriverFirstName());
                            riders[i].setRassignedDriverLastName(closestDriver.getDriverLastName());
                            riders[i].setRassignedDriverPhoneNumber(closestDriver.getDriver_Phone());
                        }
                        // Print the updated rider information to output2.txt
                        output2 << riders[i].getRiderFirstName() << ' ' << 
                                riders[i].getRiderLastName() << ' ' << 
                                riders[i].getRiderGender() << ' ' << 
                                riders[i].getRiderage() << ' ' << 
                                riders[i].getRider_Phone() << ' ' << 
                                riders[i].getRiderRating() << ' ' << 
                                riders[i].getRiderPickupLocation() << ' ' << 
                                riders[i].getRiderPickupLatitude() << ' ' << 
                                riders[i].getRiderPickupLongitude() << ' ' << 
                                riders[i].getRiderDropoffLocation() << ' ' << 
                                riders[i].getRiderDropoffLatitude() << ' ' << 
                                riders[i].getRiderDropoffLongitude() << ' ' << 
                                riders[i].getRiderVehiclePreference() << ' ' << 
                                riders[i].getRiderCurrentState() << ' ' << 
                                riders[i].getRassignedDriverFirstName() << ' ' << 
                                riders[i].getRassignedDriverLastName() << ' ' << 
                                riders[i].getRassignedDriverPhoneNumber() << std::endl;
                    }
                }
                
    }
                
                }
                if(driver_cancel_found == false && rider_cancel_found == false){
                    output0 << "Account does not exist." << std::endl;
                }
        }
        }

//main method

int main(int argc, char* argv[]){
    //set up the command line arguments

    //check the number pf command line arguments
    if (argc < 8){
        std::cerr << "Usage: " << 
        argv[0] << " <drivers_file> <riders_file> <output_file0> <output_file1> <output_file2> <Rider_PhoneNumber> <Request>" << 
        std::endl;
        return 1;
    }

    std::string driversFile = argv[1];
    std::string ridersFile = argv[2];
    std::string outputFile0 = argv[3];
    std::string outputFile1 = argv[4];
    std::string outputFile2 = argv[5];
    std::string RiderPhoneNumber = argv[6];
    std::string Request = argv[7];

    //check if the files can be opened
    std::ofstream output0(outputFile0);
    std::ofstream output1(outputFile1);
    std::ofstream output2(outputFile2);

    
    if (!output0.is_open()){
        output0 << "Error: Cannot open file '" << 
        driversFile << "'." << std::endl;
        output0.close();
        return 1;
    }

    if (!output1.is_open()){
        std::ofstream output1(outputFile1);
        output1 << "Error: Cannot open file '" << 
        ridersFile << "'." << std::endl;
        output1.close();
        return 1;
    }
    if (!output2.is_open()){
        std::ofstream output1(outputFile2);
        output1 << "Error: Cannot open file '" << 
        ridersFile << "'." << std::endl;
        output1.close();
        return 1;
    }

    std::vector<Driver> drivers;
    Driver driver;

    
    //loop through the vector to see if drivers are there
    drivers = parseDriverFile(driversFile);
        for (Driver driver : drivers) {
        //cout << "test10"<< endl;
        //cout << driver.getDriverstate() << endl;
    }
    //calling the riderfileParse method
    std::vector<Rider> allriders;
    allriders = parseRidersFile(ridersFile);

    Rider currentRider;
    Driver currentDriver;

    bool check = true;


    //check if the phone number is valid
    if (!isValidPhoneNumber(RiderPhoneNumber)){
        output0 << "Phone number is invalid." << std::endl;
        //output0.close();
        check = false;
        
    }

    //calling the checkDriverfound method
    bool rider_found = checkRiderFound(allriders, RiderPhoneNumber);
    //cout << rider_found << endl;

    bool driver_found = checkDriverFound(drivers, RiderPhoneNumber);
    //cout << driver_found << endl;

    if (!rider_found && check) {
        output0 << "Account does not exist." << std::endl;
        for (Driver driver : drivers) {
    }
    }
    if(Request == "cancel"){
        if (!driver_found && !rider_found) {
        output0 << "Account does not exist." << std::endl;
        }
    }
    
    if (rider_found){
        if(Request == "request"){
            writeRequest(driversFile, ridersFile, outputFile0, outputFile1, outputFile2, RiderPhoneNumber);
    }
    }
    if(Request == "cancel"){
        writeCancel(driversFile, ridersFile, outputFile0, outputFile1, outputFile2, RiderPhoneNumber, drivers, allriders);
    }

    output0.close();
    output1.close();
    output2.close();

    

    return 0;
}




