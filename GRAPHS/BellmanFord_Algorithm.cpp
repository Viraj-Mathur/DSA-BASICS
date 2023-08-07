// Bellman Ford Algorithm: use to find shortest path between source and destination node
// USAGE: can also find distance in negative cycle
// CAN ONLY BE USED IN THE DIRECTED GRAPHS

// https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/

// Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.

// Space Complexity: O(V) for the distance array which stores the minimized distances.

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        for(int i=0;i<V-1;i++){
            // works till v-1 nodes
            for (auto it : edges){
            int nodeA = it[0];
            int nodeB = it[1];
            int weight = it[2];

                if(dist[nodeA] != INT_MAX && dist[nodeA] + weight < dist[nodeB]){
                    dist[nodeB] = dist[nodeA] + weight;
                    // loop till n-1 will traverse every node in each cycle
                }
            }
        }
    

    // Nth loop will give relaxation to check for negative cycle
        for(auto it: edges){
            int nodeA = it[0];
                int nodeB = it[1];
                int weight = it[2];

                if(dist[nodeA] != INT_MAX && dist[nodeA] + weight < dist[nodeB]){
                    // return -1 in case of negative cycle
                    return {-1};
                }
        }

        return dist;
    }
};




int main(){
    
    int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);
	cout<<"Distances between nodes are: ";
    for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

    return 0;
}