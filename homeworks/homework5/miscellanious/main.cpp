#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
#include <vector>
#include "user.h"
#include <sstream>
#include <cmath>
//pi
#define M_PI 3.14159265358979323846


using namespace std;


void push_back(User* &head, User*new_user);
bool areUserMatch(User* user1, User* user2);
std::vector<std::string> convertStringToVector(std::vector<std::string>& likedUsersString);
std::vector<std::string> convertStringToVector2(const std::string& likedUsersString);





//parse through the input files 


double calcualteUserDistance(double lat1, double lon1, double lat2, double lon2){
    const double radiusOfEarth = 6371.0; // Earth's radius in kilometers

    // convert latitude and longitude from degrees to radians
    lat1 *= M_PI / 180.0;
    lon1 *= M_PI / 180.0;
    lat2 *= M_PI / 180.0;
    lon2 *= M_PI / 180.0;

    // Haversine formula
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + cos(lat1) * cos(lat2) * sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    // distance in kilometers
    double distanceKM = radiusOfEarth * c;
    // convert it to distance in miles
    double distanceMiles = distanceKM * 0.621371;

    return distanceMiles;
}


//parse through the input files
void parseFile(ifstream& file, User* &head){
    std::string name,age,gender,phoneNumber,profession,school,
    latitude,longitude,isPremium,minAge,maxAge,maxDistance,interestedGender, likes;
    int *count = new int;
    *count = 0;
    while (file >> name >> age >> gender >> phoneNumber >> profession >>
            school >> latitude >> longitude >> isPremium >> minAge >> maxAge >> 
            maxDistance >> interestedGender>> likes)
    {
        //mkake the object
        //cout << likes << endl;


        User* user = new User(name,age, gender,phoneNumber, profession, 
        school, latitude, longitude, isPremium, minAge, maxAge,
        maxDistance, interestedGender, likes);

        //parse the likes
        /*
                std::istringstream iss(longString);
        std::string phoneNumber;

        // tokenize the long string using the underscore delimiter
        while (std::getline(iss, phoneNumber, '_')) {
                std::cout << phoneNumber << std::endl;
        }
        */
        std::istringstream iss(likes);
        std::string phone_temp;
        // while (std::getline(iss, phone_temp, '_')) {
        //         //cout << phone_temp << endl;
        //         user->addLikedUser(phone_temp);
        //         //cout << phone_temp << endl;
        // }
        //add users to homemade list
        push_back(head, user);
    }
}

//function to add a user to the liked users vector
//how this function works is that:
//it takes in a user and a new user and adds the new user to the end of the list
void push_back(User*& head, User* new_user){
    if (head == nullptr){
        head = new_user;
        return;
    } 
    User* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new_user;
}
//method for the profile command
void profile(User* head, std::string phone_number, std::string output_file){
    //open the output file
    ofstream file(output_file);
    if(!file){
        cerr << "Could not open file" << endl;
        return;
    }
    //find the user with the phone number
    User* temp = head;
    while(temp->next != nullptr){
        if(temp->getPhoneNumber() == phone_number){
            //print the user without using the printUser method
            // file  << temp->getName() << " " << temp->getAge() << endl;
            // file << temp-> getProfession() <<endl;
            // file<< temp->getSchool() << endl;

            // Match with other users based on age, gender, and distance
            User* match = head;
            bool hasMatches = false;
            while(match != nullptr){
                if(match != temp && match->getAge() >= temp->getMinAge() && match->getAge() <= temp->getMaxAge() &&
                    (temp->getInterestedGender() == "Both" || match->getGender() == temp->getInterestedGender()) &&
                    calcualteUserDistance(temp->getLatitude(), temp->getLongitude(), match->getLatitude(), match->getLongitude()) <= temp->getMaxDistance()){
                    file << match->getName() << " " << match->getAge() << endl;
                    if (match->getProfession() == "Undisclosed"){
                    }
                    else{
                        file << match->getProfession() << endl;
                    }
                    if (match->getSchool() == "Undisclosed"){
                    }
                    else{
                        file << match->getSchool() << endl;
                    }
                    file << "" << endl;
                    hasMatches = true;
                }
                match = match->next;

                
            }
            if(!hasMatches){
                file << "There are no users matching with your preference at this moment." << endl;
            }
            return;
        }
        temp = temp->next;
    }
    //if the user is not matched with anyone
    
    
}


