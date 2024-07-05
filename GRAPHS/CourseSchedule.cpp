/*
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

// This question is almost similar to topological sort

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // Depth-First Search to detect cycles in the course dependency graph
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]){
        vis[node] = 1;       // Mark current node as visited
        pathVis[node] = 1;   // Mark current node as part of current DFS path

        // Explore all adjacent nodes (courses that depend on the current course)
        for(auto it: adj[node]){
            if(!vis[it]){
                // If adjacent node is not visited, perform DFS on it
                if(dfs(it, vis, pathVis, adj)) return true;  // Cycle detected in deeper level
            }
            else if(pathVis[it]) return true;  // Cycle detected in current path
        }

        pathVis[node] = 0;   // Backtrack: remove current node from path
        return false;        // No cycle detected for this path
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list to represent the course dependency graph
        vector<int> adj[numCourses];

        /*
        adj[pre[1]].push_back(pre[0]); does the following:
        pre[1] represents course b (the prerequisite).
        pre[0] represents course a (the course that depends on b).
        adj[pre[1]] accesses the list of courses that depend on course b.
        .push_back(pre[0]) adds course a to the list of courses that depend on course b.
        */
        for(auto el:prerequisites){
            adj[el[1]].push_back(el[0]);
        }

        // Initialize vectors to keep track of visited nodes and nodes in current path
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0);

        // Perform DFS for each unvisited course
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)) return false;
            }
        }

        // If no cycle is detected, it's possible to finish all courses
        return true;     

        // If a cycle is detected during DFS, the function returns false, indicating that it is not possible to finish all courses.
    }
};

int main(){
    
    return 0;
}