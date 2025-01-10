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
bool checkUserlikes(User* user1, User* user2);




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
        maxDistance, interestedGender);

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
        while (std::getline(iss, phone_temp, '_')) {
                //cout << phone_temp << endl;
                user->addLikedUser(phone_temp);
                //cout << phone_temp << endl;
        }
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
void profile(User* head, std::string phone_number, ofstream& output_file){
    //open the output file
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
                    output_file << match->getName() << " " << match->getAge() << endl;
                    if (match->getProfession() == "Undisclosed"){
                    }
                    else{
                        output_file << match->getProfession() << endl;
                    }
                    if (match->getSchool() == "Undisclosed"){
                    }
                    else{
                        output_file << match->getSchool() << endl;
                    }
                    output_file << "" << endl;
                    hasMatches = true;
                }
                match = match->next;

                
            }
            if(!hasMatches){
                output_file << "There are no users matching with your preference at this moment." << endl;
            }
            return;
        }
        temp = temp->next;
    }
    //if the user is not matched with anyone
    
    
}
std::vector<string> profileRemove(User* head, std::string phone_number, ofstream& output_file){
    //open the output file
    //find the user with the phone number
    std::vector<string> matches;
    User* temp = head;
    while(temp->next != nullptr){
        if(temp->getPhoneNumber() == phone_number){
            
            // Match with other users based on age, gender, and distance
            User* match = head;
            bool hasMatches = false;
            while(match != nullptr){
                if(match != temp && match->getAge() >= temp->getMinAge() && match->getAge() <= temp->getMaxAge() &&
                    (temp->getInterestedGender() == "Both" || match->getGender() == temp->getInterestedGender()) &&
                    calcualteUserDistance(temp->getLatitude(), temp->getLongitude(), match->getLatitude(), match->getLongitude()) <= temp->getMaxDistance()){
                    
                    matches.push_back(match->getPhoneNumber());
                    hasMatches = true;
                }
                match = match->next;

                
            }
            
            return;
        }
        temp = temp->next;
    }
    return matches;
    
}




void match(User* head, std::string phone_number, ofstream& output_file){
    // Open the output file
    
    //sort through head in an increasing order based on their phone number
    //since they are string convert the first three characters to an integer and then sort them, if they are the same the convert the next three characters to an integer and then sort them
    //if they are the same then convert the next three characters to an integer and then sort them

    
    // Find the user with the given phone number
    User* current = head;
    bool found = false;
    User* currentUser = nullptr;
    while (current != nullptr) {

        if (current->getPhoneNumber() == phone_number) {
            currentUser = current;
            break;
        }
        current= current->next;
    }
    current = head;
    vector<string> currentUserLikes = currentUser->getLikedUsers();
    while(current)
    {
        string potentialPhone = current->getPhoneNumber();
        vector<string> potentialMatches = current->getLikedUsers();
        for(int i = 0; i < potentialMatches.size(); i++){
            if(potentialMatches[i] == phone_number){
                for(string& s: currentUserLikes){
                    if(s == potentialPhone){
                        output_file << current->getName() << " " << current->getAge() << endl;
                        if (current->getProfession() == "Undisclosed"){
                        }
                        else{
                            output_file << current->getProfession() << endl;
                        }
                        if (current->getSchool() == "Undisclosed"){
                        }
                        else{
                            output_file << current->getSchool() << endl;
                        }
                        output_file << "" << endl;
                        bool found = true;
                        
                        
                    }
                }
                
            }
        }
        current = current->next;
    }
    if(!found){
        output_file << "There are no users matching with your preference at this moment." << endl;
    }
}

