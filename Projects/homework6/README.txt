HOMEWORK 6: INVERSE WORD SEARCH


NAME:  < Abhinand Satish >


COLLABORATORS AND OTHER RESOURCES: 
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Office hours people >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.

ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 23 >


ALGORITHM ANALYSIS:
What's the order notation of your algorithm?

parse_file function:
- It iterates the funput file once so it is O(n) time where n is the number of lines in the file
- within the loop, taking the words and theletters from the lines will have O(m) so the over all time complexity
is: O(n*m)

insert_word function:
- this function performs recursive calls based on the direction parameter but it rtranverses each
of the cells of the board once and one instance
- once the recursive call is initiated, each of these calls involed constant -time operateions for boundry checks and character which is O(1)
-The total number of recursive calls made by the function is proportional to the length of the word being inserted.
Therefore, the time complexity of insert_word is O(n), where n is the length of the word.
: O(n)

void insert_words:
- It involves nested loops over the board, words to find, rows, columns, and directions.
- The nested loops iterate over each cell of the board, resulting in O(rows * cols * 8) iterations.
- The nested loops iterate over each cell of the board, resulting in O(rows * cols * 8) iterations.
- in the case of the words being sucesfully inserted the function may return early. But it may iterate over all the cells
- this means the function is:
 O(rows * cols * 8 * |words_to_find| * n)

words_search function:
- this function has nested loops over the board, uses the words to find and the direction asweel  meanign this part is O(rows * cols * 8 * |words_to_find|) time complexity.
- but insde the loops the insert_word boolean function is called which we know has O(n) time 
meaning the the over time conplexity of this function is:
O(rows * cols * 8 * n).

check_board function:
- this has nested loops over the board, words to find and direction like the previous solutions so it has  O(rows * cols * 8 * |words_to_find|) time complexity.
- within the nested loops the check_word function is called which has a  O(word_length) time complexity.
- this meanns the ovver all time complexity is:
O(rows * cols * 8 * |words_to_find| * word_length).


MISC. COMMENTS TO GRADER:  




## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your
own? What kinds of errors did you get? How did you fix them?

What parts of the assignment did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this assignment? How well
did the development and testing process go for you?

< In this homeowrk, i managed to understand how to do the problem generally. Like the logic of
it was understandable but I found really difficulty in coding the logic and integrating my functions together
my code was able to generate a board with the right number of rows and colmns and when testing
my words were being read and feed into the grid but it was not able to print the solutions properly. 
Here is my logic:

Word insertion:
Insert_word function:
        in this function i attempt the insert a word into the board at a specified position (row, column) and direction.
        i then recursively checks if the letters of the word match the corresponding cells in the board, considering the specified direction.
        The insertion stops when either the entire word is successfully inserted or the boundaries of the board are reached.

Word searching:
Word_search function:
        i then search the words using the word search function 
        what i do is that it iterates over each cell in the board and tries to insert the words to find in all possible directions.
        If a word can be inserted successfully, it initiates a recursive search to find the remaining words.
        It also handles word insertion in horizontal, vertical, and diagonal directions.

Recursive word search:
        This function recursively searches for the remaining words in the board.
        It continues the search for the next word from the position where the previous word was inserted.
        It explores all possible directions for each word and backtracks if a word cannot be inserted.

Finally i just check the board using the check board function see if there are words that are forbinbeen and if the solutions are right
even though i got this logic i just could not get my code to work or make sense. 
 >