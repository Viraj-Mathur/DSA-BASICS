/*
The intuition is that we start from a node, and start doing BFS level-wise, 
if somewhere down the line, we visit a single node twice, it means we came via two paths to end up at the same node. 
It implies there is a cycle in the graph because we know that we start from different directions 
but can arrive at the same node only if the graph is connected or contains a cycle, otherwise we would never come 
to the same node again.  
*/

// Given an undirected graph with V vertices and E edges check whether it contains any cycle or not. 
// Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

#include <bits/stdc++.h>

using namespace std;

class Solution {

  private:
    bool detect(int source, vector<int> adj[], int vis[]){
        vis[source] = 1;
        // store <source node ,parent node>
        queue<pair<int, int>> q;
        q.push({source, -1});
        // traverse till queue is empty
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // go to adjency node
            for(auto adjencyNode: adj[node]){
                // if adjency node is unvisited
                if(!vis[adjencyNode]){
                    vis[adjencyNode] = 1;
                    q.push({adjencyNode, node});
                }
                // if adjency node is visited but not from its own parent node(thereby making it a cycle)
                else if(parent!= adjencyNode){
                    return true; //as it is a cycle then
                }
            }
        } 
        // if no cycle
        return false;

    }

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // first initialise as unvisited
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    
    return 0;
}