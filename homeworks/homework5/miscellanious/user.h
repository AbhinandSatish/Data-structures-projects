#ifndef user_H
#define user_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class User{
public:
    User();
    //contructor with parameters
    User(const std::string& name,
            std::string& age,
            std::string& gender,
            std::string& phoneNumber,
            std::string& profession,
            std::string& school,
            std::string& latitude,
            std::string& longitude,
            std::string& isPremium,
            std::string& minAge,
            std::string& maxAge,
            std::string& maxDistance,
            std::string& interestedGender,
            std::string& likedUsers);//added likedUsers to the constructor
    
    User* next;
    // Accessors
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    std::string getPhoneNumber() const;
    std::string getProfession() ;
    std::string getSchool() ;
    double getLatitude() const;
    double getLongitude() const;
    bool getIsPremium() const;
    int getMinAge() const;
    int getMaxAge() const;
    int getMaxDistance() const;
    std::string getInterestedGender() const;
    std::vector<std::string>& getLikedUsers();
    std::vector<std::string>& getMatches();

    // Mutators
    void addLikedUser(std::string name);
    void addMatch(std::string name);
    void printMatches();
    void printLikedUsers();
    void printUser();

private:
    //vector of strings to store the liked users
    std::vector<std::string> likedUsers;
    std::vector<std::string> matches;
    
    std::string name;
    int age;
    std::string gender;
    std::string phoneNumber;
    std::string profession;
    std::string school;
    double latitude;
    double longitude;
    bool isPremium;
    int minAge;
    int maxAge;
    int maxDistance;
    std::string interestedGender;
        
};





#endif