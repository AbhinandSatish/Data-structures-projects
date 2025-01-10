#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;
//for fomarting sake we put the function prototypes here
void parse_file(ifstream& input_file, int& rows, int& columns, vector<string>& words_to_find, vector<string>& words_not_to_find, vector<char>& board_letters);
bool insert_word(vector<vector<char>>& board, const string& word, int row, int col, int direction , int index );
void insert_words(vector<vector<char>>& board, const vector<string>& words_to_find);
bool check_word(const vector<vector<char>>& board, const string& word, int row, int col, int direction);
bool check_board(const vector<vector<char>>& board, const vector<string>& words_to_find, const vector<string>& words_not_to_find);
void word_search(const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command);
void fill_empty (vector<vector<char>>& board, const vector<char>& board_letters);
void print_board(const vector<vector<char>>& board, ofstream& output_file);
void print_solutions(const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command);
void generate_permutations(vector<char>& board_letters, int start, vector<vector<char>>& permutations);




//function to parse the file and get the rows, columns, words to find, words not to find, and the letters in the boards
void parse_file(ifstream& input_file, int& rows, int& columns, vector<string>& words_to_find, vector<string>& words_not_to_find, vector<char>& board_letters) {
    string line;
    getline(input_file, line);
    istringstream iss(line);
    iss >> rows >> columns;
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
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
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

void insert_words(vector<vector<char>>& board, const vector<string>& words_to_find) {
    // Iterate over each word to find
    for (const string& word : words_to_find) {
        bool word_inserted = false;
        // Iterate over each row
        for (int row = 0; row < board.size() && !word_inserted; ++row) {
            // Iterate over each column
            for (int col = 0; col < board[0].size() && !word_inserted; ++col) {
                // Try inserting the word in all directions
                for (int direction = 0; direction < 8 && !word_inserted; ++direction) {
                    if (insert_word(board, word, row, col, direction, 0)) {
                        // Word successfully inserted, mark as inserted and move to the next word
                        word_inserted = true;
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
void generate_permutations(vector<char>& board_letters, int start, vector<vector<char>>& permutations) {
    if (start == board_letters.size()) {
        permutations.push_back(board_letters);
        return;
    }

    for (int i = start; i < board_letters.size(); ++i) {
        swap(board_letters[start], board_letters[i]);
        generate_permutations(board_letters, start + 1, permutations);
        swap(board_letters[start], board_letters[i]);
    }
}

void word_search(const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command) {
    int rows = board_letters.size();
    int cols = board_letters.size();
    vector<vector<char>> board(rows, vector<char>(cols));
    vector<vector<char>> permutations;
    generate_permutations(const_cast<vector<char>&>(board_letters), 0, permutations);

    bool solution_found = false;
    for (const auto& perm : permutations) {
        insert_words(board, words_to_find);
        fill_empty(board, perm);
        if (check_board(board, words_to_find, words_not_to_find)) {
            print_board(board, output_file);
            solution_found = true;
            if (command == "one_solution") {
                break;
            }
        }
    }

    if (!solution_found) {
        output_file << "No solution" << endl;
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

//function out print out the solutiosn in this format
/*
4 solution(s)
Board: 
  one
  cat
Board: 
  cat
  one
Board: 
  eno
  tac
Board: 
  tac
  eno
*/

void print_solutions(const vector<string>& words_to_find, const vector<string>& words_not_to_find, const vector<char>& board_letters, ofstream& output_file, const string& command){
    if (command == "one_solution" || command == "all_solutions"){
        vector<vector<char>> board(board_letters.size(), vector<char>(board_letters.size(), ' '));
        fill_empty(board, board_letters);
        vector<vector<char>> original_board = board;
        int solution_count = 0;
        vector<vector<char>> permutations;
        generate_permutations(board_letters, 0, permutations);
        for (const auto& perm : permutations) {
            board = original_board;
            fill_empty(board, perm);
            if (check_board(board, words_to_find, words_not_to_find)) {
                solution_count++;
                output_file << "Board: " << endl;
                print_board(board, output_file);
            }
        }
        output_file << solution_count << " solution(s)" << endl;
    }
    else{
        output_file << "Invalid command" << endl;
    }
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

    //insert the words into the board
    insert_words(board, words_to_find);
//print out the board for testnng
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    //check if the words are in the board and the words not to find are not in the board
    if (check_board(board, words_to_find, words_not_to_find)) {
        fill_empty(board, board_letters);
        print_board(board, output_file);
    } else {
        output_file << "No solution" << endl;
    }

    //print out possible solutions to the board
    print_solutions(words_to_find, words_not_to_find, board_letters, output_file, command);
    return 0;
    
}