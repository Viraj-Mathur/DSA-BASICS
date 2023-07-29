// Printing the shortest path in Dijkstra’s Algorithm (using priority queue)

#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // adjacency list of pairs of the form node1 -> {node2, edge weight}
        vector<pair<int,int>> adj[n+1]; // n+1 coz of zero based indexing
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // priority queue of {dist,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        // Create a dist array for storing the updated distances and a parent array
        //for storing the nodes from where the current nodes represented by indices of
        // the parent array came from.

        vector<int> dist(n+1, INT_MAX), parent(n+1); // creating dist and parent vectors
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        dist[1] = 0; // initialsing source dist as 0
        // pushing source in a queue
        pq.push({0,1});
        
        while (!pq.empty())
        {
        //    topmost element of priority queue
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // iterate through adjacent nodes
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                
                // Check if the previously stored distance value is 
                // greater than the current computed value or not, 
                // if yes then update the distance value.

                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    // update the parent node
                    parent[adjNode] = node;
                }
                
            }
        }

        // if distance is not found return -1
        if(dist[n] == INT_MAX) return {-1};

        // store the final path in a "path" array
        vector<int> path;
        int node = n;
        // Iterating backwards from destination to source through the parent array.
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }

        // manually adding the source node to the path vector becasue the loop does not add it
        path.push_back(1);
        // reversing the path as the result is stored backwards
        reverse(path.begin(), path.end());
        return path;
        
    }
};

int main(){


    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);
    
    cout<<"The Path covered is: "<<endl;

    for (int i = 0; i < path.size(); i++)
    {

        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}