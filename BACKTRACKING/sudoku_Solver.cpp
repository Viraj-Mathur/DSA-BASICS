#include <bits/stdc++.h>

using namespace std;

// tweak done -> make it bool : therefore no need for base case

bool isSafe(int value, int board[][9], int curr_row, int curr_col) {
    // row check
    for (int col = 0; col < 9; col++) {
        if (board[curr_row][col] == value) {
            return false; // not safe
        }
    }

    // column check
    for (int row = 0; row < 9; row++) {
        if (board[row][curr_col] == value) {
            return false; // not safe
        }
    }

    // checking under the 3*3 matrix - the tricky part
    // mathematical formula to check : for row = (3*(row/3) + i/3) for col = (3*(col/3) + i%3) where i = 0..8 and (row,col) are the coordinates

    for (int i = 0; i < 9; i++) {
        if (board[3 * (curr_row / 3) + (i / 3)][3 * (curr_col / 3) + (i % 3)] == value) {
            return false; // not safe
        }
    }

    return true;
}

bool solve(int board[9][9], int n) {
    // as 2d matrix we need 2 loops to traverse
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // checking for empty cells
            if (board[i][j] == 0) {
                for (int value = 1; value <= 9; value++) {
                    // check for safe cells
                    if (isSafe(value, board, i, j)) {
                        // insert if safe
                        board[i][j] = value;

                        // recursive action for every cell filling
                        bool aageKaSol = solve(board, n);

                        // Found solution or not?
                        // This if condition is the reason we don't need a base case
                        if (aageKaSol == true) {
                            return true;
                        }
                        // backtrack if solution not found
                        else {
                            board[i][j] = 0;
                        }
                    }
                }
                return false; // If no solution from 1 to 9, then that means previous placement has some fault
            }
        }
    }
    return true; // meaning all cells are filled
}

int main() {
    int board[9][9] = {
        {4, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 7, 0, 6, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 8},
        {0, 0, 0, 9, 5, 0, 0, 0, 0},
        {0, 8, 6, 0, 0, 0, 2, 0, 0},
        {0, 2, 0, 6, 0, 0, 7, 5, 0},
        {0, 0, 0, 0, 0, 0, 4, 7, 6},
        {0, 7, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 9, 0, 0, 0}
    };

    int n = 9;
    solve(board, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
Time Complexity: 𝑂(9^(n^2))

Space Complexity: 𝑂(n^2)
