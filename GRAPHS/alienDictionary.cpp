
// Problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// NOTE -> USE TOPOLOGY SORT

// https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/

#include <bits/stdc++.h>

using namespace std;

class Solution{
    private:
    // function for topological sorting

    vector<int> topoSort(int V, vector<int> adj[]){
        int indegree[V] = {0}; // In-degree of a vertex is the number of incoming edges to that vertex.
        
        // calculating the in-degrees of all vertices.

        for(int i=0; i<V ;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        // A queue q is initialized to store the vertices with an in-degree of 0. 
        // In topological sorting, the vertices with no incoming edges are the starting points of the sort.

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // topo is a vector to store topological ordering
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // node is in your topo sort
			// so please remove it from the indegree

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }

    public:

    string findOrder(string dict[], int N, int K) {
        
        vector<int>adj[K];
        for(int i =0; i<N-1; i++){
            // n-1 coz if we use till n then no one to compare at the end
            string s1 = dict[i]; //string 1
            string s2 = dict[i+1]; //string 2

            int len = min(s1.size(), s2.size()); //comparing the minimum elements
            for(int ptr = 0; ptr <len; ptr++){
                if(s1[ptr]!= s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // -a so that we get a numerical digit
                    break;
                }
            }

        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto it: topo){
            ans = ans + char(it + 'a');
        }
        return ans;


    }
};




int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

    cout<<"The order of characters in the alien language are: ";
	for (auto ch : ans)
		cout<< ch << ' ';
        cout << endl;
    
    return 0;
}