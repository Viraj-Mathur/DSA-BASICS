/*
    In DFS, we start with a node ‘v’, mark it as visited and store it in the solution vector. It is unexplored as its adjacent nodes are not visited.

    We run through all the adjacent nodes, and call the recursive dfs function to explore the node ‘v’ 

    which has not been visited previously. This leads to the exploration of another node ‘u’ which is its adjacent node
    and is not visited.

    The adjacency list stores the list of neighbours for any node. Pick the neighbour list of node ‘v’ 
    and run a for loop on the list of neighbours (say nodes ‘u’ and ‘w’ are in the list). We go in-depth with each node.
    When node ‘u’ is explored completely then it backtracks and explores node ‘w’.

    This traversal terminates when all the nodes are completely explored. 
*/




#include <bits/stdc++.h>

using namespace std;


class Solution {
    private:
    // recursive function for dfs
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &list) {
        vis[node] = 1;
        list.push_back(node);
        // traverse all the neighbours
        for(auto i: adj[node]){
            // if not visisted
            if(!vis[i]){
                dfs(i, adj, vis ,list); //recursion function
            }
        }
    }

    public:

    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        int vis[V] = {0};
        int start = 0; // 0 based indexing
        vector<int> list;
        dfs(start ,adj, vis, list);
        return list;
    }

};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
