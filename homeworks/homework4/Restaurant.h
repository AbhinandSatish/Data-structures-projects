
#include <string>

class Restaurant {

public:
    // Default constructor
    Restaurant();
    // Parameterized constructor
    Restaurant(std::string name, std::string categories, double rating, int price);

    // Accessors
    std::string getName() const;
    std::string getCategories() const;
    double getRating() const;
    int getPrice() const;



private:
    std::string name;
    std::string categories;
    double rating;
    int price;

};


