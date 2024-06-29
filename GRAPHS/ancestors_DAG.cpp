/*
2192. All Ancestors of a Node in a Directed Acyclic Graph : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

*/

#include <bits/stdc++.h>

using namespace std;

/*
Intuition:
Ancestors: An ancestor of a node is any node that can reach it by following directed edges.
For example, if there's a path A -> B -> C, then both A and B are ancestors of C.
Since the graph is acyclic, this problem can be efficiently solved using Depth-First Search (DFS).

Approach
Graph Representation:

Use an adjacency list to represent the graph. This allows efficient traversal of the graph.
DFS for Ancestor Tracking:

Perform a DFS from each node to identify all nodes that can reach the current node. During this traversal, mark nodes as visited to avoid cycles and repeated work.
While performing the DFS, if we reach a node, we add the starting node (ancestor) to the list of ancestors for the reached node.
Result Collection:

Initialize a list of lists to store the ancestors for each node. Each index corresponds to a node and contains a list of its ancestors.
Sorting:

After collecting all ancestors using DFS, sort the ancestor lists to meet the requirement of ascending order.
Complexity

Time Complexity:
Building the graph: ( O(m) ), where ( m ) is the number of edges.
DFS from each node: ( O(n ⋅ (n + m)) ) in the worst case, where ( n ) is the number of nodes and ( m ) is the number of edges. Each DFS can traverse up to all nodes and edges.
Sorting the ancestors: ( O(n ⋅ k log k) ), where ( k ) is the average number of ancestors per node.
The overall time complexity is ( O(n ⋅ (n + m)) ) considering the nested DFS traversal.

Space Complexity:
Storing the graph: ( O(n + m) ).
Storing the ancestors: ( O(n ⋅ n) ) in the worst case if every node is an ancestor of every other node.
Additional space for recursion stack in DFS: ( O(n) ).



*/

class Solution {
private:
    // DFS function to find ancestors
    void dfs(const vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& res, vector<bool>& visited) {
        visited[curr] = true;
        for (int dest : graph[curr]) {
            if (!visited[dest]) {
                // Add the parent as an ancestor of the destination node
                res[dest].push_back(parent);
                // Recursive call for the destination node
                dfs(graph, parent, dest, res, visited);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize result vector and graph
        vector<vector<int>> res(n);
        vector<vector<int>> graph(n);

        // Build the graph from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Perform DFS from each node
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            dfs(graph, i, i, res, visited);
        }

        // Sort the ancestors for each node
        for (int i = 0; i < n; i++) {
            sort(res[i].begin(), res[i].end());
            // Remove duplicates if any
            res[i].erase(unique(res[i].begin(), res[i].end()), res[i].end());
            // Remove the node itself from its ancestors list
            if (!res[i].empty() && res[i][0] == i) {
                res[i].erase(res[i].begin());
            }
        }

        return res;
    }
};

int main(){
    
    return 0;
}