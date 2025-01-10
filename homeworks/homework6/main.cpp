#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <set>
using namespace std;
//for fomarting sake we put the function prototypes here
void parse_file(ifstream& input_file, int& rows, int& columns, vector<string>& words_to_find, vector<string>& words_not_to_find, vector<char>& board_letters);
void insert_words(vector<vector<char>>& board, const vector<string>& words_to_find);
bool insert_word(vector<vector<char>>& board, const string& word, int row, int col, int direction, int index);
bool check_word(const vector<vector<char>>& board, const string& word, int row, int col, int direction);
bool check_board(const vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find);
void rate_of_change(int direction, int& changex, int& changey);
bool check_available(vector<vector<char>>& board, const string& word, int row, int col, int direction);
void word_search(vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command);
void word_recursion(vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command, int word_index, int row, int col, int direction);
void fill_empty(vector<vector<char>>& board, const vector<char>& board_letters);
void print_board(const vector<vector<char>>& board, ofstream& output_file);
void print_solutions(vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command);
//function to print all the solutions
void print_solutions(vector<vector<char>>& board,const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command){
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            for (int k = 0; k < 8; ++k){
                if (check_available(board, words_to_find[0], i, j, k)){
                    insert_word(board, words_to_find[0], i, j, k, 0);
                    word_recursion(board, words_to_find, words_not_to_find, board_letters, output_file, command, 1, i, j, k);
                    insert_word(board, words_to_find[0], i, j, k, 0);
                }
            }
        }
    }
}

//function to parse the file and get the rows, columns, words to find, words not to find, and the letters in the boards
void parse_file(ifstream& input_file, int& rows, int& columns, vector<string>& words_to_find, vector<string>& words_not_to_find, vector<char>& board_letters) {
    string line;
    getline(input_file, line);
    istringstream iss(line);
    iss >> columns >> rows;
    while (getline(input_file, line)) {
        if (line[0] == '+') {
            string word = line.substr(1);
            words_to_find.push_back(word);
            for (char letter : word) {
                board_letters.push_back(letter);
            }
        }
        else if (line[0] == '-') {
            words_not_to_find.push_back(line.substr(1));
        }
    }
    //test to print out the letters in the board
    for (char letter : board_letters) {
        cout << letter << " ";
    }

    //print out rows and columns for testing
    // cout << rows << "-- rows ---> col " << columns << endl;

}
//create a grid of letters from the letters that are in the words need to be found
//we need to create a grid of 2d vectors of characters to represent the board
//after we make the grid we need to use recursive calls to make the words in all directions 
// we then print out all the words that are found in the board

bool insert_word(vector<vector<char>>& board, const string& word, int row, int col, int direction , int index ) {
    // base case - the word was successfully inserted
    if (index >= word.length()) {
        return true;
    }
        // Check boundaries to avoid accessing out-of-bounds memory
    if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size()) {
    return false;
}

    // Check if the current cell matches the character in the word
    if (board[row][col] != word[index]) {
        return false;
    }

    // Recursively try inserting the next character of the word in the specified direction
    if (direction == 0) {
        // Move up
        return insert_word(board, word, row - 1, col, direction, index + 1);
    } else if (direction == 1) {
        // Move down
        return insert_word(board, word, row + 1, col, direction, index + 1);
    } else if (direction == 2) {
        // Move left
        return insert_word(board, word, row, col - 1, direction, index + 1);
    } else if (direction == 3) {
        // Move right
        return insert_word(board, word, row, col + 1, direction, index + 1);
    } else if (direction == 4) {
        // Move diagonally up-left
        return insert_word(board, word, row - 1, col - 1, direction, index + 1);
    } else if (direction == 5) {
        // Move diagonally up-right
        return insert_word(board, word, row - 1, col + 1, direction, index + 1);
    } else if (direction == 6) {
        // Move diagonally down-left
        return insert_word(board, word, row + 1, col - 1, direction, index + 1);
    } else if (direction == 7) {
        // Move diagonally down-right
        return insert_word(board, word, row + 1, col + 1, direction, index + 1);
    }

    return false;
}
//order notation for all functions


