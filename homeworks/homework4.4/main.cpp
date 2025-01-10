#include <iostream>
#include <fstream>  
#include <string>
#include <list>
#include "yelp.h"
using namespace std;
#include <vector>

//Declare the functions from the Restaurant class
std::string getNameJson(std::string& line){
        int start = 0;
        // starting from the position start, and search the string variable line,
        // to find the first name string.
        int key_start = line.find("name", start);
        int value_start = key_start + 7;
        // remember to use escape.
        int value_end = line.find("\"", value_start);
        int len = value_end - value_start;
        // go from start to end, but exclude the character at end.
        // when we use the substr(start, length) function on a std::string,
        // the substring includes the character at the start position,
        // and the length of the substring is length.
        // It does not include the character at the position start + length.
        std::string name = line.substr(value_start, len);
        return name;
}
std::string getCategoriesJson(std::string& line){
        int start = 0;
        // starting from the position start, and search the string variable line,
        // to find the first categories string.
        int key_start = line.find("categories", start);
        int value_start = key_start + 13;
        // remember to use escape.
        int value_end = line.find("\"", value_start);
        int len = value_end - value_start;
        // go from start to end, but exclude the character at end.
        // when we use the substr(start, length) function on a std::string,
        // the substring includes the character at the start position,
        // and the length of the substring is length.
        // It does not include the character at the position start + length.
        std::string categories = line.substr(value_start, len);

        return categories;
}
double getRatingJson(std::string& line){
        int start = 0;
        // starting from the position start, and search the string variable line,
        // to find the first stars string.
        int key_start = line.find("stars", start);
        int value_start = key_start + 7;
        // remember to use escape.
        int value_end = line.find("\"", value_start);
        // -1 here because this is not a string.
        int len = value_end - value_start - 1;
        // go from start to end, but exclude the character at end.
        // when we use the substr(start, length) function on a std::string,
        // the substring includes the character at the start position,
        // and the length of the substring is length.
        // It does not include the character at the position start + length.
        // convert this string to a double
        double stars = stod(line.substr(value_start, len));
        return stars;
}
int getPriceJson(std::string& line){
        int start = 0;
        // starting from the position start, and search the string variable line,
        // to find the first RestaurantsPriceRange2 string.
        int key_start = line.find("RestaurantsPriceRange2", start);
        // if not found, return now
        if(key_start == std::string::npos){
                return -1;
        }
        int value_start = key_start + 25;
        // remember to use escape.
        int value_end = line.find("\"", value_start);
        // -1 here because this is not a string.
        int len = value_end - value_start;
        // go from start to end, but exclude the character at end.
        // when we use the substr(start, length) function on a std::string,
        // the substring includes the character at the start position,
        // and the length of the substring is length.
        // It does not include the character at the position start + length.
        // convert this string to an integer
        int price;
        if(line.substr(value_start, len) == "None"){
            return -1;
        }else{
            price = stoi(line.substr(value_start, len));
        }
        return price;
}

std::string getZipcodeJson(std::string& line){
        int start = 0;
        // starting from the position start, and search the string variable line,
        // to find the first postal_code string.
        int key_start = line.find("postal_code", start);
        int value_start = key_start + 14;
        // remember to use escape.
        int value_end = line.find("\"", value_start);
        int len = value_end - value_start;
        // go from start to end, but exclude the character at end.
        // when we use the substr(start, length) function on a std::string,
        // the substring includes the character at the start position,
        // and the length of the substring is length.
        // It does not include the character at the position start + length.
        std::string postal_code = line.substr(value_start, len);
        return postal_code;
}

std::string getCityJson(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first city string.
    int key_start = line.find("city", start);
    int value_start = key_start + 7;
    // remember to use escape.
    int value_end = line.find("\"", value_start);
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    std::string city = line.substr(value_start, len);
    return city;
}

// create a function that finds the number of reviews for each restuarant
int numReviews(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first review_count string.
    int key_start = line.find("review_count", start);
    int value_start = key_start + 14;
    // remember to use escape.
    int value_end = line.find(",", value_start);
    // -1 here because this is not a string.
    int len = value_end - value_start;
    // go from start to end, but exclude the character at end.
    // when we use the substr(start, length) function on a std::string,
    // the substring includes the character at the start position,
    // and the length of the substring is length.
    // It does not include the character at the position start + length.
    // convert this string to an integer
    int review_count = stoi(line.substr(value_start, len));
    return review_count;
}