std::vector<string> matchedlist(User* head, std::string phone_number, ofstream& output_file){
    // Open the output file
    
    //sort through head in an increasing order based on their phone number
    //since they are string convert the first three characters to an integer and then sort them, if they are the same the convert the next three characters to an integer and then sort them
    //if they are the same then convert the next three characters to an integer and then sort them

    
    // Find the user with the given phone number
    std::vector<string> matches;
    User* current = head;
    bool found = false;
    User* currentUser = nullptr;
    while (current != nullptr) {

        if (current->getPhoneNumber() == phone_number) {
            currentUser = current;
            break;
        }
        current= current->next;
    }
    current = head;
    vector<string> currentUserLikes = currentUser->getLikedUsers();
    while(current)
    {
        string potentialPhone = current->getPhoneNumber();
        vector<string> potentialMatches = current->getLikedUsers();
        for(int i = 0; i < potentialMatches.size(); i++){
            if(potentialMatches[i] == phone_number){
                for(string& s: currentUserLikes){
                    if(s == potentialPhone){
                        //psuhback to the vector over here
                        matches.push_back(current->getPhoneNumber());
                    }
                }
                
            }
        }
        current = current->next;
    }
    return matches;
    
}

void like(User* head, std::string phone_number, ofstream& output_file){

    //run through the vector of liked phone numbers and then see if the user is in the liked users list of the liked user

    // Find the user with the given phone number
    User* current = head;
    User* currentUser = nullptr;
    while (current != nullptr) {
        if (current->getPhoneNumber() == phone_number) {
            currentUser = current;
            break;
        }
        current = current->next;
    }
    current = head;
    //run through the file and see if the getLikedUser is == to current->getPhoneNumber
    //run through the file
    //if premium or not
    //if not premium then output << "You must be a premium user to use this feature." << endl;

    if(!currentUser->getIsPremium()){
        output_file << "You must be a premium user to use this feature." << endl;
        return;
    }else{
    while(current){
        //run through the liked users list of all the users
        for(string& s: current->getLikedUsers()){
            
                if(s == phone_number){
                output_file << current->getName() << " " << current->getAge() << endl;
                if (current->getProfession() == "Undisclosed"){
                }
                else{
                    output_file << current->getProfession() << endl;
                }
                if (current->getSchool() == "Undisclosed"){
                }
                else{
                    output_file << current->getSchool() << endl;
                }
                output_file << "" << endl;
            }
            
        }
        current = current->next;
    }
}
}

void unmatched(User* head, std::string phone_number,std::string other_phone_number, ofstream& output_file){
    // Find the user with the given phone number
    std::vector<string> matched = matchedlist(head, phone_number, output_file);
    User* current = head;
    User* currentUser = nullptr;
    while (current != nullptr) {
        if (current->getPhoneNumber() == phone_number) {
            currentUser = current;
            break;
        }
        current = current->next;
    }
    
    //find the other user with the given phone number
    std::vector<string> matchedOther = matchedlist(head, other_phone_number, output_file);
    current = head;
    User* otherUser = nullptr;
    while (current != nullptr) {
        if (current->getPhoneNumber() == other_phone_number) {
            otherUser = current;
            break;
        }
        current = current->next;
    }

    //run through the vector of matched users and then remove the other user from the matched users list of the current user
    for(int i = 0; i < matched.size(); i++){
        if(matched[i] == other_phone_number){
            matched.erase(matched.begin() + i);
        }
    }
    //run through the vector of matched users and then remove the current user from the matched users list of the other user
    for(int i = 0; i < matchedOther.size(); i++){
        if(matchedOther[i] == phone_number){
            matchedOther.erase(matchedOther.begin() + i);
        }
    }
    

    //print the users that are left in the matched users list
    output_file << currentUser->getName() << "'s match list:" << endl;
    output_file << "" << endl;
    //find the users for each of numbers in the matced list
    for(string& s: matched){
        
        User* temp = head;
        while(temp != nullptr){
            if(temp->getPhoneNumber() == s){
                output_file << temp->getName() << " " << temp->getAge() << endl;
                if (temp->getProfession() == "Undisclosed"){
                }
                else{
                    output_file << temp->getProfession() << endl;
                }
                if (temp->getSchool() == "Undisclosed"){
                }
                else{
                    output_file << temp->getSchool() << endl;
                }
                output_file << "" << endl;
            }
            temp = temp->next;
        }
    }
        output_file << "======"<<endl;
        //print the users for the other users matched list
        output_file << otherUser->getName() << "'s match list:" << endl;
        output_file << "" << endl;

        for(string& s: matchedOther){
            User* temp = head;
            while(temp != nullptr){
                if(temp->getPhoneNumber() == s){
                    output_file << temp->getName() << " " << temp->getAge() << endl;
                    if (temp->getProfession() == "Undisclosed"){
                    }
                    else{
                        output_file << temp->getProfession() << endl;
                    }
                    if (temp->getSchool() == "Undisclosed"){
                    }
                    else{
                        output_file << temp->getSchool() << endl;
                    }
                    output_file << "" << endl;
                }
                temp = temp->next;
            }
        }
}

