/*

1976. Number of Ways to Arrive at Destination

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/


#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n];

        // Build the adjacency list
        for (auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        /*

        For road [0,6,7]:
            - adj[0].push_back({6, 7})  // Node 0 connects to Node 6 with weight 7
            - adj[6].push_back({0, 7})  // Node 6 connects to Node 0 with weight 7 (undirected)

        For road [0,1,2]:
            - adj[0].push_back({1, 2})  // Node 0 connects to Node 1 with weight 2
            - adj[1].push_back({0, 2})  // Node 1 connects to Node 0 with weight 2

        After processing all roads, adj will look like this:
            
            adj[0] = [{6,7}, {1,2}, {4,5}]       // Node 0 connects to nodes 6,1,4
            adj[1] = [{0,2}, {2,3}, {3,3}]       // Node 1 connects to nodes 0,2,3
            adj[2] = [{1,3}, {5,1}]              // Node 2 connects to nodes 1,5
            adj[3] = [{1,3}, {6,3}, {5,1}]       // Node 3 connects to nodes 1,6,5
            adj[4] = [{0,5}, {6,2}]              // Node 4 connects to nodes 0,6
            adj[5] = [{3,1}, {6,1}, {2,1}]       // Node 5 connects to nodes 3,6,2
            adj[6] = [{0,7}, {3,3}, {5,1}, {4,2}]// Node 6 connects to nodes 0,3,5,4

        */


        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);  // Change to long long to prevent overflow
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        int mod = int(1e9 + 7);

        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;  // Use long long here as well
            int node = pq.top().second;
            pq.pop();

            for (auto& n : adj[node]) {
                int adjNode = n.first;
                int w = n.second;

                // If a shorter path to adjNode is found
                if (dis + w < dist[adjNode]) {
                    dist[adjNode] = dis + w;
                    pq.push({dis + w, adjNode});
                    ways[adjNode] = ways[node]; // Reset ways count for new shortest path
                }
                // If another path with the same shortest distance is found
                else if (dis + w == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};


int main(){
    
    return 0;
}