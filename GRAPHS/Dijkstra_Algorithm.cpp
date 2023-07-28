#include <bits/stdc++.h>

using namespace std;



// using Priority Queue in this approach for finding the shortest distances
// Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.
// Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Priority queue containig pairs of the type {dist, node},using a min-heap and a distance array of size V(no of nodes) 
        // initialized with infinity and initialize the distance to source node as 0. 
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        // initialise distance to infinity
        vector<int> distTo(V, INT_MAX);

        // let source initialise to 0

        distTo[S] = 0;
        pq.push({0,S});
        
        // pop minimum dist from node first from min heap and traverse the adjency list
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                int v = it[0];
                int w = it[1];
                if(distance + w < distTo[v] ){
                    distTo[v] = distance + w;
                    // if current node is smaller push it in a queue
                    pq.push({distance+w ,v}); 
                }
            }
        }
        return distTo;
    }
};



// Using Set Approach
// as set store data in ascending order just like we needed in Priority Queue

class Sol2{
    public:
      vector <int> dijkstra_set(int V, vector<vector<int>> adj[], int S){
        // create a set -> {dist,node} stores node in ascending order
        set<pair<int,int>> st;
        // initialise distance to infinity
        vector<int> dist(V, INT_MAX);

        st.insert({0,S});
        // source initialised to 0
        dist[S] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it); //erase the min distance from the set

            // Check for all adjacent nodes of the erased element whether the prev dist is larger than current or not.
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgW = it[1];

                if(dis + edgW < dist[adjNode]){
                    // erase if visited previously
                    if(dist[adjNode]!= INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }

                        // if current distance is smaller push it in the set
                        dist[adjNode] = dis+ edgW;
                        st.insert({dist[adjNode], adjNode});
                    
                }
            }
        }
        return dist;
      }
};

int main(){
    
     int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);
    
    cout<<"Minimum distances are: "<<endl;
    cout<<"1. Using priority queue in Dijkstra Algorithm: "<<endl;
    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    cout<<"2. Using set data structure in Dijkstra Algorithm: "<<endl;

    Sol2 d1;
    vector<int> ans = d1.dijkstra_set(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}