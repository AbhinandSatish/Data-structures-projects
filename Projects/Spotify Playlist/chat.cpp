#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 6) {
        std::cerr << "Usage: " << argv[0] << " <playlist_file> <library_file> <output_file> <action> <title> [new_position]\n";
        return 1; // Exit with an error code
    }

    // Extract information from command line arguments
    std::string playlistFile = argv[1];
    std::string libraryFile = argv[2];
    std::string outputFile = argv[3];
    std::string action = argv[4];
    std::string title = argv[5];

    int newPosition = -1; // Default value for commands other than "move"

    // Check if the action is "move" and a new position is provided
    if (action == "move" && argc > 6) {
        try {
            newPosition = std::stoi(argv[6]);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid new position. Please provide a valid integer.\n";
            return 1; // Exit with an error code
        }
    }

    // Now you have the required information, you can use these variables in your program logic

    // For testing, you can print the extracted information
    std::cout << "Playlist File: " << playlistFile << "\n";
    std::cout << "Library File: " << libraryFile << "\n";
    std::cout << "Output File: " << outputFile << "\n";
    std::cout << "Action: " << action << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "New Position: " << newPosition << "\n";

    // Your program logic goes here

    return 0; // Exit successfully
}
