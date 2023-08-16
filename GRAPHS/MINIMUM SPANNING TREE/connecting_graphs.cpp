/*
PROBLEM STATEMENT:
    You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between 
    any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. 
    If it is not possible to make the graph connected, 
    return -1.

INTUITION:
    we need a minimum of nc-1 edges (nc = no. of components of the graph) to make the graph connected. 
    And according to the question, to add these nc-1 edges, the graph must contain a minimum of nc-1 extra edges. 

    if a graph contains nc-1 extra-edges, we can make the graph connected with just nc-1 operations
    (where nc = no. of components of the graph).

    the extra edges are the ones which can be used to ultimately connect the different components of the graphs

*/

#include <bits/stdc++.h>

using namespace std;
// same function for implementing the  disjoint sets
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it:edge){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtras++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
    int cntC = 0;
    for(int i=0;i<n;i++){
        if(ds.parent[i] == i)
            cntC++;
    }
    int ans = cntC - 1;

    // if bigger than return -1
    if(cntExtras >= ans)
        return ans;
        return -1;
    }
};

int main(){
    
    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}