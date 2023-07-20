// Problem Statement: Given a binary grid of N*M. Find the distance of the nearest 1 in the grid for each cell.

/* Approach: Use BFS 
             Visited array: an array initialized to 0 indicating unvisited nodes.  
             Distance matrix: stores the distance of the nearest cell having 1 for every particular cell.

             For every neighboring unvisited 0, we can mark the distance to be +1 of the current node distance 
             and store it in the distance 2D array, and at the same time insert <{row, col}, steps+1> into the queue.
             
Repeat the steps until the queue becomes empty and then return the distance matrix where we have stored the steps.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(); // size of row;
        int m = grid[0].size(); // size of column

        // making visited and distance matrix
        vector<vector<int>> vis( n, vector<int>(m,0) );
        vector<vector<int>> dist( n, vector<int>(m,0) );

        // queue -> {coordinates , steps}

        queue<pair<pair<int,int> , int>> q;
        // traversing the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // start BFS is cell contains 1
                if(grid[i][j] == 1){ // for every 1
                    q.push({{i,j}, 0}); // mark the distance matrix as 0
                    vis[i][j] = 1; // mark the visited matrix as 1
                }
                else{
                    // mark unvisited
                    vis[i][j] = 0;
                }

            }
        }

        // neighbouring traversal logic

        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1};

        // traverse till queue becomes empty
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            // for all 4 neighbours
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // check for valid unvisited cell
                if(nrow >=0 && nrow < n && ncol >=0 &&
                   ncol < m && vis[nrow][ncol] ==0){
                    vis[nrow][ncol] = 1; // marking neighbouring as 1
                    q.push({{nrow, ncol} ,steps+1});
                   }
            }
        } 

        // return distance matrix
        return dist;
	}
};

int main(){

    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
    
    return 0;
}