Main topics used here:
- Getting familiear with linked lists
- Practise using std::list
- Pactise using iterators


----------------------------------SPECIFICATION----------------------------------------

Impliment a program which allows users to discover local buisnesses. I should write a program that parces 
through the JASON file and produce an output to output.txt This output should have buisnesses that match the 
users search query

Command line

nybusninesses.exe input.json output.txt zipcode categories

input.json is the input file. In this assignment, we have several input files, but for each run of your program, it takes one input file.
output.txt is where to print your output.
zipcode indicates the zipcode of the area where the user is trying to search.
categories indicate the categories of the businesses. This argument can be one or multiple of the following:


"If multiple categories are supplied from the command line, these categories will be separated by a single space. To simplify your command line processing logic, you can assume that our test cases would only use a category if it contains one single word, and that means, we might test the category of "Pizza", "Japanese", "Barbeque", "Indian", "Chinese", but we would not test "Sushi Bars" - because it contains more than one word."

The buisnesses in the ouptut file should be sorted based on the rating of the buisness. If ratings are the same put it in the order of the input file


PRICE INFORMATION:

In Yelp, the "$" sign is commonly used to indicate the price range for businesses. It helps users quickly gauge the approximate cost of dining or using services at a particular establishment. There are four levels, represented by "$", "$$", "$$$", and "$$$$" respectively. A single "$" indicates that the business is relatively inexpensive, with prices typically ranging from low to moderate. A "$$$$" sign represents the highest price range level, indicating that the business is quite expensive.

In the input json file, the RestaurantsPriceRange2 field is used for this purpose. The value of this field ranges from 1 to 4. With 1 being the least expensive and 4 being the most expensive. Therefore, for a business whose RestaurantsPriceRange2 is 1, your program should print a "$" sign; for a business whose RestaurantsPriceRange2 is 2, your program should print a "$$" sign; etc.

If the ResturantsPriceRange2 field does not exit the function would return -1. 

HEre are the functions that are provided to us:

getname:
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

catagori
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

getratings
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

getprice
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

here is an example of the parce stuff from the json file
{"business_id":"3uvFklejzRPwEPEZQ5vHYQ","name":"Wawa","address":"100 E Old Baltimore Pike","city":"Media","state":"PA","postal_code":"19063","latitude":39.916175541,"longitude":-75.3876546369,"stars":3.5,"review_count":14,"is_open":1,"attributes":{"Alcohol":"u'none'","RestaurantsReservations":"False","RestaurantsTakeOut":"True","OutdoorSeating":"False","GoodForKids":"True","RestaurantsGoodForGroups":"False","RestaurantsPriceRange2":"2","BusinessAcceptsCreditCards":"True","NoiseLevel":"u'average'","RestaurantsAttire":"u'casual'","Ambience":"{'romantic': False, 'intimate': False, 'touristy': False, 'hipster': False, 'divey': False, 'classy': False, 'trendy': False, 'upscale': False, 'casual': False}","WiFi":"u'free'","HasTV":"True","BusinessParking":"{'garage': False, 'street': True, 'validated': False, 'lot': True, 'valet': False}","BikeParking":"True","RestaurantsDelivery":"True"},"categories":"Delis, Convenience Stores, Restaurants, Food, Coffee & Tea, Sandwiches","hours":{"Monday":"0:0-0:0","Tuesday":"0:0-0:0","Wednesday":"0:0-0:0","Thursday":"0:0-0:0","Friday":"0:0-0:0","Saturday":"0:0-0:0","Sunday":"0:0-0:0"}}

The getName() function will return an std::string "Wawa".
The getCategories() function will return an std::string "Delis, Convenience Stores, Restaurants, Food, Coffee & Tea, Sandwiches".
The getRating() function will return a double number: 3.5.
The getPrice() function will return an integer number: 2.

