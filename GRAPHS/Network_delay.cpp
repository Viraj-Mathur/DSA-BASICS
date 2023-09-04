/*
PROBLEM STATEMENT: 
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges 
times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal 
to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct node{
        int dist;
        int wt;
    };
    struct qnode{
        int vertex;
        int dist;
    };

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // making the adjacency list
        unordered_map<int, vector<node *>> adj;
        for(int i=0;i<times.size();i++){
            node *newNode = new node;
            newNode-> dist  = times[i][1];
            newNode-> wt = times[i][2];
            adj[times[i][0]].push_back(newNode);
        }
// making a queue
        qnode *qn = new qnode;
        qn->vertex = k; //initialise the vertex as k
        qn-> dist = 0; // and distance as 0
        queue<qnode *> q;
        q.push(qn); //push the source node in the queue

        vector<int> distance(n+1, INT_MAX); //initialising as infinity
        distance[k] = 0;
        int time = 0;

        // Applying BFS traversal

        while(!q.empty()){
            qnode *curr = q.front();
            q.pop();

            for(auto it:adj[curr->vertex]){
                qnode *temp_qn = new qnode;
                temp_qn-> vertex = it->dist;
                temp_qn-> dist = it->wt + curr->dist;

        //continious updating the value so that we get the nearest value(min value)
                if(distance[temp_qn->vertex] > temp_qn->dist){
                    q.push(temp_qn);
                    distance[temp_qn->vertex] = it->wt + curr->dist;
                } 
            } 
        }

// find the maximum distance node (if all the nodes are traversed)
        for(int i=1;i<=n;i++){
            if(distance[i] == INT_MAX) return -1;
            time = max(time,distance[i]);
        }

        return time;


        
    }
};

int main(){
    
    return 0;
}