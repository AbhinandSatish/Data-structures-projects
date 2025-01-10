#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>


/*

Command 1: add a music track to a playlist
The first argument is the name of an input file which contains a playlist. The second argument is the name of another input file which contains all available music tracks. The third argument is the output file. The fourth argument is the action, which in this case is "add". The fifth argument is the title of the music track.

*/
// making a function to add a music track to a playlist

//creating a function to run through the library file to add the song with the author to the playlist
void addSong1(std::vector<std::string>& playlist, const std::string& title, const std::string& libraryFile) {
    // Check if the song is already in the playlist
    if (std::find(playlist.begin(), playlist.end(), title) != playlist.end()) {
        std::cerr << "Error: Song '" << title << "' is already in the playlist.\n";
        return;
    }

    // Read the library file to find authors
    std::ifstream libraryInput(libraryFile);
    if (!libraryInput.is_open()) {
        std::cerr << "Error: Cannot open file '" << libraryFile << "'.\n";
        return;
    }

    std::string line;
    std::string song_name;

    while(std::getline(libraryInput, line)) {
        std::istringstream iss(line);
        std::string songTitle;
        std::string songAuthor;
        std::getline(iss, songTitle, ',');
        song_name = songTitle.substr(1, songTitle.find('"', 1)-1);
        std::getline(iss, songAuthor, ',');
        //std::cout << songTitle << std::endl;
        //removing any white spaces after the songAuthor
        
        //songAuthor.erase(songAuthor.find_last_not_of(" \n\r\t")+1);

        if(song_name == title){
            std::string full_song = songTitle + "  " + songAuthor;
            full_song = full_song.substr(0, full_song.length()-2);
            //std::cout << "test"<< std::endl;
            //removing the extra spaces at the end of the songAuthor
            playlist.push_back(full_song);
            libraryInput.close();
            return;
        }
    }
}



//function to remove teh song from the playlist
void removeSong(std::vector<std::string>& playlist, const std::string& title) {
    // Remove any additional quotes around the title
    std::string formattedTitle = title;
    formattedTitle.erase(std::remove(formattedTitle.begin(), formattedTitle.end(), '"'), formattedTitle.end());

    // Find the song in the playlist using the formatted tittle and substring matching from the playlist
    std::vector<std::string>::iterator it = std::find_if(playlist.begin(), playlist.end(), [formattedTitle](const std::string& song) {
        return song.find(formattedTitle) != std::string::npos;
    });
    //std::vector<std::string>::iterator it = std::find(playlist.begin(), playlist.end(), formattedTitle);
    //remove the song from the playlist
    if (it != playlist.end()) {
        playlist.erase(it);
    } else {
        std::cerr << "Error: Song '" << formattedTitle << "' not found in the playlist.\n";
    }
}



//function to move the song 
//the final argument on the command line is the new position of the song
//delete the song from the old position and then move it to the new position in the playlist
void moveSong(std::vector<std::string>& playlist, const std::string& title, int newPosition) {


    // Find the song in the playlist
    std::string formattedTitle = title.substr(0, title.find_last_not_of("0123456789") + 1);

    formattedTitle.erase(std::find_if(formattedTitle.rbegin(), formattedTitle.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), formattedTitle.end());
    

    
    int a;
    for (int i = 0; i < playlist.size(); i++) {
        //std::cout << playlist[i] << std::endl;
        if (playlist[i].find(formattedTitle) != std::string::npos) {

            a =i;

        }
    }
    std::string new_location = playlist[a];
    playlist.erase(playlist.begin() + a);
    
    playlist.insert(playlist.begin() + newPosition - 1, new_location);

}




int main(int argc, char* argv[]){

    if (argc <5)
    {
        std::cerr << "Usage: " << argv[0] << " <playlist_file> <library_file> <output_file> add <title>\n";
        return 1;
    }
    
    //extracting the information from the command line arguments

    std::string playlistFile = argv[1];
    std::string libraryFile = argv[2];
    std::string outputFile = argv[3];
    std::string action = argv[4];

    std::string title = argv[5];
    //concatenating the title if it has more than one word
    for (int i = 6; i < argc; i++) {
        title += " ";
        title += argv[i];
    }
    //removing any escape characters from the title
    title.erase(std::remove(title.begin(), title.end(), '\\'), title.end());
    //removing any additional quotes from the title
    title.erase(std::remove(title.begin(), title.end(), '"'), title.end());
    //removing any additional spaces at the end of the title
    title.erase(title.find_last_not_of(" \n\r\t")+1);

    //now to read the existing playlist from the file
    std::ifstream playlistInput(playlistFile);
    std::vector<std::string> playlist;
    if (!playlistInput.is_open())
    {
        std::cerr << "Error: Cannot open file '" << playlistFile << "'.\n";
        return 1;
    }

    //reading the existing playlist from the input file
    std::string line;
    
    while (std::getline(playlistInput, line))
    {
        playlist.push_back(line);
    }

    // condition of add from the command line


    if (action == "add") {
        // now I should call the addSong function to add the song to the playlist
        addSong1(playlist, title, libraryFile);
    }

    //condition of remove from the command line
    if (action == "remove") {
        // call the removeSong function to remove the song from the playlist
        removeSong(playlist, title);
    }
    //now we hshould write the new playlist to the output
    std::ofstream playlistOutput(outputFile);
    //if the condition is to move

    if (action == "move") {
        // Parse the new position argument
        int newPosition;
        newPosition = std::atoi(argv[argc-1]);
    
        

        // now I should call the moveSong function to move the song to the new position
        moveSong(playlist, title, newPosition);
    }

    
    if (!playlistOutput.is_open())
    {
        std::cerr << "Error: Cannot open file '" << outputFile << "'.\n";
        return 1;
    }
    // now i should iterate over each element in the playlist and write it to the output file
    for (const std::string& song : playlist) {
        playlistOutput << song << "\n";
    }
    playlistOutput.close(); 
    return 0;
    
    
}