//function to  check if the two uses are a match
bool areUserMatch(User* user1, User* user2) {
    // Check if user1 has liked user2 and vice versa
    for (const std::string& likedUser1 : user1->getLikedUsers()) {
        if (likedUser1 == user2->getPhoneNumber()) {
            cout << "are you here" << endl;
            // User1 has liked User2, now check if User2 has liked User1
            for (const std::string& likedUser2 : user2->getLikedUsers()) {
                if (likedUser2 == user1->getPhoneNumber()) {
                    return true;  // Both users like each other
                }
            }
        }
    }
    return false;  // No mutual like found
}



//create a method that converts the phone number of strings to a vector
std::vector<std::string> convertStringToVector(std::vector<std::string>& likedUsersString){
    std::vector<std::string> likedUsers;
    //take the first string from the vector and convert that string to a vector or strings
    for (std::string likedUser : likedUsersString){
        std::istringstream iss(likedUser);
        std::string phoneNumber;
        while (std::getline(iss, phoneNumber, '_')) {
            likedUsers.push_back(phoneNumber);
        }
    }
    return likedUsers;
}

std::vector<std::string> convertStringToVector2(const std::string& likedUsersString){
    std::vector<std::string> likedUsers;
    //take the first string from the vector and convert that string to a vector or strings
    std::istringstream iss(likedUsersString);
    std::string phoneNumber;
    while (std::getline(iss, phoneNumber, '_')) {
        likedUsers.push_back(phoneNumber);
    }
    return likedUsers;
}


void match(User* head, std::string phone_number, std::string output_file) {
    // Open the output file
    ofstream file(output_file);
    if (!file) {
        cerr << "Could not open file" << endl;
        return;
    }

    // Find the user with the given phone number
    User* currentUser = head;
    while (currentUser != nullptr) {
        if (currentUser->getPhoneNumber() == phone_number) {
            // Print the current user details
            bool hasMatches = false;
            

            // Convert the string of liked user numbers to a vector
            std::vector<std::string> likedUsers = convertStringToVector(currentUser->getLikedUsers());

            // Find users who liked the current user
            for (const std::string& likedUser : likedUsers) {
                // Print the phone number of users who liked the current user
                //file << likedUser << endl;

                // Find the details of the liked user and print them
                User* likedUserDetails = head;
                while (likedUserDetails != nullptr) {
                    if (likedUserDetails->getPhoneNumber() == likedUser) {
                        
                        // Check if there's a mutual like between the current user and the liked user iwthout using the areUserMatch method
                        //test to print out the liked users of the linkedUserDetails
                        for (std::string likedUser : likedUserDetails->getLikedUsers()){
                            //convert the vector of one string to a vector of strings
                            std::vector<std::string> likedUsers = convertStringToVector2(likedUser);
                            //now that the we can a vector of a list of the liked users of the liked user
                            //we can now check if the liked user has liked the current user
                            for (std::string likedUser : likedUsers){
                                if (likedUser == currentUser->getPhoneNumber()){
                                    file << likedUserDetails->getName() << " " << likedUserDetails->getAge() << endl;
                                    if (likedUserDetails->getProfession() != "Undisclosed") {
                                        file << likedUserDetails->getProfession() << endl;
                                    }
                                    if (likedUserDetails->getSchool() != "Undisclosed") {
                                        file << likedUserDetails->getSchool() << endl;
                                    }
                                    file << "" << endl;
                                    hasMatches = true;
                                
                                }
                            }
                        }
                    
                    
                    }
                    likedUserDetails = likedUserDetails->next;
                }
            }

            if (!hasMatches) {
                file << "You do not have any matches at this moment." << endl;
            }
            
            
        }
        currentUser = currentUser->next;
    }
}

