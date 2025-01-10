#include <sstream>
#include "recommendation.h"
//#include "recommendation.cpp"
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;



/*

Learning Objectives
- Practice managing dynamic memory.
- Practice using two-dimensional arrays.

Specifics: 
- There are 500 users in total and it is index from 0-->499
- There are 110 movies in total and it is indexed from 0 --> 99

-- index and name of all movies are in the main.cpp in a list 
-- need to define a class recommendation.cpp most of the code is given to us but it is incomplete
        -- Class REcommendation requirements:
                - Must have atleast two member variables, it can have more definitly if needed
                    - userMovieRatingsMatrix
                    - userShowRatingMatrix 
                            -- both are 2D arrays so use "int**" as pointer
                        - Two member functions to your class are provided, and you can call but should not modify these two functions.\


-- USER INFORMATION AND STUFF:
-----Two input files are provided: movieRatings.txt and showRatings.txt.
        - Each line of the text file is the text file represents one user
        -- the rating of the movie is in a range of 1 to 5
        ----> The first line of movieRatings.txt means, user 0 gives a rating of 3 to movie 87, gives a rating of 1 to 
                movie 11, gives a rating of 1 to movie 14, gives a rating of 4 to moving 31, gives a rating of 4 to movie 101, gives a rating of 2 to movie 21, etc.

        ----> The second line of 
        movieRatings.txt means, user 1 gives a rating of 1 to movie 6, gives a rating of 2 to movie 61, gives a rating of 2 to movie 109, gives a rating of 4 to moving 87, 
            gives a rating of 4 to movie 28, gives a rating of 5 to movie 38, etc.

        ----> The 3rd line descirbes ratings given by user 2, the 4th line describes ratings given by user 3, etc.

        ----> The file showRatings.txt can be interpreted in the same way. It is just ratings in that file are for tv shows. 
        In this assignment, your program should read these two input files and store the movie ratings in a matrix, and store the show ratings in another matrix.


####### IMportant notes:
In this assignment, you are NOT allowed to use std::vector anywhere in your code. You must use dynamic memory to store the movie rating matrix, and the show rating matrix.

Use good coding style when you design and implement your program. Organize your program into functions: don’t put all the code in main!



*/

class Movie {
public:
    int movieId;
    std::string title;
};

class TVShow {
public:
    int tvShowId;
    std::string title;
};

