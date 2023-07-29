/*
Cheapest Flights Within K Stops

There are n cities and m edges connected by some number of flights. You are given an array of flights where 
flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost price. 
You have also given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

// DIJKSTRA ALGO WILL NOT WORK HERE AS WE NEED CHEAPEST CONSIDERING GIVEN STOPS NOT THE SHORTEST ROUTE
*/

#include <bits/stdc++.h>

using namespace std;

/*
We store the elements in terms of the minimum number of stops in the queue (priority queue is not needed here) so that when the algorithm halts, 
we can get the minimum cost within limits.
*/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        // creating adjancency list to form a graph of airports and flights

        vector<pair<int, int >> adj[n];

        for (auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // creating a queue in the form -> {stops, {node, dist}}
        queue<pair<int, pair< int,int>>> q;

        q.push({0, {src, 0}}); // source as 0

        // a distance array to store the updated distances from the source
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Iterate through the graph using a queue like in Dijkstra with 
        // popping out the element with min stops first.

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We stop as soon as the limit of the stops(K) is reached
            if(stops > K)
                continue;
            for(auto iter : adj[node]){
         
                int adjNode = iter.first;
                int edW = iter.second;

                // update the queue only when new dist is less than the prev and the stops are also within limits

                if( cost + edW < dist[adjNode] && stops<=K){
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost+ edW}});
                }

            }
        }
        // If the destination node is unreachable return ‘-1’
        //  else return the calculated dist from src to dst.
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];

    }
};

int main(){

    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;

    int ans = obj.CheapestFLight(n, flights, src, dst, K);

    cout << "Cheapest Flights within K stops are : "<< ans;
    cout << endl;
    
    return 0;
}