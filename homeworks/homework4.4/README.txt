HOMEWORK 4: Yelp Businesses


NAME:  < Abhinand Satish>


COLLABORATORS AND OTHER RESOURCES:
    List the names of everyone you talked to about this assignment
    (classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
    LMS, etc.), and all of the resources (books, online reference
    material, etc.) you consulted in completing this assignment.

< Lab TA: Jiaqi, Aleksander & Nicholas Bilsborrow >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 5 hours >


MISC. COMMENTS TO GRADER:
()


## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your
own? What kinds of errors did you get? How did you fix them?

What parts of the assignment did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this assignment? How well
did the development and testing process go for you?

< In this Homework I found a few things challenging: 1. Was setting the values
from the getters and setters. I had accidentally named my functions that same as the 
getters since I used the code provided. That way it didnt even match and output the 
results of each line after it parsed. 
To solve this I had just changed the names of the function.
2: I did not create new varaibles in my class, without doing this my code got
to complex in my main so I just created new getters appropriatly. 
3. I did not completly undertand how to use the iterators. To solve this i just looked
at the lecture notes and the lab work. 
The TA from the labs also helped me understand how to use the iterator function from the List
Here is an example: 
std::cout << "test2" << endl;
        std::list<yelp>::iterator it = matchedRestaurants.begin();
        outputFile << "====================="<<endl;
        while(it != matchedRestaurants.end()){
            yelp restaurant = *it;
            outputFile << i << ". " << restaurant.getName() << endl;
>
