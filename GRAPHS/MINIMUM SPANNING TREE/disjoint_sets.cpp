// https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46

#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
        // creating a constructor
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i] = 1;
                size[i] = 1;
            }
        }

        // for finding ultimate parent for compression
        int findUltParent(int node){
            if(node == parent[node])
                return node;
            return parent[node] = findUltParent(parent[node]);
        }


        // Union by Rank
        void unionByRank(int u, int v){
            int ulp_u = findUltParent(u); // ultimate parent of u
            int ulp_v = findUltParent(v); // ultimate parent of v
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        // Union by Size
        void unionBySize(int u, int v) {
        int ulp_u = findUltParent(u); 
        int ulp_v = findUltParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

int main(){
    

    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUltParent(3) == ds.findUltParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBySize(3, 7); 

    if(ds.findUltParent(3) == ds.findUltParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	
    return 0;
}