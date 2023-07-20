/*
QUESTION: Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally
or vertically or diagonally i.e., in all 8 directions.
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
  private:
    // function for bfs traversal
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1; // marking visited as 1
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size(); // row size 
        int m = grid[0].size(); // col size

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

        // to traverse the neighbouring elements of the islands(checking for 1s (rows and cols))
        for(int delrow = -1; delrow <= 1 ; delrow++ ){
            for(int delcol = -1; delcol <= 1 ; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;

                // satisfying the required conditions
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol <m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});

                }
            }
        }

        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); // size of rows
        int m = grid[0].size(); // size of columns
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};

// T.C = O(N^2)

int main(){
    
    return 0;
}