//method to show all users who swiped right on this user
// if the user is not a premium user, then the user will not be able to see the users who swiped right on them
void like(User* head, std::string phone_number, std::string output_file){
   // Open the output file
    ofstream file(output_file);
    if (!file) {
        cerr << "Could not open file" << endl;
        return;
    }

    //current user
    User* currentUser = head;
    while(currentUser != nullptr){
        if(currentUser->getPhoneNumber() == phone_number){
            //print the current user details
            bool hasMatches = false;

            //convert the string of liked user numbers to a vector
            //std::vector<std::string> likedUsers = convertStringToVector(currentUser->getLikedUsers());
            //run through every single user in the linked list and check if in their liked list, the user is in there
            User* likedUserDetails = head;
            while(likedUserDetails != nullptr){
                for (std::string likedUser : likedUserDetails->getLikedUsers()){
                    //convert the vector of one string to a vector of strings
                    std::vector<std::string> likedUsers = convertStringToVector2(likedUser);
                    //now that the we can a vector of a list of the liked users of the liked user
                    //we can now check if the liked user has liked the current user
                    for (std::string likedUser : likedUsers){
                        if (likedUser == currentUser->getPhoneNumber()){
                            // Check if the current user is a premium user
                            if (currentUser->getIsPremium()) {
                                // Print the details of the liked user
                                file << likedUserDetails->getName() << " " << likedUserDetails->getAge() << endl;
                                if (likedUserDetails->getProfession() != "Undisclosed") {
                                    file << likedUserDetails->getProfession() << endl;
                                }
                                if (likedUserDetails->getSchool() != "Undisclosed") {
                                    file << likedUserDetails->getSchool() << endl;
                                }
                                file << "" << endl;
                                hasMatches = true;
                            } else {
                                // Print a message indicating that the current user is not a premium user
                                file << "You are not a premium user. You cannot see the users who liked you." << endl;
                                return;
                            }
                        }
                    }
                }
                likedUserDetails = likedUserDetails->next;
            }
            
    }
    }
}
// void like(User* head, std::string phone_number, std::string output_file){
//     // Open the output file
//     ofstream file(output_file);
//     if (!file) {
//         cerr << "Could not open file" << endl;
//         return;
//     }

//     // Find the user with the given phone number
//     User* currentUser = head;
//     while (currentUser != nullptr) {
//         if (currentUser->getPhoneNumber() == phone_number) {
//             // Print the current user details
//             bool hasMatches = false;

//             // Convert the string of liked user numbers to a vector
//             std::vector<std::string> likedUsers = convertStringToVector(currentUser->getLikedUsers());

//             // Find users who liked the current user
//             for (const std::string& likedUser : likedUsers) {
//                 // Find the details of the liked user and print them
//                 User* likedUserDetails = head;
//                 while (likedUserDetails != nullptr) {
//                     if (likedUserDetails->getPhoneNumber() == likedUser) {
//                         // Check if the current user is a premium user
//                         if (currentUser->getIsPremium()) {
//                             // Print the details of the liked user
//                             file << likedUserDetails->getName() << " " << likedUserDetails->getAge() << endl;
//                             if (likedUserDetails->getProfession() != "Undisclosed") {
//                                 file << likedUserDetails->getProfession() << endl;
//                             }
//                             if (likedUserDetails->getSchool() != "Undisclosed") {
//                                 file << likedUserDetails->getSchool() << endl;
//                             }
//                             file << "" << endl;
//                             hasMatches = true;
//                         } else {
//                             // Print a message indicating that the current user is not a premium user
//                             file << "You are not a premium user. You cannot see the users you liked." << endl;
//                             return;
//                         }
//                     }
//                     likedUserDetails = likedUserDetails->next;
//                 }
//             }

//             if (!hasMatches) {
//                 file << "You have not liked any users so far." << endl;
//             }
//         }
//         currentUser = currentUser->next;
//     }
// }
int main(int argc, char* argv[]){
    User* head = nullptr;
    if(argc != 5 && argc !=6){
        cerr << "Usage: " << argv[0] << " <input file> error]" << endl;
        return 1;
    }

    ifstream file((argv[1]));
    if(!file){
        cerr << "Could not open file" << endl;
        return 1;
    }
    std::string output_file = argv[2];
    std::string user_phone = argv[3];
    std::string command = argv[4];



    //parse the file
    parseFile(file, head);
    //if the command is profile
    if(command == "profile"){
        profile(head, user_phone, output_file);
    }
    else if(command == "match"){
        match(head, user_phone, output_file);
    }else if(command == "like"){
        like(head, user_phone, output_file);
    
    }




}

