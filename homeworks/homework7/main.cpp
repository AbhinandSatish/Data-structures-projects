#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <list>
#include <regex>
using namespace std;

//putting the function prototypes here
std::list<std::string> extractLinksFromHTML(const std::string& fileContent);
std::map<std::string, std::string> extractInfoFromHTML(const std::string& fileContent);
std::string read_file(const std::string& filename);

/*
USEFUL STRING FUNCTIONS for the homework;
size_t periodPos = data.rfind(".", queryPos); 
size_t start = data.rfind("http", queryPos);


std::string directory;
// suppose URL is "html_files/subdir1/subdir2/file7.html"
size_t lastSlashPos = URL.find_last_of('/');
if (lastSlashPos != std::string::npos) {
	// directory will now be "html_files/subdir1/subdir2/"
	directory = URL.substr(0, lastSlashPos + 1);
}

*/

/*
HTML file infomations:
<meta name="description" content="Boston Celtics Scores, Stats and Highlights">
<title>ESPN</title>

IF you have the stuff in the ouput files we need to output key word to its own output file in this formmat;
the title
the url
the description
a snippet

*/

/*
std::ifstream fileStream(filePath);
if (fileStream.is_open()) {
	std::string fileContent((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	// suppose filePath is the string "html_files/subdir1/file3.html", then at this point, the string fileContent will be the full content of this file file3.html.
	// do something with fileContent
}
*/

//function to parse an HITML file and extrack the links to local files
// function to parse an HTML file and extract links to local files
std::list<std::string> extractLinksFromHTML(const std::string& fileContent) {
    std::list<std::string> links;
    // regular expression to match href attributes in anchor tags
    std::regex linkRegex("<a\\s+[^>]*href\\s*=\\s*['\"]([^'\"]+)['\"][^>]*>");
    std::smatch match;

    // search for links in the HTML content
    std::string::const_iterator start = fileContent.cbegin();
    while (std::regex_search(start, fileContent.cend(), match, linkRegex)) {
        if (match.size() > 1) {
            links.push_back(match[1].str());

        }
        start = match.suffix().first;

    }
    
    return links;
}

//create a recursive function that goes through the links and extracts the following links from those files and so on

//function to extract the title, description, and snippet from an HTML file
std::map<std::string, std::string> extractInfoFromHTML(const std::string& fileContent) {
    std::map<std::string, std::string> info;
    // regular expressions to match the title and description
    std::regex titleRegex("<title>([^<]+)</title>");
    std::regex descriptionRegex("<meta\\s+[^>]*name\\s*=\\s*['\"]description['\"][^>]*content\\s*=\\s*['\"]([^'\"]+)['\"][^>]*>");
    std::smatch match;

    // search for the title in the HTML content
    if (std::regex_search(fileContent, match, titleRegex) && match.size() > 1) {
        info["title"] = match[1].str();
    }

    // search for the description in the HTML content
    if (std::regex_search(fileContent, match, descriptionRegex) && match.size() > 1) {
        info["description"] = match[1].str();
    }

    //take all the paragraphs and sentences from the body of the HTML file and store it in a string
    std::string body;
    std::regex bodyRegex("<body>([^<]+)</body>");
    if (std::regex_search(fileContent, match, bodyRegex) && match.size() > 1) {
        body = match[1].str();
    }

    
    return info;
}

//read the input file and store the full content into a string
std::string read_file(const std::string& filename) {
    std::ifstream fileStream(filename);
    if (fileStream.is_open()) {
        std::string fileContent((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
        return fileContent;
    }
    return "";
}



int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    //first argument is the seed URL and the second argument is the filename
    std::string seed_url = argv[1];
    std::string input_file = argv[2];

    //input file consists of key words
    std::ifstream fileStream(input_file);
    //run through the file and store the key words into a vector
    std::vector<std::string> key_words;
    std::string word;
    //store the key words into a vector but each line is a key word - just need to remember to use each line as a key word only for the ones with qoutes
    //if there are quotes then store the whole phrase into the vector
    while(std::getline(fileStream, word)) {
        key_words.push_back(word);
    }
    

    //run through the vector and cout the key words
    // for(auto word : key_words) {
    //     std::cout << word << std::endl;
    // }

    //get the links from the HTML file
    std::string fileContent = read_file(seed_url);
    std::list<std::string> links = extractLinksFromHTML(fileContent);

    //store the information from the HTML file into a map
    std::map<std::string, std::string> info = extractInfoFromHTML(fileContent);

    //run through the map and cout the information
    for (auto pair : info) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    //run through the list and cout the links
    for (auto link : links) {
        std::cout << link << std::endl;
    }
    
    return 0;
}