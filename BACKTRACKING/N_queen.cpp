/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

*/

#include <bits/stdc++.h>

using namespace std;


void printSolution(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] == 1 ? 'Q' : '.') << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    // function to check for safe movements; no queen should be attacking

    // Check three directions -> upper left diagonal, left row, bottom left diagonal

    int i = row;
    int j = col;

    // Check left row first
    while (j >= 0) {
        if (board[i][j] == 1) { // Queen found and hence can't place it here
            return false;
        }
        j--;
    }

    // Check upper left diagonal
    i = row;
    j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) { // Queen found and hence can't place it here
            return false;
        }
        i--;
        j--;
    }

    // Check bottom left diagonal
    i = row;
    j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 1) { // Queen found and hence can't place it here
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<int>>& board, int col, int n) {
    // base case - When we have placed queens in all the columns then col will go to n
    if (col == n) {
        printSolution(board, n);
        return;
    }

    // Solve one case
    // In every row, place the queen
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            // action
            board[row][col] = 1;
            // recursive call for col + 1
            solve(board, col + 1, n);
            // backtracking by clearing the queen placed
            board[row][col] = 0; // Queen removed
        }
    }
}


int main() {
    int n = 20;
    // Initially all are zeroes in the nxn chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col = 0;
    solve(board, col, n);
    return 0;
}