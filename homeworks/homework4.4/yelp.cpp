#include "yelp.h"
#include <iostream>
#include <cmath>
using namespace std;
#include <string>
#include <list>

// Default constructor
yelp::yelp(){}

// Parameterized constructor
yelp::yelp(std::string name, std::string categories, double rating, int price, std::string zipcode,
            std::string city, int numReviews) {
//setting the values of the private variables
    this->name = name;
    this->categories = categories;
    this->rating = rating;
    this->price = price;
    this->zipcode = zipcode;
    this->city = city;
    this->numReviews = numReviews;
    

}
//here are the follwoing getters
std::string yelp::getName() const {
    return name;
}

std::string yelp::getCategories() const {
    return categories;
}



double yelp::getRating() const {
    return rating;
}



int yelp::getPrice() const {
    return price;
}

std::string yelp::getZipCode() const {
    return zipcode;
}

std::string yelp::getCity() const {
    return city;
}

int yelp::getNumReviews() const {
    return numReviews;
}



bool sortRestaurantsByRating(const yelp& a, const yelp& b) {
    return a.getRating() > b.getRating();
}


