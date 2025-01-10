#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "rider.h"
                                                                                                                        

//code all the methods from the rider.h file
Rider::Rider(){
    
    
}


Rider::Rider(std::string aRiderFirstname,std::string aRiderLastname,std::string aRiderGender,std::string aRiderAge,std::string aRiderPhoneNumber,
            std::string aRiderRating, std::string aRiderPickupLocation,
            double aRiderPickupLatitude, double aRiderPickupLongitude, 
            std::string aRiderDropoffLocation,
            double aRiderDropoffLatitude, double aRiderDropoffLongitude, std::string aRiderVehiclePreference, 
            std::string aRiderCurrentState, std::string aRassignedDriverFirstName, std::string aRassignedDriverLastName, std::string aRassignedDriverPhoneNumber) {
    RiderFirstname = aRiderFirstname;
    RiderLastname = aRiderLastname;
    RiderGender = aRiderGender;
    RiderAge = aRiderAge;
    RiderPhoneNumber = aRiderPhoneNumber;
    RiderRating = aRiderRating;
    RiderPickupLocation = aRiderPickupLocation;
    RiderPickupLatitude = aRiderPickupLatitude;
    RiderPickupLongitude = aRiderPickupLongitude;
    RiderDropoffLocation = aRiderDropoffLocation;
    RiderDropoffLatitude = aRiderDropoffLatitude;
    RiderDropoffLongitude = aRiderDropoffLongitude;
    RiderVehiclePreference = aRiderVehiclePreference;
    RiderCurrentState = aRiderCurrentState;
    RassignedDriverFirstName = aRassignedDriverFirstName;
    RassignedDriverLastName = aRassignedDriverLastName;
    RassignedDriverPhoneNumber = aRassignedDriverPhoneNumber;

}
//returning all the get methods
std::string Rider::getRiderFirstName() const{
    return RiderFirstname;
}
std::string Rider::getRiderLastName() const{
    return RiderLastname;
}
std::string Rider::getRiderGender() const{
    return RiderGender;
}
std::string Rider::getRiderage() const{
    return RiderAge;
}
std::string Rider::getRider_Phone() const{
    return RiderPhoneNumber;
}
std::string Rider::getRiderRating() const{
    return RiderRating;
}
std::string Rider::getRiderPickupLocation() const{
    return RiderPickupLocation;
}
double Rider::getRiderPickupLatitude() const{
    return RiderPickupLatitude;
}
double Rider::getRiderPickupLongitude() const{
    return RiderPickupLongitude;
}
std::string Rider::getRiderDropoffLocation() const{
    return RiderDropoffLocation;
}
double Rider::getRiderDropoffLatitude() const{
    return RiderDropoffLatitude;
}
double Rider::getRiderDropoffLongitude() const{
    return RiderDropoffLongitude;
}
std::string Rider::getRiderVehiclePreference() const{
    return RiderVehiclePreference;
}

//non-constant getters
std::string Rider::getRiderCurrentState(){
    return RiderCurrentState;
}
std::string Rider::getRassignedDriverFirstName(){
    return RassignedDriverFirstName;
}
std::string Rider::getRassignedDriverLastName(){
    return RassignedDriverLastName;
}
std::string Rider::getRassignedDriverPhoneNumber(){
    return RassignedDriverPhoneNumber;
}




//setter methods for the rider class(only the setters that are not constant and the ones that are needed)
void Rider::setRiderCurrentState(std::string newRiderCurrentState){
    RiderCurrentState = newRiderCurrentState;
}
void Rider::setRassignedDriverFirstName(std::string newRassignedDriverFirstName){
    RassignedDriverFirstName = newRassignedDriverFirstName;
}
void Rider::setRassignedDriverLastName(std::string newRassignedDriverLastName){
    RassignedDriverLastName = newRassignedDriverLastName;
}
void Rider::setRassignedDriverPhoneNumber(std::string newRassignedDriverPhoneNumber){
    RassignedDriverPhoneNumber = newRassignedDriverPhoneNumber;
}


