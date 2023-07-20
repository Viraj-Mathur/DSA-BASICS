

// Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province 
// if there is a path from u to v or v to u. Your task is to find the number of provinces.


#include <bits/stdc++.h>

using namespace std;


class Solution {

    private:
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;
        for(auto i: adjLs[node]){
            if(!vis[i]){
                dfs(i, adjLs,vis);
            }
        }
    }

    public:
    int numProvinces(vector<vector<int>> adj, int V) {
// creating adjency list as adjency matrix is given
        vector<int> adjLs[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        // counting the number of for loops -> the number of count will contain the no of provinces
        int vls[V] = {0};
        int count = 0;
        for(int i=0;i<V;i++){
            if(!vls[i]){
            count++;
            dfs(i,adjLs, vls);
            }
        }
        return count;
    }


};

int main(){
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << "The number of provinces are: " <<ob.numProvinces(adj,3) << endl;
    cout<<endl;
        
    return 0;
}