// Oscar-winning movies
Movie movies[] = {
    {0, "Elvis"},
    {1, "The Shawshank Redemption"},
    {2, "The Godfather"},
    {3, "Schindler's List"},
    {4, "The Lord of the Rings: The Return of the King"},
    {5, "Forrest Gump"},
    {6, "Titanic"},
    {7, "Gladiator"},
    {8, "The Departed"},
    {9, "12 Years a Slave"},
    {10, "Green Book"},
    {11, "The Silence of the Lambs"},
    {12, "The Sound of Music"},
    {13, "Amadeus"},
    {14, "The Shape of Water"},
    {15, "Braveheart"},
    {16, "The English Patient"},
    {17, "Moonlight"},
    {18, "Argo"},
    {19, "Birdman"},
    {20, "No Country for Old Men"},
    {21, "A Beautiful Mind"},
    {22, "Spotlight"},
    {23, "The King's Speech"},
    {24, "Platoon"},
    {25, "Dances with Wolves"},
    {26, "Gandhi"},
    {27, "The Green Mile"},
    {28, "The Pianist"},
    {29, "The Bridge on the River Kwai"},
    {30, "West Side Story"},
    {31, "The Godfather: Part II"},
    {32, "Crouching Tiger, Hidden Dragon"},
    {33, "The Hurt Locker"},
    {34, "Slumdog Millionaire"},
    {35, "Million Dollar Baby"},
    {36, "Rain Man"},
    {37, "Rocky"},
    {38, "Inception"},
    {39, "Chariots of Fire"},
    {40, "The Great Gatsby"},
    {41, "All About Eve"},
    {42, "One Flew Over the Cuckoo's Nest"},
    {43, "The Apartment"},
    {44, "The French Connection"},
    {45, "The Grand Budapest Hotel"},
    {46, "Rebecca"},
    {47, "Gone with the Wind"},
    {48, "Casablanca"},
    {49, "Ben-Hur"},
    {50, "Lawrence of Arabia"},
    {51, "The Phantom of the Opera"},
    {52, "The Godfather: Part III"},
    {53, "Annie Hall"},
    {54, "Out of Africa"},
    {55, "My Fair Lady"},
    {56, "The Life of Emile Zola"},
    {57, "On the Waterfront"},
    {58, "The Best Years of Our Lives"},
    {59, "The Deer Hunter"},
    {60, "Midnight Cowboy"},
    {61, "American Beauty"},
    {62, "Gigi"},
    {63, "Going My Way"},
    {64, "Gentleman's Agreement"},
    {65, "From Here to Eternity"},
    {66, "Oliver!"},
    {67, "Patton"},
    {68, "The Artist"},
    {69, "The Family Plan"},
    {70, "A Man for All Seasons"},
    {71, "Lincoln"},
    {72, "The Greatest Show on Earth"},
    {73, "An American in Paris"},
    {74, "Kramer vs. Kramer"},
    {75, "The Descendants"},
    {76, "Driving Miss Daisy"},
    {77, "All Quiet on the Western Front"},
    {78, "The Greatest Showman"},
    {79, "Mutiny on the Bounty"},
    {80, "The Lost Weekend"},
    {81, "The Batman"},
    {82, "Aquaman and the Lost Kingdom"},
    {83, "Parasite"},
    {84, "Ordinary People"},
    {85, "Wonka"},
    {86, "Tom Jones"},
    {87, "The Last Emperor"},
    {88, "Don't Look Up"},
    {89, "Chicago"},
    {90, "The Revenant"},
    {91, "Darkest Hour"},
    {92, "Manchester by the Sea"},
    {93, "Hacksaw Ridge"},
    {94, "The Theory of Everything"},
    {95, "Midnight in Paris"},
    {96, "Coda"},
    {97, "Catch Me If You Can"},
    {98, "Nomadland"},
    {99, "The Graduate"},
    {100, "Pearl Harbor"},
    {101, "Dune"},
    {102, "King Richard"},
    {103, "Drive My Car"},
    {104, "The Fabelmans"},
    {105, "The Long Goodbye"},
    {106, "Nightmare Alley"},
    {107, "A Star is Born"},
    {108, "Top Gun: Maverick"},
    {109, "Everything Everywhere All at Once"},
};

// Emmy Award-winning TV shows
TVShow tvShows[] = {
    {0, "Little Women"},
    {1, "The West Wing"},
    {2, "The Sopranos"},
    {3, "Breaking Bad"},
    {4, "Game of Thrones"},
    {5, "The Twilight Zone"},
    {6, "The Simpsons"},
    {7, "Friends"},
    {8, "The Mary Tyler Moore Show"},
    {9, "M*A*S*H"},
    {10, "The Wire"},
    {11, "The Marvelous Mrs. Maisel"},
    {12, "The Crown"},
    {13, "Fleabag"},
    {14, "Stranger Things"},
    {15, "The Mandalorian"},
    {16, "Veep"},
    {17, "The Big Bang Theory"},
    {18, "Homeland"},
    {19, "The Handmaid's Tale"},
    {20, "The Office (U.S.)"},
    {21, "Cheers"},
    {22, "The Golden Girls"},
    {23, "I Love Lucy"},
    {24, "The Americans"},
    {25, "Sherlock"},
    {26, "Fargo"},
    {27, "The People v. O.J. Simpson: American Crime Story"},
    {28, "Black Mirror"},
    {29, "Westworld"},
    {30, "Mad Men"},
    {31, "The Boys"},
    {32, "Better Call Saul"},
    {33, "Hand of God"},
    {34, "The Good Place"},
    {35, "Atlanta"},
    {36, "Barry"},
    {37, "The Office (UK)"},
    {38, "Fawlty Towers"},
    {39, "Monty Python's Flying Circus"},
    {40, "The Daily Show with Jon Stewart"},
    {41, "Late Night with David Letterman"},
    {42, "The Tonight Show Starring Johnny Carson"},
    {43, "Saturday Night Live"},
    {44, "The X-Files"},
    {45, "Downton Abbey"},
    {46, "The Big C"},
    {47, "Six Feet Under"},
    {48, "Ray Donovan"},
    {49, "Curb Your Enthusiasm"},
    {50, "Keeping Up with the Kardashians"},
    {51, "The Twilight Zone (2002)"},
    {52, "Dexter"},
    {53, "House of Cards"},
    {54, "Boardwalk Empire"},
    {55, "The Newsroom"},
    {56, "Black-ish"},
    {57, "The Good Wife"},
    {58, "Parks and Recreation"},
    {59, "Pose"},
    {60, "This Is Us"},
    {61, "Watchmen"},
    {62, "The Office (U.K.)"},
    {63, "Vigil"},
    {64, "The Ellen DeGeneres Show"},
    {65, "True Detective"},
    {66, "The Cosby Show"},
    {67, "The Witcher"},
    {68, "Succession"},
    {69, "The Tonight Show Starring Jimmy Fallon"},
    {70, "Scrubs"},
    {71, "Mindhunter"},
    {72, "Euphoria"},
    {73, "The Umbrella Academy"},
    {74, "Arrested Development"},
    {75, "Jury Duty"},
    {76, "Seinfeld"},
    {77, "Great News"},
    {78, "Killers of the Flower Moon"},
    {79, "House"},
    {80, "Ted Lasso"},
    {81, "How I Met Your Mother"},
    {82, "Unbreakable Kimmy Schmidt"},
    {83, "All in the Family"},
    {84, "The Leftovers"},
    {85, "Wednesday"},
    {86, "Frasier"},
    {87, "Modern Family"},
    {88, "Better Things"},
    {89, "Brooklyn Nine-Nine"},
    {90, "Everybody Loves Raymond"},
    {91, "Taxi"},
    {92, "Late Night with Seth Meyers"},
    {93, "30 Rock"},
    {94, "Community"},
    {95, "Squid Game"},
    {96, "Will & Grace"},
    {97, "Schitt's Creek"},
    {98, "Get Smart"},
    {99, "The Monkees"},
};

