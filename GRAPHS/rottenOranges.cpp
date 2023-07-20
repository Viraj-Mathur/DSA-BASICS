/*
Rotten Oranges

Problem Statement: Given a grid of dimension N x M where each cell in the grid can have values 0, 1, or 2 
which has the following meaning:

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] 
can rot other fresh oranges at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // grid size for rows and col
        int n = grid.size();
        int m = grid[0].size();

        // store data -> {{row, col}, time}

        queue<pair<pair<int,int> , int >> q;

        int vis[n][m];
        int cntFresh = 0; // initialsing the count with 0
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if cell contains rotten oranges
                
                if(grid[i][j] ==2 ){
                    q.push({{i,j},0});
                    // mark the rotten (2) as visited
                    vis[i][j] = 2;
                }

                // if not rotten
                else{
                    vis[i][j] = 0;
                }

                // counting the fresh oranges
                if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }

            int time = 0;
            // delta row and col
             int drow[] = {-1, 0, +1, 0};
             int dcol[] = {0, 1, 0, -1}; 
             int cnt = 0;

            //  bfs traversal until queue becomes empty

            while(!q.empty()){

                // store data -> {{row, col}, time}

                int r = q.front().first.first; // row 
                int c = q.front().first.second; // col
                int t = q.front().second;

                time = max(time,t);
                q.pop();

                // as there are four neighbours

                for(int i=0;i<4;i++){
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];

                    // check for valid cell and then unvisited fresh oranges

                    if(nrow >=0 && nrow<n && ncol >=0 && ncol <m && 
                       vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        // push in queue with time increased
                        q.push({{nrow,ncol}, t+1 });
                        // mark as rotten 
                        vis[nrow][ncol] = 2;
                        cnt++;

                       }
                }
            }

               // if all oranges are not rotten
                if (cnt != cntFresh) return -1;

                return time;




        }

    
};


int main(){
    
  vector<vector<int>>grid{{1,1,2},{0,1,2},{2,0,1}};
  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << "Total Time Taken to Rott: "<< ans << "\n";


  return 0;
}