//parse the json input file
void parseJson(std::string& line, std::list<yelp>& restaurants){
    //setting the values of the restuarant
    std::string name = getNameJson(line);
    std::string categories = getCategoriesJson(line);
    double rating = getRatingJson(line);
    int price = getPriceJson(line);
    std::string zipcode = getZipcodeJson(line);
    std::string city = getCityJson(line);
    int reviews = numReviews(line);

    //create a restuarant object
    yelp restaurant(name, categories, rating, price, zipcode, city , reviews);
    restaurants.push_back(restaurant);
}

//check if the restuarant matches any of the resturant criteria from a list from
// all the restuarants 
void restaurantMatch(std::list<yelp>& restaurants, std::string& zipcode, 
std::vector<std::string>& category, std::list<yelp>& output){
    
    for(yelp restaurant : restaurants){
        //using the zipcode and the category to find the restuarants that
        // match the criteria
        if(restaurant.getZipCode() == zipcode){
            std::string line = restaurant.getCategories();
            for(int i = 0; i< category.size(); i++){
                if(line.find(category[i]) != std::string::npos){
                    output.push_back(restaurant);
                    break;
                }
            }
        }
        
    }
    
}


//main function
int main(int argc, char* argv[]){
    if(argc < 5){
        cout << "Usage: " << argv[0] << " <input file> <output file> <price>"
        << endl;
        return 1;

    }
    //setting the arguments
    std::string input_file = argv[1];
    std::string output_file = argv[2];
    std::string zipcode = argv[3];
    std::vector<std::string> category;

    for(int i = 4; i < argc; i++){
        category.push_back(argv[i]);
    }

    //open the input file
    std::ifstream inputFile(input_file);
    if(!inputFile){
        std::cout << "Error: Unable to open " << input_file << endl;
        return 1;
    }

    //open the output file
    std::ofstream outputFile(output_file);
    if(!outputFile){
        std::cout << "Error: Unable to open " << output_file << endl;
        return 1;
    }

    //Reading each line from the json input file
    //add all catagories of all resturants to a list from the input file
    std::string line; 
    std::list<yelp> restaurants;
    while(getline(inputFile, line)){
        //creating an object of the Restaurant class
        parseJson(line, restaurants);
        for (yelp restaurant : restaurants){
            //std::cout << restaurant.getName() << endl;

        }
        //std::cout <<restaurants.size() << endl;
    }
    std::list<yelp> matchedRestaurants;
    restaurantMatch(restaurants, zipcode, category, matchedRestaurants);
    matchedRestaurants.sort(sortRestaurantsByRating);

    std::cout << matchedRestaurants.size() << endl;
    /* The above code is using the C++ cout statement to print the value of 
    //the first element in
    the matchedRestaurants array, followed by a newline character. */
    
    
    //print out list of restuarants that match the criteria
    //sortRestaurants(matchedRestaurants);
    std::cout << "test7" << endl;
    //sorting the buisness by the rating
    int i = 1; // Initialize counter variable
    if (matchedRestaurants.size() == 0){
            outputFile << "Sorry, we couldn't find any results" << endl;
            
    }
    else 
    {
        std::cout << "test2" << endl;
        std::list<yelp>::iterator it = matchedRestaurants.begin();
        outputFile << "====================="<<endl;
        while(it != matchedRestaurants.end()){
            yelp restaurant = *it;
            outputFile << i << ". " << restaurant.getName() << endl;
            //put rating in the form of the stars
            
            //getting the rating and number of reviews
            for(int i = 0; i < (int)restaurant.getRating(); i++){
                    outputFile << "\u2605";
                }
            if((int)(restaurant.getRating()*10) % 10 == 5){
                outputFile << "\u00BD";
            }
            outputFile << " " << restaurant.getRating() << " ("  
            << restaurant.getNumReviews() << " reviews)" << endl; 
            outputFile << restaurant.getCity() << " "; 

            //for price based on the number of dollar signs from the
            // RestaurantsPriceRange2
            for(int i = 0; i < restaurant.getPrice(); i++){
                outputFile << "$";
            }
            outputFile << endl;
            outputFile<< restaurant.getCategories() << endl;
            
            outputFile << "====================="<<endl;

            i++; // Increment counter variable
            ++it; // Increment iterator
            }
        }
    

    
    
}
