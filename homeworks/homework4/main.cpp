#include <iostream>
#include <fstream>  
#include <string>
#include <list>
#include "Restaurant.h"
using namespace std;

//Declare the functions from the Restaurant class


std::string getName(std::string& line){
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
std::string getCategories(std::string& line){
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
double getRating(std::string& line){
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
int getPrice(std::string& line){
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
        int price = stoi(line.substr(value_start, len));
        return price;
}

//parse the json input file
void parseJson(std::string& line, std::list<Restaurant>& restaurants){
    std::string name = getName(line);
    std::string categories = getCategories(line);
    double rating = getRating(line);
    int price = getPrice(line);
    Restaurant restaurant(name, categories, rating, price);
    restaurants.push_back(restaurant);
}

//check if the restuarant matches any of the resturant criteria from a list from all the restuarants 
std::list<Restaurant> restaurantMatch(std::list<Restaurant>& restaurants, std::string zipcode, std::string category){
    std::list<Restaurant> matchedRestaurants;
    for(const auto& restaurant : restaurants){
        if(restaurant.getCategories() == category){
            matchedRestaurants.push_back(restaurant);
        }
    }
    return matchedRestaurants;
}

//sort the restuarants by the rating
void sortRestaurants(std::list<Restaurant>& restaurants){
    restaurants.sort([](const Restaurant& a, const Restaurant& b){
        return a.getRating() > b.getRating();
    });
}

// create a function that finds the number of reviews for each restuarant
int numReviews(std::string& line){
    int start = 0;
    // starting from the position start, and search the string variable line,
    // to find the first review_count string.
    int key_start = line.find("review_count", start);
    int value_start = key_start + 15;
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

int main(int argc, char* argv[]){
    if(argc < 5){
        cout << "Usage: " << argv[0] << " <input file> <output file> <price>" << endl;
        return 1;

    }
    std::string input_file = argv[1];
    std::string output_file = argv[2];
    std::string zipcode = argv[3];
    std::string category = argv[4];

    //open the input file
    std::ifstream inputFile(input_file);
    if(!inputFile){
        cout << "Error: Unable to open " << input_file << endl;
        return 1;
    }

    //open the output file
    std::ofstream outputFile(output_file);
    if(!outputFile){
        cout << "Error: Unable to open " << output_file << endl;
        return 1;
    }

    //Reading each line from the json input file
    std::string line;
    std::list<Restaurant> restaurants;
    while(getline(inputFile, line)){
        //creating an object of the Restaurant class
        parseJson(line, restaurants);

        //check if the restuarnt matches the citeria using the resturant match function
        std::list<Restaurant> matchedRestaurants = restaurantMatch(restaurants, zipcode, category);

        //sorting the buisness by the rating
        int i = 1; // Initialize counter variable
        for(const auto& restaurant : restaurants){
            outputFile << "====================="<<endl;
            outputFile << i << ". " << restaurant.getName() << endl;
            //put rating in the form of the stars
            //std::cout << "\u2605" << std::endl;
            //if half start use this:
            //std::cout << "\u00BD" << std::endl;
            for(int i = 0; i < restaurant.getRating(); i++){
                if (i % 1 == 0){
                    outputFile << "\u2605";
                }
                else{
                    outputFile << "\u00BD";
                }
            }
            //print out rating and number of reviews
            outputFile << " " << restaurant.getRating() << " "  << numReviews(line) << " reviews" << endl;
            //outputFile << restaurant.getAddress() << " " << endl;
            //for price based on the number of dollar signs from the RestaurantsPriceRange2
            for(int i = 0; i < restaurant.getPrice(); i++){
                outputFile << "$";
            }
            outputFile << endl;
            outputFile << restaurant.getCategories() << endl;
            outputFile << "====================="<<endl;

            i++; // Increment counter
        }

    }
    inputFile.close();
    outputFile.close();
    return 0;

}