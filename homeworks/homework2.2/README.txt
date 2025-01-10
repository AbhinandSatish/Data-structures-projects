HOMEWORK 2: Ride Sharing


NAME:  < Abhinand Satish >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment:
mentors: Jiaqi, Aleksander, Erik, Eric, Yi 
Other REsources: Stackoverflow errors

< no COLLABORATORS other than the mentors from office hours >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 20 hours >


MISC. COMMENTS TO GRADER:
(

    In this assignment I am aware that we are supposed to keep the length of lines less than 100.
    If the lines in the main.cpp file goes over 100 characters that is because i kept getting errors
    This is because i could not cut output statements into two if it was mid string and 
    since the only statements that go over 100 are when i write to the output files or call functions 
    
    Also, i commented out all the cout statements to show you that i used those to debug the problems 
    I was having. 

)


## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your
own? What kinds of errors did you get? How did you fix them?

What parts of the assignment did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this assignment? How well
did the development and testing process go for you?

< 
    This assignment I had a lot of problems: firstly when I started out I had problems 
    acessing the header files and integrating the CPP files. But then I looked at the labs
    and they had the information about the #endif at the end of the header files.

    Another problem I had that took so much time to solve, was the segmentation error. 
    To solve this a TA helped me USE GDB to set break points and then find where the segmentation
    error occured. First I understood what it was by googling the stackoverflow 

    Anoher problem that I had was acessing the vectors and some unessesary vector declarations 
    that set my vectors to 0. I also accidentylaly left the vector = {} at one stage and that 
    had left the vector empty and I did not realize that it was empty. I set it empty at one stage To
    test something but I ended up making a set of errors after that. 

    Another problem that I had was setting the variables to null in cancel function, the problem
    was that i set the null variables to something but then called the wrong variables when updating
    output1.txt file and the output2,txt file. 

    The final problem that i faced was updating the driver that was cancelled to availed after it was cancelled
    when i outputed the file to output1 for the drivers, i did not change the old driver to available so I solved
    it by splitting the updated into two if statements and wrote a condition that if the for loop
    index i matched the index of the old driver then i update the state of the driver to avaialbe if not
    the next if statement gets carried out. Here is the code:

>