#include "driver.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ostream>


                                                                                                                        

Driver::Driver(){}
Driver::Driver(std::string adriverFirstname, std::string adriverLastname, std::string adriverGender,
std::string adriverAge, std::string adriverPhoneNumber, std::string adriverRating,
double adriverLatitude, 
double adriverLongitude,
std::string adriverVehicleType, std::string adriverCurrentState, std::string aDassignedRiderFirstName,
std::string aDassignedRiderLastName, std::string aDassignedRiderPhoneNumber){

    driverFirstname = adriverFirstname;
    driverLastname = adriverLastname;
    driverGender = adriverGender;
    driverAge = adriverAge;
    driverPhoneNumber = adriverPhoneNumber;
    driverRating = adriverRating;
    driverLatitude = adriverLatitude;
    driverLongitude = adriverLongitude;
    driverVehicleType = adriverVehicleType;
    driverCurrentState = adriverCurrentState;
    DassignedRiderFirstName = aDassignedRiderFirstName;
    DassignedRiderLastName = aDassignedRiderLastName;
    DassignedRiderPhoneNumber = aDassignedRiderPhoneNumber;

}
//returning all the get methods
std::string Driver::getDriverFirstName() const{
    return driverFirstname;
}
std::string Driver::getDriverLastName() const{
    return driverLastname;
}
std::string Driver::getDriverGender() const{
    return driverGender;
}
std::string Driver::getDriverage() const{
    return driverAge;
}
std::string Driver::getDriver_Phone() const{
    return driverPhoneNumber;
}
std::string Driver::getDriverRating() const{
    return driverRating;
}
double Driver::getDriverLatitude() const{
    return driverLatitude;
}
double Driver::getDriverLongitude() const{
    return driverLongitude;
}
std::string Driver::getVehicleType() const{
    return driverVehicleType;
}
std:: string Driver::getDriverstate(){
    return driverCurrentState;
}
std:: string Driver::getDassignedRiderFirstName(){
    return DassignedRiderFirstName;
}
std:: string Driver::getDassignedRiderLastName(){
    return DassignedRiderLastName;
}
std:: string Driver::getDassignedRiderPhoneNumber(){
    return DassignedRiderPhoneNumber;
}


//setter methods for the rider class(setters that are not constant  and ones that are needed)
void Driver::setDriverstate(std::string newDriverstate){
    driverCurrentState = newDriverstate;
}
void Driver::setDassignedRiderFirstName(std::string newDassignedRiderFirstName){
    DassignedRiderFirstName = newDassignedRiderFirstName;
}
void Driver::setDassignedRiderLastName(std::string newDassignedRiderLastName){
    DassignedRiderLastName = newDassignedRiderLastName;
}
void Driver::setDassignedRiderPhoneNumber(std::string newDassignedRiderPhoneNumber){
    DassignedRiderPhoneNumber = newDassignedRiderPhoneNumber;
}