#include "tinder.h"
#include <iostream>
#include <string>
#include <list>


tinder::tinder(){
    head = nullptr;
}

tinder::tinder(std::string name,
            int age,
            std::string gender,
            std::string phoneNumber,
            std::string profession,
            std::string school,
            double latitude,
            double longitude,
            bool isPremium,
            int minAge,
            int maxAge,
            int maxDistance,
            std::string interestedGender,
            std::string likedUsers){
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->phoneNumber = phoneNumber;
    this->profession = profession;
    this->school = school;
    this->latitude = latitude;
    this->longitude = longitude;
    this->isPremium = isPremium;
    this->minAge = minAge;
    this->maxAge = maxAge;
    this->maxDistance = maxDistance;
    this->interestedGender = interestedGender;
    this->likedUsers = likedUsers;
            }

//accessors
std::string tinder::getName() const {
    return name;
}

int tinder::getAge() const {
    return age;
}

std::string tinder::getGender() const{
    return gender;
}

std::string tinder::getPhoneNumber() const {
    return phoneNumber;
}

std::string tinder::getProfession() const {
    return profession;
}

std::string tinder::getSchool() const {
    return school;
}

double tinder::getLatitude() const {
    return latitude;
}

double tinder::getLongitude() const {
    return longitude;
}

bool tinder::getIsPremium() const {
    return isPremium;
}

int tinder::getMinAge() const {
    return minAge;
}

int tinder::getMaxAge() const {
    return maxAge;
}

int tinder::getMaxDistance() const {
    return maxDistance;
}

std::string tinder::getInterestedGender() const {
    return interestedGender;
}

std::string tinder::getLikedUsers() const {
    return likedUsers;
}

