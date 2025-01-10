

ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 8 hours >
## Project Overview

In this project, I implemented a Spotify Playlist manager using C++. The main objective was to create a program that allows users to add, remove, and move songs within a playlist. The project is divided into two main files: `chat.cpp` and `main.cpp`.

### Data Structures Used

The primary data structure used in this project is the `std::vector` from the C++ Standard Library. This choice was made due to the dynamic nature of vectors, which allows for efficient addition and removal of elements.

### Implementation Details

#### chat.cpp

In `chat.cpp`, I implemented the core functionalities for managing the playlist. This includes functions for adding, removing, and moving songs within the playlist.

1. **Adding a Song**: 
    - I created a function to add a song to the playlist. This function takes the song title and artist as input, concatenates them into a single string, and then appends this string to the vector.
    ```cpp
    void addSong(std::vector<std::string>& playlist, const std::string& title, const std::string& artist) {
        std::string song = title + " - " + artist;
        playlist.push_back(song);
    }
    ```

2. **Removing a Song**: 
    - To remove a song, I used the `std::remove` algorithm along with the `erase` method. This combination allows for efficient removal of elements from the vector.
    ```cpp
    void removeSong(std::vector<std::string>& playlist, const std::string& title, const std::string& artist) {
        std::string song = title + " - " + artist;
        playlist.erase(std::remove(playlist.begin(), playlist.end(), song), playlist.end());
    }
    ```

3. **Moving a Song**: 
    - Moving a song within the playlist was a bit more challenging. I used a loop to find the song's current position, then used the `erase` method to remove it from its original position and insert it at the new position.
    ```cpp
    void moveSong(std::vector<std::string>& playlist, const std::string& title, const std::string& artist, int newPosition) {
        std::string song = title + " - " + artist;
        auto it = std::find(playlist.begin(), playlist.end(), song);
        if (it != playlist.end()) {
            playlist.erase(it);
            playlist.insert(playlist.begin() + newPosition, song);
        }
    }
    ```

#### main.cpp

In `main.cpp`, I implemented the user interface and interaction logic. This file contains the main function, which handles user input and calls the appropriate functions from `chat.cpp`.

### Challenges and Solutions

1. **Learning C++ Syntax**: 
    - Initially, I struggled with the syntax and basic concepts of C++. I watched several YouTube tutorials and read documentation to get up to speed.

2. **String Manipulation**: 
    - Handling song titles and artist names required a lot of string manipulation. I learned about functions like `substr`, `find`, and `erase` to manage strings effectively.

3. **Efficient Removal and Insertion**: 
    - I was not familiar with `std::remove` and the `erase` method. With the help of mentors during office hours, I learned how to use these functions to manage the playlist efficiently.

4. **Debugging**: 
    - Debugging was done using `std::cout` and `std::cerr` statements to trace errors. This helped me identify and fix issues in the code.

### Reflection and Self Assessment

This project was a great learning experience. I faced several challenges, especially with C++ syntax and string manipulation. However, with persistence and help from mentors, I was able to overcome these obstacles. The most rewarding part was seeing the playlist manager work as expected after implementing and testing all the functions.



