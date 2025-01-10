#ifndef TINDER_H
#define TINDER_H
#include <string>
#include <list>
/*
User's name
User's age
User's gender
User's phone number
User's profession: A user can choose not to disclose their profession, and if so, this field will be Undisclosed.
User's school: A user can choose not to disclose his/her school, and if so, this field will be Undisclosed.
User's current latitude
User's current longitude
Is Premium User or not: this field will be either true or false.
User's preference on age: minimum age
User's preference on age: maximum age
User's preference on max distance (in miles). Note: this is an integer number.
User's preference on interested gender: this field can be one of these three: Male, Female, Both.
Users whom this user liked (i.e., users whom this user has swiped right on): here users are represented by phone numbers. If this user does not like anyone, then this field will be displayed as null. If this user liked multiple users, the phone numbers of these users will be displayed in this field, and these phone numbers are separated by an underscore.
*/

class TinderNode{
    public:
        tinder data;
        TinderNode* next;

        TinderNode(tinder data, TinderNode* next){
            this->data = data;
            this->next = next;
        }
};
class tinder {

public:

    //Default constructors
    tinder();
    //contructor with parameters
    tinder(std::string name,
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
            std::string likedUsers);

    // Accessors
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    std::string getPhoneNumber() const;
    std::string getProfession() const;
    std::string getSchool() const;
    double getLatitude() const;
    double getLongitude() const;
    bool getIsPremium() const;
    int getMinAge() const;
    int getMaxAge() const;
    int getMaxDistance() const;
    std::string getInterestedGender() const;
    std::string getLikedUsers() const;


private:
    TinderNode* head;
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
    std::string likedUsers;

};

#endif
