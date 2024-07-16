/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents 
that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it. 
Return the list of paths in lexicographically increasing order.
 
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

*/

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int x, int y, int row, int col, vector<vector<int>>& arr, vector<vector<bool>>& visited) {
    // 3 conditions should be satisfied
    // not out of bounds
    // should not go to visited box
    // should not go where box is blocked i.e 0

    if ((x >= 0 && x < row) && (y >= 0 && y < col) && (arr[x][y] == 1 && !visited[x][y])) {
        return true;
    } else {
        return false;
    }
}

void solveMaze(vector<vector<int>>& arr, int row, int col, int i, int j, vector<vector<bool>>& visited, vector<string>& path, string output) {
    // base case
    if (i == row - 1 && j == col - 1) {
        path.push_back(output);
        return;
    }

    // solving cases 

    // down
    if (isSafe(i + 1, j, row, col, arr, visited)) {
        visited[i + 1][j] = true; //mark it as visited
        solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');

        // now backtrack in case of failure by marking visited false again
        visited[i + 1][j] = false;
    }

    // up
    if (isSafe(i - 1, j, row, col, arr, visited)) {
        visited[i - 1][j] = true; //mark it as visited
        solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');

        // now backtrack in case of failure by marking visited false again
        visited[i - 1][j] = false;
    }

    // left
    if (isSafe(i, j - 1, row, col, arr, visited)) {
        visited[i][j - 1] = true; //mark it as visited
        solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');

        // now backtrack in case of failure by marking visited false again
        visited[i][j - 1] = false;
    }

    // right
    if (isSafe(i, j + 1, row, col, arr, visited)) {
        visited[i][j + 1] = true; //mark it as visited
        solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');

        // now backtrack in case of failure by marking visited false again
        visited[i][j + 1] = false;
    }
}

int main() {
    vector<vector<int>> maze = { { 1, 0, 0, 0 },
                                  { 1, 1, 0, 1 },
                                  { 1, 1, 0, 0 },
                                  { 0, 1, 1, 1 } };

    int row = maze.size();
    int col = maze[0].size();

    if (maze[0][0] == 0) {
        cout << "No Path exists";
        return 0;
    }

    // Creating a 2D array for visited array
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    // Source value should be 1 as rat is standing on it only
    visited[0][0] = true;
    // Create string which stores all the paths
    vector<string> path;
    string output = "";
    solveMaze(maze, row, col, 0, 0, visited, path, output);

    for (auto i : path) {
        cout << i << " ";
    }
    cout << endl;

    if (path.size() == 0) { // Destination is only blocked
        cout << "No path exists";
    }

    return 0;
}