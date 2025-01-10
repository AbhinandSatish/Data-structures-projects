#ifndef RIDER_H
#define RIDER_H
#include <ostream>


class Rider{
    public:
    //constructor information
    Rider();
    Rider(std::string RiderFirstname,std::string RiderLastname, std::string RiderGender, 
    std::string RiderAge, std::string RiderPhoneNumber,std::string RiderRating, 
    std::string RiderPickupLocation, double RiderPickupLatitude, double RiderPickupLongitude, 
    std::string RiderDropoffLocation, double RiderDropoffLatitude, double RiderDropoffLongitude,
    std::string RiderVehiclePreference, std::string RiderCurrentState, std::string RassignedDriverFirstName,
    std::string RassignedDriverLastName, std::string RassignedDriverPhoneNumber);


    //accessors
    std::string getRiderFirstName() const;
    std::string getRiderLastName() const;
    std::string getRiderGender() const;
    std::string getRiderage() const;
    std::string getRider_Phone() const;
    std::string getRiderRating() const;
    std::string getRiderPickupLocation() const;
    double getRiderPickupLatitude() const;
    double getRiderPickupLongitude() const;
    std::string getRiderDropoffLocation() const;
    double getRiderDropoffLatitude() const;
    double getRiderDropoffLongitude() const;
    std::string getRiderVehiclePreference() const;
    std::string getRiderCurrentState();
    std::string getRassignedDriverFirstName();
    std::string getRassignedDriverLastName();
    std::string getRassignedDriverPhoneNumber();


    //mutators
    void setRiderCurrentState(std::string newRiderCurrentState);
    void setRassignedDriverFirstName(std::string newRassignedDriverFirstName);
    void setRassignedDriverLastName(std::string newRassignedDriverLastName);
    void setRassignedDriverPhoneNumber(std::string newRassignedDriverPhoneNumber);


    private:
    //private varaibles and member varaibles
    std::string RiderFirstname;
    std::string RiderLastname;
    std::string RiderGender;
    std::string RiderAge;
    std::string RiderPhoneNumber;
    std::string RiderRating;
    std::string RiderPickupLocation;
    double RiderPickupLatitude;
    double RiderPickupLongitude;
    std::string RiderDropoffLocation;
    double RiderDropoffLatitude;
    double RiderDropoffLongitude;
    std::string RiderVehiclePreference;
    std::string RiderCurrentState;
    std::string RassignedDriverFirstName;
    std::string RassignedDriverLastName;
    std::string RassignedDriverPhoneNumber;
    
};


#endif