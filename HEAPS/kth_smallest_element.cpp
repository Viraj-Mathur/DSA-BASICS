
/*
Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.


*/

// Approach 1 : use sorting to find kth element but complexity O(n log n)
// Approach 2 : use min heap but as we need smallest it is not required as space complexity will be O(n)
// Approach 3 : use min heap - tc O(n) and SC : O(k)

#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // Step1: make the "MAX HEAP" for k elements
        priority_queue<int> pq;


        // insert initial k elements
        for(int i =0; i<k; i++){
            pq.push(arr[i]);    
        }
        // for remaining elements push only if they are less than top 
        // step 2:for (k-1)th element first delete the root node and push the element
        for(int i = k; i<=r; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        // answer is the top of the priority queue
        int ans = pq.top();
        return ans;
    }
};

// TO FIND Kth largest element: USE MIN HEAP

int main(){
    
    return 0;
}