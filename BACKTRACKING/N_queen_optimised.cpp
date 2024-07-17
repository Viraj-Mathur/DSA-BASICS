/*
An optimised version of N-Queen problem
Optimisation is done on the isSafe function because the each directions -> upper left diagonal, left row, bottom left diagonal take O(n) time to execute 
so inorder to reduce the time we will use unordered map to store diractions
This allows quick O(1) checks and updates for row conflicts.
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int,bool>rowCheck;
unordered_map<int,bool>upperLeftDiagonalCheck;
unordered_map<int,bool>lowerLeftDiagonalCheck;


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
    // using map to check directions
    if(rowCheck[row] == true){
        return false;
    }
    if(upperLeftDiagonalCheck[col-row] == true){
        return false;
    }
    if(lowerLeftDiagonalCheck[row+col] == true){
        return false;
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

            // Map modifications
            rowCheck[row] = true;
            upperLeftDiagonalCheck[col-row] = true;
            lowerLeftDiagonalCheck[row+col] = true;

            // recursive call for col + 1
            solve(board, col + 1, n);
            // backtracking by clearing the queen placed
            board[row][col] = 0; // Queen removed

            // backtracking map modifications
            rowCheck[row] = false;
            upperLeftDiagonalCheck[col-row] = false;
            lowerLeftDiagonalCheck[row+col] = false;
        }
    }
}


int main() {
    int n = 4;
    // Initially all are zeroes in the nxn chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col = 0;
    solve(board, col, n);
    return 0;
}