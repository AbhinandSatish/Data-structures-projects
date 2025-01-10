HOMEWORK 1: Spotify Playlists


NAME:  < Abhinand Satish>


COLLABORATORS AND OTHER RESOURCES:

List the names of everyone you talked to about this assignment
mentors:  Tashi, Max & Erik, Nick Archer & Kiron & Matteo & Yi. 
Other RESOURCES: Stackoverflow for error messages



< no COLLABORATORS other than the mentors from office hours >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 8 hours >






MISC. COMMENTS TO GRADER:  
Optional, please be concise!


## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your
own? What kinds of errors did you get? How did you fix them?

What parts of the assignment did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this assignment? How well
did the development and testing process go for you?

< The main problem that i faced was that i did not know how to start doing this homework. I did not know the syntax to begin, so i had to look at a lot of youtube videos on using vectors, 
how to push, and basic C++ information that I needed. Once I learnt a lot about that I then created my functions. The first function that I created was the adding the song function.
I rewrote this function many time over and over because I was not able to first get the song artist along with the songs. So to tackle that problem I had to run through the library of all the 
song and then match the song then pull the whole line with the authors name. One thing that I had to figure out at office hours was to add all the names of the song together by string concactonating 
espeically when there were extra white spaces. Then I had to tackle remove two spaces after the authors name on the song after adding. Removing the song was a little less challenging I would say but I 
I did face some problems, i did not know of the std::remove and the .begin and .end functions so when I came to office hours the mentors helped me with that and to erase the song from the playlists. 
There were also some things I learnt like std::string::npos;. I did not know that was a think until i googled it and used stackoverflow responses to learn how to use that. Finally the most challenging 
was moving the song in the playlists, I wrote an initial piece of code but then it was a lot and unessesary, so Yi at office hours helped me to move the song. He thought me to run a loop through the playlist 
and then he helped me to find the erase function and use that to swap a newPosition and a new location for the songs." 
// Find the song in the playlist
    std::string formattedTitle = title.substr(0, title.find_last_not_of("0123456789") + 1);

    formattedTitle.erase(std::find_if(formattedTitle.rbegin(), formattedTitle.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), formattedTitle.end());
    the above piece of code was majority of what he thought me to use. As well as the below for loop:
         int a;
    for (int i = 0; i < playlist.size(); i++) {
        //std::cout << playlist[i] << std::endl;
        if (playlist[i].find(formattedTitle) != std::string::npos) {

            a =i;

        }
    }
    Overall the rest of the errors I just tested by writing cout statements  and also using the std:cerr, that helped me to find out where the errors were occuring.  The more complicated errors I asked help from the office hour mentors. 
>
