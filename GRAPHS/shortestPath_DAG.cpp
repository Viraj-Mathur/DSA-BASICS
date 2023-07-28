
// Given a DAG, find the shortest path from the source to all other nodes in this DAG. 
// In this problem statement, we have assumed the source vertex to be ‘0’. You will be given the weighted edges of the graph.

#include <bits/stdc++.h>

using namespace std;

class Solution {

  private:
    // topo sort using DFS
    void topoSort(int node, vector<pair<int, int >> adj[],
                    int vis[], stack <int> &st){
         vis[node] = 1; // making the current node visited
         for(auto it: adj[node]){
            int v = it.first; // to extract vertex from pair (vertex, distance)
            if(!vis[v]){
                topoSort(v,adj,vis,st);
            }
         }       

         st.push(node);
    }

  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // creating a graph from adjacency list
        vector<pair<int,int>> adj[N]; // (vertex, distance)
        for(int i=0;i<M ;i++){
            // [u, v, wt], where u is the starting vertex of the edge, v is the ending vertex of the edge, and wt is the weight of the edge.
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }

        // a visited array is created initially and all nodes are marked as unvisited{0}
        int vis[N] = {0};

        // perform topo sort and store it in a stack
        stack<int> st;
        for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

        vector < int > dist(N);

        for(int i=0;i<N;i++){
            dist[i] = INT_MAX; //MARKING DIST VECTOR AS INFINITE
        }

        dist[0] = 0; //marking distance of starting node as 0, the same node
        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;

                // checking for shortest route
                if (dist[node] + wt < dist[v]){
                    dist[v] = wt + dist[node];
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

int main(){
    
    return 0;
}