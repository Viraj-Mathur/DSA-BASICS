// In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).
// with V vertices and E edges,
// Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 



#include <bits/stdc++.h>

using namespace std;

class Solution
{
    private:
    void dfs(int node, int vis[] ,stack<int> &st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it,vis,st,adj);
        }
        st.push(node);
    }

	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
        stack<int> st; 
        // storing the returned dfs function in stack after emptying it will return topological sort
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}
};

int main(){

    //V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);
    cout<<"The topoligical Sort Elements are : ";
	for (auto node : ans) {
		cout<< node << " ";
	}
	cout << endl;
    
    return 0;
}

/*
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. 
So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) 
for recursive stack space, where N = no. of nodes.
*/