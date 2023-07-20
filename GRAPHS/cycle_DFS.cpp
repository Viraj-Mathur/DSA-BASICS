
#include <bits/stdc++.h>

using namespace std;

class Solution{
    private:
        bool dfs(int node, int parent, int vis[], vector<int>adj[]){
            vis[node] = 1;
            // visit adjencent node
            for(auto adjecentNode: adj[node]){
                // for unvisited adjencent node
                if(!vis[adjecentNode]){
                    if(dfs(adjecentNode,node, vis, adj) == true)
                        return true;
                }
                // visited but not a parent node
                else if(adjecentNode!= parent){
                    return false;
                }
            }
        }

    public:
    
        bool isCycle(int V, vector<int>adj[]){
            int vis[V] = {0}; // 0 based indexing
            
            // for connected nodes otherwise simple dfs call would have been suffice
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(dfs(i, -1, vis, adj) == true) return true; 
                }
            }
            return false;
        }
};

int main(){
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}