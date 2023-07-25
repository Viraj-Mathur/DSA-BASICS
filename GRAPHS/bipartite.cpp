/*
Bipartite Graph | BFS and DFS implementation

If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a bipartite graph.
lET TWO COLORS BE 1 AND 0 INITIALISING WITH 0
*/


#include <bits/stdc++.h>

using namespace std;

// USING BFS
class Solution {
private:
// function for coloring and checking the component
    bool check(int start, int V, vector<int>adj[], int color[]){
        queue<int>q;
        q.push(start);
        color[start] = 0; //let first color be 0
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                // if adjency node is not yet colored
                // give the color opposite to corresponding color
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // if adjency list have the same color someone already color at some other path so false
                else if(color[it] == color[node]){
                    return false;
                } 
            }
        }  
        return true;
    }

public:
	bool isBipartite_BFS(int V, vector<int>adj[]){
	    int color[V];
        for(int i=0; i<V;i++){
            color[i] = -1; //making everything -1 
        }
        for(int i=0;i<V;i++){
            // if not colored
            if(color[i] == -1){
                // check if previous color is same or not
                if(check(i,V,adj,color) == false){
                    return false;
                }
            }
        }
        return true;
	}

};

// USING DFS
class Sol2 {
    private:
        bool dfs(int node, int col, int color[], vector<int> adj[]){
            color[node] = col;
            // traverse adjacent node
            for(auto it: adj[node]){
                // if uncolored
                if(color[it] == -1){
                    if(dfs(it, !col, color ,adj) == false) return false;
                }
                // if previous colored and have same color
                else if(color[it] == col){
                    return false;
                }
            }
            return true;
        }

    public:
        bool isBipartite_DFS(int V, vector<int>adj[]){
            int color[V];
            for(int i=0;i<V;i++){
                color[i] = -1;
            }
                // for connected components
            for(int i=0;i<V;i++){
                if(color[i] == -1){
                    if(dfs(i,0,color, adj) == false)
                        return false;
                }
            }
            return true;
        }

};








void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){

    // V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

    cout<<"Using BFS"<<endl;
    
	Solution obj;
	bool ans = obj.isBipartite_BFS(4, adj);    
	if(ans)cout << "It is a bipartite Graph \n";
	else cout << "It is not a bipartite Graph \n"; 
    cout<<endl;
    cout<<"Using DFS"<<endl;

    Sol2 ob;
	bool answer = ob.isBipartite_DFS(4, adj);    
	if(ans)cout << "It is a bipartite Graph\n";
	else cout << "It is not a bipartite Graph\n";  
	
	
    
    return 0;
}