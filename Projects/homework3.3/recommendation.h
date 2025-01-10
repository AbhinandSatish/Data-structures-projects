#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H
#include <iostream>
#include <cmath>
using namespace std;


/*
 Class REcommendation requirements:
                - Must have atleast two member variables, it can have more definitly if needed
                    - userMovieRatingsMatrix
                    - userShowRatingMatrix 
                            -- both are 2D arrays so use "int**" as pointer
                        - Two member functions to your class are provided, and you can call but should not modify these two functions.\

*/


class RecommendationSystem{
    public:
    //constructor
    RecommendationSystem(int numUsers, int numMovies, int numShows, int** userMovieRatings, int** userShowRatings);
    //accessors 
    void recommendMovies(int userId, 
                        int numRecommendations, 
                        int* recommendedMovies) const;
    void recommendShows(int userId, 
                        int numRecommendations,
                        int* recommendedTVShows) const;
    private:
    // member variables
    int numUsers;
    int numMovies;
    int numShows;
    int** userMovieRatingsMatrix;
    int** userShowRatingsMatrix;
    
};
#endif