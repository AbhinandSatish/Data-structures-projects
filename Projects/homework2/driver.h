#ifndef DRIVER_H
#define DRIVER_H
#include <ostream>



                                                                                                                        
class Driver{

    public:
    //constructor information
    Driver();
    Driver(std::string driverFirstname, std::string driverLastname, std::string driverGender,
    std::string driverAge, std::string driverPhoneNumber,std::string driverRating,
    double driverLatitude, 
    double driverLongitude,
    std::string driverVehicleType, std::string driverCurrentState, std::string DassignedRiderFirstName,
    std::string DassignedRiderLastName, 
    std::string DassignedRiderPhoneNumber);

    //Accessors
    std::string getDriverFirstName() const;
    std::string getDriverLastName() const;
    std::string getDriverGender() const;
    std::string getDriverage() const;
    std::string getDriver_Phone() const;
    std::string getDriverRating() const;
    double getDriverLatitude() const;
    double getDriverLongitude() const;
    std::string getVehicleType() const;
    std:: string getDriverstate();
    std:: string getDassignedRiderFirstName();
    std:: string getDassignedRiderLastName();
    std:: string getDassignedRiderPhoneNumber();



    //Mutators
    void setDriverstate(std::string newDriverstate);
    void setDassignedRiderFirstName(std::string newDassignedRiderFirstName);
    void setDassignedRiderLastName(std::string newDassignedRiderLastName);
    void setDassignedRiderPhoneNumber(std::string newDassignedRiderPhoneNumber);


    private:
    //private variables and member variables
    std::string driverFirstname;
    std::string driverLastname;
    std::string driverGender;
    std::string driverAge;
    std::string driverPhoneNumber;
    std::string driverRating;
    double driverLatitude;
    double driverLongitude;
    std::string driverVehicleType;
    std::string driverCurrentState;
    std::string DassignedRiderFirstName;
    std::string DassignedRiderLastName;
    std::string DassignedRiderPhoneNumber;


};
#endif 