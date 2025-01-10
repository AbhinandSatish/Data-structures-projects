
#include <string>

class yelp {

public:
    // Default constructor
    yelp();
    // Parameterized constructor
    yelp(std::string name, std::string categories, double rating, int price, std::string zipcode, std::string city , int numReviews);


    // Accessors
    std::string getName() const;
    std::string getCategories() const;
    double getRating() const;
    int getPrice() const;
    std::string getZipCode() const;
    std::string getCity() const;
    int getNumReviews() const;



private:
    std::string name;
    std::string categories;
    double rating;
    int price;
    std::string zipcode;
    std::string city;
    int numReviews;

};

bool sortRestaurantsByRating(const yelp& a, const yelp& b);


