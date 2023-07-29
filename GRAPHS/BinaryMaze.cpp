// FIND THE SHORTEST DISTANCE IN A BINARY MAZE - USING DIJKSTRA ALGO

/*
Problem Statement: 

Given an n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between 
a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between the source cell and the destination cell, then return -1.

Note: You can move into an adjacent cell if that adjacent cell is filled with element 1. 
Two cells are adjacent if they share a side. In other words, you can move in one of four directions, Up, Down, Left, and Right.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        // if source is the destination
        if(source.first == destination.first && source.second == destination.second) return 0;

        // creating a queue for storing distance from source in the form -> {dist,{cell coordinates pair}}
        queue<pair<int, pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // creating a distance matrix with all initially marked as infinity(unvisited) and source as 0
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first ,source.second}});

        // creating moving rules(in 4 directions)
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        // iterating through maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i=0;i<4;i++){
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                // Checking the validity of the cell and updating if dist is shorter
                if(newRow >=0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == 1 && dis + 1 < dist[newRow][newCol]){
                    dist[newRow][newCol] = 1 + dis;

                    // return distance when destination is reached
                    if(newRow == destination.first &&
                        newCol == destination.second){
                            return dis + 1;
                        }
                    q.push({1 + dis, {newRow ,newCol}});
                }
            }
        }

        // if now path found
        return -1; 
    }
};

int main(){

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 0, 1},
                                {1, 0, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);
    cout<<"Shortest Path took moves = ";
    cout << res;
    cout << endl;

    
    return 0;
    
}