// Kosaraju’s Algorithm for finding number of Strongly Connected Components

/*
A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices (u, v) 
inside that component, u is reachable from v and v is reachable from u.

Strongly connected components(SCC) are only valid for directed graphs. 
*/ 




#include <bits/stdc++.h>
using namespace std;

class Solution
{

    private:
    // funct for DFS
     void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    private:
    void dfs2(int node, vector<int> &vis, vector<int> adjT[]){
        vis[node] = 1;
        for(auto it: adjT[node]){   //adjacency matrix transpose
            if(!vis[it]){
                dfs2(it,vis,adjT);
            }
        }
    }

	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int>adj[])
    {
        // STEP 1: SORT THE GRAPH
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // STEP 2: REVERSE THE GRAPH BY TAKING TRANSPOSE OF THE ADJECENCY LIST
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }

        // STEP 3: PERFORM DFS AND COUNT THE NUMBER OF DFS CALL IT WILL GIVE YOU THE NO. OF SCCs
        int scc = 0; //count for scc
        while(!st.empty()){
            int node  =st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,vis,adjT);
            }
        }

        return scc;        
    }
};






int main(){
    
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}