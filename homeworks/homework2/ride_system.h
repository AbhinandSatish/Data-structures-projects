#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>





class Rider{
    public:
    //constructor information
    Rider();
    //remove const
    Rider( std::string& firstName, const std::string& lastName, const std::string& gender,
        int age, const std::string& phoneNumber, double rating,
        const std::string& pickupLocation, double pickupLatitude, double pickupLongitude,
        const std::string& dropoffLocation, double dropoffLatitude, double dropoffLongitude,
        const std::string& vehiclePreference, std::string currentState,
        const std::string& assignedDriverFirstName, const std::string& assignedDriverLastName,
        const std::string& assignedDriverPhoneNumber);


    //Accessors
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getAge() const;
    std::string getRider_Phone() const;
    double getRating() const;
    std::string getPickupLocation() const;
    double getPickupLatitude() const;
    double getPickupLongitude() const;
    std::string getDropoffLocation() const;
    double getDropoffLatitude() const;
    double getDropoffLongitude() const;
    std::string getVehiclePreference() const;
    std::string getCurrentState() const;
    std::string getAssignedDriverFirstName() const;
    std::string getAssignedDriverLastName() const;
    std::string getAssignedDriverPhoneNumber() const;


    //Mutators
    void setFirstName(const std::string& newFirstName);
    void setLastName(const std::string& newLastName);
    void setGender(const std::string& newGender);
    void setAge(int newAge);
    void setCurrent_state(const std::string& newState);
    void setAssignedDriver(const std::string& driverFirstName, const std::string& driverLastName,const std::string& driverPhoneNumber);
    void setPickupLocation(const std::string& newPickupLocation);
    void setPickupLatitude(double newPickupLatitude);
    void setPickupLongitude(double newPickupLongitude);
    void setDropoffLocation(const std::string& newDropoffLocation);
    void setDropoffLatitude(double newDropoffLatitude);
    void setDropoffLongitude(double newDropoffLongitude);
    void setVehiclePreference(const std::string& newVehiclePreference);
    void setRating(double newRating);


    private:
    //private variables and member variables
        std::string firstName;
        std::string lastName;
        std::string gender;
        int age;
        std::string phoneNumber;
        double rating;
        std::string pickupLocation;
        double pickupLatitude;
        double pickupLongitude;
        std::string dropoffLocation;
        double dropoffLatitude;
        double dropoffLongitude;
        std::string vehiclePreference;
        std::string currentState;
        std::string assignedDriverFirstName;
        std::string assignedDriverLastName;
        std::string assignedDriverPhoneNumber;
    };

class Driver{

    public: 
    //cosnturctor information

    Driver();
    Driver(const std::string& firstName, const std::string& lastName, const std::string& gender,
        int age, const std::string& phoneNumber, double rating,
        double latitude, double longitude, const std::string& vehicleType,
        const std::string& currentState, const std::string& assignedRiderFirstName,
        const std::string& assignedRiderLastName, const std::string& assignedRiderPhoneNumber);

    //Accessors
    std::string getDriverFirstName() const;
    std::string getDriverLastName() const;
    std::string getDriverGender() const;
    int getAge() const;
    std::string getDriver_Phone() const;
    double getRating() const;
    double getLatitude() const;
    double getLongitude() const;
    std::string getVehicleType() const;
    std::string getCurrentState() const;
    std::string getAssignedRiderFirstName() const;
    std::string getAssignedRiderLastName() const;
    std::string getAssignedRiderPhoneNumber() const;

    //Mutators
    void setDriverFirstName(const std::string& newFirstName);
    void setDriverLastName(const std::string& newLastName);
    void setDriverGender(const std::string& newGender);
    void setAge(int newAge);
    void setDriver_Phone(const std::string& newPhoneNumber);
    void setCurrent_state(const std::string& newState);
    void setAssignedRider(const std::string& riderFirstName, const std::string& riderLastName,const std::string& riderPhoneNumber);
    void setLatitude(double newDriverLatitude);
    void setLongitude(double newDriverLongitude);
    void setVehicleType(const std::string& newVehicleType);
    void setRating(double newRating);



    

    private:
    //private variables and member variables
    std::string firstName;
    std::string lastName;
    std::string gender;
    int age;
    std::string phoneNumber;
    double rating;
    double latitude;
    double longitude;
    std::string vehicleType;
    std::string currentState;
    std::string assignedRiderFirstName;
    std::string assignedRiderLastName;
    std::string assignedRiderPhoneNumber;
};


