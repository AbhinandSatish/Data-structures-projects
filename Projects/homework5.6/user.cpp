#include "user.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

User::User(){
}

//contructor with parameters
User::User(const std::string& name,
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
            std::string& interestedGender)//added likedUsers to the constructor
            {
    this->name = name;
    this->age = stoi(age);
    this->gender = gender;
    this->phoneNumber = phoneNumber;
    this->profession = profession;
    this->school = school;
    this->latitude = stod(latitude);
    this->longitude = stod(longitude);
    this->isPremium = isPremium=="true";
    this->minAge = stoi(minAge);
    this->maxAge = stoi(maxAge);
    this->maxDistance = stoi(maxDistance);
    this->interestedGender = interestedGender;
    this->next = NULL;
            }

// Accessors
std::string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

std::string User::getGender() const
{
    return gender;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}

std::string User::getProfession()  {
    for(char &c: profession){
        if (c == '_'){
            c = ' ';
        }
    
}
    return profession;
}

std::string User::getSchool()  {
    for(char &c: school){
        if (c == '_'){
            c = ' ';
        }
    }
    return school;
}

double User::getLatitude() const {
    return latitude;
}

double User::getLongitude() const {
    return longitude;
}

bool User::getIsPremium() const {
    return isPremium;
}

int User::getMinAge() const {
    return minAge;
}

int User::getMaxAge() const {
    return maxAge;
}

int User::getMaxDistance() const {
    return maxDistance;
}

std::string User::getInterestedGender() const {
    return interestedGender;
}

std::vector<std::string> User::getLikedUsers(){
    return likedUsers;
}

std::vector<std::string>& User::getMatches(){
    return matches;
}



//function to add a user to the liked users vector
void User::addLikedUser(std::string phoneNumber){
    likedUsers.push_back(phoneNumber);
}



