#include "Restaurant.h"
#include <iostream>
#include <cmath>
using namespace std;
#include <string>
#include <list>


Restaurant::Restaurant(){}

Restaurant::Restaurant(std::string name, std::string categories, double rating, int price) {
    name = name;
    categories = categories;
    rating = rating;
    price = price;
    

}

std::string Restaurant::getName() const {
    return name;
}

std::string Restaurant::getCategories() const {
    return categories;
}



double Restaurant::getRating() const {
    return rating;
}



int Restaurant::getPrice() const {
    return price;
}


/*
bool Restaurant::operator==(const Restaurant& other) const {
    return name == other.name && categories == other.categories && rating == other.rating && price == other.price;
}*/
