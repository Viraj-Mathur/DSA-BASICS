
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
        
        for(int i =0; i<k; i++){
            pq.push(arr[i]);    
        }
        
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