//insert the words recursivly in all directions
/*void insert{
    //for row
    //for col
    //for x direction
    //for y direction
    //for diagonal
    //for reverse diagonal
    --> check if the word can be inserted in the board
    then actually insert the word into the grid

}*/
void insert_words(vector<vector<char>>& board, const vector<string>& words_to_find) {
    int rows = board.size();
    int cols = board[0].size();
    for (const string& word : words_to_find) {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                for (int direction = 0; direction < 8; ++direction) {
                    if (insert_word(board, word, row, col, direction, 0)) {
                        return;
                    }
                }
            }
        }
    }
}


//Funtion to each if a word exissts in the baord starting from a specific position and a specific direction
bool check_word(const vector<vector<char>>& board, const string& word, int row, int col, int direction){
    int len = word.length();
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < len; ++i){
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[i]){
            return false;
        }
        if (direction == 0){
            //move up
            row--;
        }
        else if (direction == 1){
            //move down
            row++;
        }
        else if (direction == 2){
            //move left
            col--;
        }
        else if (direction == 3){
            //move right
            col++;
        }
        else if (direction == 4){
            //move diagonally up-left
            row--;
            col--;
        }
        else if (direction == 5){
            //move diagonally up-right
            row--;
            col++;
        }
        else if (direction == 6){
            //move diagonally down-left
            row++;
            col--;
        }
        else if (direction == 7){
            //move diagonally down-right
            row++;
            col++;
        }
    
}
}

//function to check if al required words are in the board and no forbidden are present
bool check_board(const vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find){
    int rows = board.size();
    int cols = board[0].size();
    for (const string& word : words_to_find){
        bool word_found = false;
        for (int row = 0; row < rows && !word_found; ++row){
            for (int col = 0; col < cols && !word_found; ++col){
                for (int direction = 0; direction < 8 && !word_found; ++direction){
                    if (check_word(board, word, row, col, direction)){
                        word_found = true;
                    }
                }
            }
        }
        if (!word_found){
            return false;
        }
    }
    for (const string& word : words_not_to_find){
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                for (int direction = 0; direction < 8; ++direction){
                    if (check_word(board, word, row, col, direction)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
//function to see if the the particular location is available
void rate_of_change(int direction, int& changex, int& changey){
    cout << "are you here in rate_of_change" << endl;
    if (direction == 0){
        changex = 0;
        changey = -1;
    }
    else if (direction == 1){
        changex = 0;
        changey = 1;
    }
    else if (direction == 2){
        changex = -1;
        changey = 0;
    }
    else if (direction == 3){
        changex = 1;
        changey = 0;
    }
    else if (direction == 4){
        changex = -1;
        changey = -1;
    }
    else if (direction == 5){
        changex = 1;
        changey = -1;
    }
    else if (direction == 6){
        changex = -1;
        changey = 1;
    }
    else if (direction == 7){
        changex = 1;
        changey = 1;
    }
}
bool check_available(vector<vector<char>>& board, const string& word, int row, int col, int direction){
    /*
    Check whether a word can be inserted at a given location with a given rotation
    */
    
    int changex = 0;
    int changey = 0;
    rate_of_change(direction, changex, changey);
    int len = word.length();
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < len; ++i){
        if (row < 0 || row >= rows || col < 0 || col >= cols || (board[row][col] != ' ' && board[row][col] != word[i])){
            return false;
        }
        row += changex;
        col += changey;
    }

}
//function to start the word search
void word_search(vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command){
    //first layer of recursion

    //base case
    if (board_letters.size() == 0){
        return;
    }
    int rows = board.size();
    int cols = board[0].size();

    //place the word horizontally using the recursive function
    //testing board, print the board to test using cout
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            //test grid
        }
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            for (int k = 0; k < 4; ++k){
                //testing words_to_find
                cout << words_to_find[0] << endl;
                if (check_available(board, words_to_find[0], i, j, k)){
                    insert_word(board, words_to_find[0], i, j, k, 0);
                    word_recursion(board, words_to_find, words_not_to_find, board_letters, output_file, command, 1, i, j, k);
                    insert_word(board, words_to_find[0], i, j, k, 0);
                }
            }
        }
    }
    //place the word vertically using the recursive function
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            for (int k = 4; k < 8; ++k){
                if (check_available(board, words_to_find[0], i, j, k)){
                    insert_word(board, words_to_find[0], i, j, k, 0);
                    word_recursion(board, words_to_find, words_not_to_find, board_letters, output_file, command, 1, i, j, k);
                    insert_word(board, words_to_find[0], i, j, k, 0);
                }
            }
        }
    }
    //place the word diagonally using the recursive function
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            for (int k = 4; k < 8; ++k){
                if (check_available(board, words_to_find[0], i, j, k)){
                    insert_word(board, words_to_find[0], i, j, k, 0);
                    word_recursion(board, words_to_find, words_not_to_find, board_letters, output_file, command, 1, i, j, k);
                    insert_word(board, words_to_find[0], i, j, k, 0);
                }
            }
        }
    }

}

