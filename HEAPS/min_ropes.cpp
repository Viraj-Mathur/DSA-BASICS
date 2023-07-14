/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. 
Given N size array arr[] contains the lengths of the ropes. 

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array {4, 5, 6}. Cost of this operation 2+3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array {9, 6}. Cost of this operation 4+5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9+6 =15
Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
*/

/*
APPROACH: MAKE A MIN HEAP - IT WILL GIVE TWO MINIMUM ELEMENTS OF THE ARRAY TO BE MERGED IN COMPLEXITY: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // creating a min heap
        priority_queue<long long , vector<long long>, greater<long long> > pq;
        
        // adding the elements in the priority queue
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a+b;
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }
};

// T.C: O(n log n) S.C: O(N)

int main(){
    
    return 0;
}