// this function reads the one line, and update row i of the matrix.
void process_one_line(int** matrix, int i, std::string& line){
	std::istringstream iss(line);
	// process each (index, value) pair
        int index, value;
        char openParen, comma, closeParen;
	// when used with integers, it reads characters until it encounters a non-digit character or whitespace. However, when used with characters, it reads a single character.
        while (iss >> openParen >> index >> comma >> value >> closeParen) {
            matrix[i][index] = value;
        }
}

int main(int argc, char* argv[]) {
    // setting up the command line arguments:
    /*
            
            Your program only needs to support one command:

        nyrecommender.exe movieRatings.txt showRatings.txt output.txt userID numRecommendations
        Here

        movieRatings.txt is the movie rating input file, already described above.
        showRatings.txt is the show rating input file, already described above.
        output.txt is where to print your output.
        userID specifies the ID of the user.
        numRecommendations specifies how many movies/shows your program will recommend to the user. For example, if numRecommendation is 5, then your program should try to print up to 5 movies and up to 5 tv shows.

    */

   //conditions of the the command line:
    /*
        in the case where the number of command line arguments is not 6, your program should use std::cerr to print the following message:
        Usage: nyrecommender.exe movieRatings.txt showRatings.txt output.txt userID numRecommendations
        Nothing should be printed to the output file in such a case.

        in the case where the userID command line argument is not in the range of 0-499, your program should use std::cerr to print the following error message:
        Invalid User ID.
        Nothing should be printed to the output file in such a case.

        in the case where the numRecommendations command line argument is 0, your program should produce the output file which contains the following message:
        Prime: Movies we think you'll like:
        Prime: TV shows we think you'll like:
   */
    
        std::string movie_ratings;
        std::string show_ratings;
        std::string output_file;
        if (argc != 6) {
            std::cerr << "Usage: nyrecommender.exe movieRatings.txt showRatings.txt output.txt userID numRecommendations" << std::endl;
            return 1;
        }
        movie_ratings = argv[1];
        show_ratings = argv[2];
        output_file = argv[3];
        int userID = std::stoi(argv[4]);
        int numRecommendations = std::stoi(argv[5]);

        if (userID < 0 || userID >= 500) {
            std::cerr << "Invalid User ID." << std::endl;
            return 1;
        }

        if (numRecommendations == 0) {
            std::ofstream output(output_file);
            output << "Prime: Movies we think you'll like:" << std::endl;
            output << "Prime: TV shows we think you'll like:" << std::endl;
            return 0;
        }else{
            // now i am going to use a matrix to store the movie ratings and the show ratings
            std::ifstream movieRatingsFile(movie_ratings);
            if (!movieRatingsFile) {
                std::cerr << "Cannot open movie ratings file." << std::endl;
                return 1;
            }
            int** userMovieRatings = new int*[500];
            for (int i = 0; i < 500; ++i) {
                userMovieRatings[i] = new int[110];
                // cout << "i: " << i<< endl;
                // cout << "userMovieRatings[i]: " << userMovieRatings[i]<< endl;
            }
            std::string line;
            for (int i = 0; i < 500; ++i) {
                std::getline(movieRatingsFile, line);
                process_one_line(userMovieRatings, i, line);
                //cout << "i2: " << i<< endl;
                // cout << "line: " << line << endl;
            }
            // std::string line;
            // int i = 0;
            // while (std::getline(movieRatingsFile, line)) {
            //     process_one_line(userMovieRatings, i, line);
            //     i++;
            //     cout << "i2: " << i<< endl;
            //     cout << "line: " << line << endl;

            // }

            movieRatingsFile.close();

            // read the show ratings
            std::ifstream showRatingsFile(show_ratings);
            if (!showRatingsFile) {
                std::cerr << "Cannot open show ratings file." << std::endl;
                return 1;
            }

            int** userShowRatings = new int*[500];
            for (int i = 0; i < 500; ++i) {
                userShowRatings[i] = new int[100];
            }
            for (int i = 0; i < 500; ++i) {
                std::getline(showRatingsFile, line);
                process_one_line(userShowRatings, i, line);
                
            }
            showRatingsFile.close();

            // create a recommendation system for the void movies function 
            RecommendationSystem recommendation(500, 110, 100, userMovieRatings, userShowRatings);
            int* recommendedMovies = new int[numRecommendations];
            recommendation.recommendMovies(userID, numRecommendations, recommendedMovies);

            //create a recommendation system for the void shows function
            int* recommendedShows = new int[numRecommendations];
            recommendation.recommendShows(userID, numRecommendations, recommendedShows );

            //now i  need to find the rating of the movie and trhe show and store that value
            std::ofstream outputFile(output_file);
            outputFile << "Prime: Movies we think you'll like:" << std::endl;
            for (int i = 0; i < numRecommendations; ++i) {
                outputFile << movies[recommendedMovies[i]].title << std::endl;
            }
            outputFile << "Prime: TV shows we think you'll like:" << std::endl;
            for (int i = 0; i < numRecommendations; ++i) {
                cout << "are you here" << endl;
                outputFile << tvShows[recommendedShows[i]].title << std::endl;
            }
            outputFile.close();

            

            
        }
        

        return 0;

}



