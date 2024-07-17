/*

980. Unique Paths III

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 Example 1:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    int travel(vector<vector<int>>& grid, int i,int j,int visited){
        int n = grid.size();
        int m = grid[0].size();
        
        // base case - return 0 if out of bound no place to traverse or obstacle
        if(i>=n|| i<0 || j>=m || j<0 || grid[i][j] == -1 ){
            return 0;
        }
        // if all empty places are visited
        if (grid[i][j] == 2) {
            if (visited == 0) {
                return 1;
            } 
            else {
                return 0;
            }
        }

        // mark all the cells visited
        grid[i][j] = -1;
        visited--;

        // exploring all possible path using recursion taking directions into consideration
        int paths = travel(grid,i+1,j,visited) + travel(grid,i-1,j,visited) + travel(grid,i,j+1,visited) + travel(grid,i,j-1,visited);

        // backtracking - if no answer found in recursion backtrack and unmark the cell as visited
        grid[i][j] = 0;
        visited++;

        return paths;

    }


public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x = 0, start_y = 0, visited = 1; // starting with (0,0) coordinate and mark visited as 1

        // Find the starting point and count the number of empty cells
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                else if(grid[i][j] == 0){
                    visited++;
                }
            }
        }

        // recursive traversal

        return travel(grid,start_x,start_y,visited);

        
    }
};

int main(){
    
    return 0;
}