void word_recursion(vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command, int word_index, int row, int col, int direction){
    //base case
    if (word_index == words_to_find.size()){
        if (check_board(board, words_to_find, words_not_to_find)){
            print_board(board, output_file);
        }
        return;
    }
    //recursive case
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            for (int k = 0; k < 8; ++k){
                cout << "i: " << i << " j: " << j << " k: " << k << endl;
                if (check_available(board, words_to_find[word_index], i, j, k)){
                    insert_word(board, words_to_find[word_index], i, j, k, 0);
                    word_recursion(board, words_to_find, words_not_to_find, board_letters, output_file, command, word_index + 1, i, j, k);
                    insert_word(board, words_to_find[word_index], i, j, k, 0);
                }
            }
        }
    }
}


void fill_empty (vector<vector<char>>& board, const vector<char>& board_letters){
    int rows = board.size();
    int cols = board[0].size();
    int index = 0;
    for (int row = 0; row < rows; ++row){
        for (int col = 0; col < cols; ++col){
            if (board[row][col] == ' '){
                board[row][col] = board_letters[index];
                index++;
            }
        }
    }
}

void print_board(const vector<vector<char>>& board, ofstream& output_file){
    for (const vector<char>& row : board){
        for (char letter : row){
            output_file << letter << " ";
        }
        output_file << endl;
    }
    output_file << endl;
}


int main(int argc, char* argv[]){
    //take 3 arguments
    if(argc != 4){
        cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return 1;
    }
    //open input file
    ifstream input_file(argv[1]);
    if(!input_file){
        cout << "Error: cannot open file " << argv[1] << endl;
        return 1;
    }
    //open output file
    ofstream output_file(argv[2]);
    if(!output_file){
        cout << "Error: cannot open file " << argv[2] << endl;
        return 1;
    }
    //create output file
    output_file << "Solution to the word search puzzle" << endl;

    
    //see if command is either "one_solution" or "all solution"
    string command = argv[3];

    //create a 2d vector of characters to represent the board
    vector<vector<char>> board;

    //parse the file to get the rows, columns, words to find, words not to find, and the letters in the board
    
    int rows, columns;
    vector<string> words_to_find;
    vector<string> words_not_to_find;
    vector<char> board_letters;
    parse_file(input_file, rows, columns, words_to_find, words_not_to_find, board_letters);
    
    //initialize the board 
    board = vector<vector<char>>(rows, vector<char>(columns));

    //sort words and not to find by length
    sort(words_to_find.begin(), words_to_find.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });
    sort(words_not_to_find.begin(), words_not_to_find.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });
    //startr the word search
    word_search(board, words_to_find, words_not_to_find, board_letters, output_file, command);
    //find variant solutions for unique solutions
    set<string> unique_solutions = set<string>();
    for(unsigned int i = 0; i < words_to_find.size(); i++){
        unique_solutions.insert(words_to_find[i]);
    }
    for (set<string>::iterator it = unique_solutions.begin(); it != unique_solutions.end(); ++it){
        words_to_find.push_back(*it);
    }
    //print solutions
    if (command == "one_solution"){
        print_board(board, output_file);
    }
    else if (command == "all_solutions"){
        print_solutions(board, words_to_find, words_not_to_find, board_letters, output_file, command);
    }
    else{
        cout << "Error: invalid command" << endl;
        return 1;
    }
    //close the input and output files
    //tests
    

    return 0;
    
}