//old code:
/*
        // std::ifstream movieRatingsFile(movie_ratings);
        // if (!movieRatingsFile) {
        //     std::cerr << "Cannot open movie ratings file." << std::endl;
        //     return 1;
        // }
        // int** userMovieRatings = new int*[500];
        // for (int i = 0; i < 500; ++i) {
        //     userMovieRatings[i] = new int[110];
        // }
        // std::string line;
        // int i = 0;
        // while (std::getline(movieRatingsFile, line)) {
        //     process_one_line(userMovieRatings, i, line);
        //     i++;
        // }
        // movieRatingsFile.close();

        // // read the show ratings
        // std::ifstream showRatingsFile(show_ratings);
        // if (!showRatingsFile) {
        //     std::cerr << "Cannot open show ratings file." << std::endl;
        //     return 1;
        // }
        // int** userShowRatings = new int*[500];
        // for (int i = 0; i < 500; ++i) {
        //     userShowRatings[i] = new int[75];
        // }
        // i = 0;
        // while (std::getline(showRatingsFile, line)) {
        //     process_one_line(userShowRatings, i, line);
        //     i++;
        // }
        // showRatingsFile.close();

        // // create a recommendation system
        // RecommendationSystem rs(500, 110, 75, userMovieRatings, userShowRatings);

        // // recommend movies
        // int* recommendedMovies = new int[numRecommendations];
        // rs.recommendMovies(userID, numRecommendations, recommendedMovies);

        // // recommend tv shows
        // int* recommendedTVShows = new int[numRecommendations];
        // rs.recommendShows(userID, numRecommendations, recommendedTVShows);

        // // write the recommendations to the output file
        // std::ofstream outputFile(output_file);
        // outputFile << "Prime: Movies we think you'll like:" << std::endl;
        // for (int i = 0; i < numRecommendations; ++i) {
        //     outputFile << movies[recommendedMovies[i]].title << std::endl;
        // }
        // outputFile << "Prime: TV shows we think you'll like:" << std::endl;
        // for (int i = 0; i < numRecommendations; ++i) {
        //     outputFile << tvShows[recommendedTVShows[i]].title << std::endl;
        // }
        // outputFile.close();



*/