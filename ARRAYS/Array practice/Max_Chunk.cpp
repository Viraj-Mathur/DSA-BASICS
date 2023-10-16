/*
768. Max Chunks To Make Sorted II

You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

*/

// APPROACH: USE LEFT MAX AND RIGHT MIN APPROACH TO SOLVE THE QUESTION

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        // CREATING LEFT MAX ARRAY
        vector<int> left_max(n);
        left_max[0] = arr[0];
        for(int i=1;i<n;i++){
            if(left_max[i-1] > arr[i]){
                left_max[i] = left_max[i-1];
            }
            else{
                left_max[i] = arr[i];
            }
        }

        // CREATING RIGHT MIN ARRAY
        vector<int> right_min(n+1);
        right_min[n] = INT_MAX;
        right_min[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(right_min[i+1] < arr[i]){
                right_min[i] = right_min[i+1];
            }
            else{
                right_min[i] = arr[i];
            }
        }

        int chunk = 0;
        for(int i=0;i<n;i++){
            if(left_max[i] <= right_min[i+1]){
                chunk++;
            }
        }

        return chunk;
    }     
};

int main(){
    
    return 0;
}