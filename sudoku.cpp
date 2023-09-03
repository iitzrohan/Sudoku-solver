#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function to check if a number can be placed in a given cell
bool isValid(vector<vector<int>> &board, int row, int col, int num) {
    // Check if the number is not present in the current row and column
    for (int i = 0; i < SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check if the number is not present in the 3x3 subgrid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>> &board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            // Find an empty cell
            if (board[row][col] == 0) {
                // Try placing numbers 1 to 9 in the cell
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(board, row, col, num)) {
                        // Place the number if it's valid
                        board[row][col] = num;

                        // Recursively try to solve the remaining Sudoku
                        if (solveSudoku(board)) {
                            return true; // Solution found
                        }

                        // If placing the number doesn't lead to a solution, backtrack
                        board[row][col] = 0;
                    }
                }
                return false; // No valid number can be placed
            }
        }
    }
    return true; // Sudoku is solved
}

// Function to print the Sudoku board
void printSudoku(const vector<vector<int>> &board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a Sudoku is valid and solve if possible
void checkAndSolveSudoku(vector<vector<int>> &board) {
    if (solveSudoku(board)) {
        cout << "Valid Sudoku with Solution:\n";
        printSudoku(board);
    } else {
        cout << "Invalid Sudoku\n";
    }
}

int main() {
    vector<vector<int>> sudokuBoard = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}};
    cout << "Enter the Sudoku board (0 for empty cells):\n";
    for (int i = 0; i < SIZE; ++i) {
        vector<int> row;
        for (int j = 0; j < SIZE; ++j) {
            int cell;
            cin >> cell;
            row.push_back(cell);
        }
        sudokuBoard.push_back(row);
    }

    checkAndSolveSudoku(sudokuBoard);

    return 0;
}
