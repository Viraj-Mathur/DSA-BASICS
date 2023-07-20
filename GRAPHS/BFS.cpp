/* for zero based indexing

    In BFS, we start with a “starting” node, mark it as visited, and push it into the queue data structure.

    In every iteration, we pop out the node ‘v’ and put it in the solution vector, as we are traversing this node.

    All the unvisited adjacent nodes from ‘v’ are visited next and are pushed into the queue. 
    The list of adjacent neighbors of the node can be accessed from the adjacency list.
    
    Repeat steps 2 and 3 until the queue becomes empty, and this way you can easily traverse all the nodes in the graph.


    Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
    Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:

    vector<int> bfsOfGraph(int V, vector<int> adj[]) { // v= total nodes
        int vis[V] = {0}; // initialising visited nodes list
        vis[0] = 1;
        queue<int> q; // creating a queue for storing nodes
        q.push(0); // pushing the initial node
        vector<int> bfs;
        
        while(!q.empty()){
        // iterate till queue is empty
        int node = q.front(); // getting the topmost element
        q.pop();
        bfs.push_back(node);
        

        for(auto it: adj[node]) { // for traversing all its neighbouring nodes
            // if already visited store in queue and mark as visited
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }

        }
        }

        return bfs;
        

    }
};

// adding elements in the graph
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
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}