void blockUser(User* head, std::string phone_number, std::string other_phone_number, ofstream& output_file){
    // Find the user with the given phone number
    cout << "are you here block profile" << endl;
    std::vector<string> block  = profileRemove(head, phone_number, output_file);
    User* current = head;
    User* currentUser = nullptr;
    while (current != nullptr) {
        if (current->getPhoneNumber() == phone_number) {
            currentUser = current;
            break;
        }
        current = current->next;
    }

    //find the other user with the given phone number
    std::vector<string> blockOther = profileRemove(head, other_phone_number, output_file);
    current = head;
    User* otherUser = nullptr;
    while (current != nullptr) {
        if (current->getPhoneNumber() == other_phone_number) {
            otherUser = current;
            break;
        }
        current = current->next;
    }

    //run through the vector of matched users and then remove the other user from the matched users list of the current user
    for(int i = 0; i < block.size(); i++){
        if(block[i] == other_phone_number){
            block.erase(block.begin() + i);
        }
    }
    //run through the vector of matched users and then remove the current user from the matched users list of the other user
    for(int i = 0; i < blockOther.size(); i++){
        if(blockOther[i] == phone_number){
            blockOther.erase(blockOther.begin() + i);
        }
    }

    //print users that are left in the profil block list
    output_file << "profiles shown to " << currentUser->getName() << ":" << endl;
    output_file << "" << endl;
    //find the users for each of numbers in the matced list
    for(string& s: block){
        
        User* temp = head;
        while(temp != nullptr){
            if(temp->getPhoneNumber() == s){
                output_file << temp->getName() << " " << temp->getAge() << endl;
                if (temp->getProfession() == "Undisclosed"){
                }
                else{
                    output_file << temp->getProfession() << endl;
                }
                if (temp->getSchool() == "Undisclosed"){
                }
                else{
                    output_file << temp->getSchool() << endl;
                }
                output_file << "" << endl;
            }
            temp = temp->next;
        }
    }
        output_file << "======"<<endl;
        //print the users for the other users matched list
        output_file << "profiles shown to " << otherUser->getName() << ":" << endl;
        output_file << "" << endl;

        for(string& s: blockOther){
            User* temp = head;
            while(temp != nullptr){
                if(temp->getPhoneNumber() == s){
                    output_file << temp->getName() << " " << temp->getAge() << endl;
                    if (temp->getProfession() == "Undisclosed"){
                    }
                    else{
                        output_file << temp->getProfession() << endl;
                    }
                    if (temp->getSchool() == "Undisclosed"){
                    }
                    else{
                        output_file << temp->getSchool() << endl;
                    }
                    output_file << "" << endl;
                }
                temp = temp->next;
            }
        }
    
}


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
    ofstream output_file(argv[2]);
    if(!output_file){
        cerr << "Could not open file" << endl;
        return 1;
    }
    std::string user_phone = argv[3];
    std::string command = string(argv[4]);
    

        cout << "are you here-3" << endl;
        cout <<"test" << command << endl;
    //parse the file
    parseFile(file, head);
    //if the command is profile
    if(command == "profile"){
        profile(head, user_phone, output_file);
    }
    else if(command == "match"){
        match(head, user_phone, output_file);
    }
    else if(command == "like"){
        like(head, user_phone, output_file);
    
    }else if(command == "unmatch" && argc == 6){
        cout << "are you here2" << endl;
        std::string other_phone = argv[5];
        unmatched(head, user_phone, other_phone, output_file);
    }
    
    else if(command == "block" && argc == 6){
        cout<<"is block here" << endl;
        std::string other_phone = argv[5];
        blockUser(head, user_phone, other_phone, output_file);
    }
    
}

