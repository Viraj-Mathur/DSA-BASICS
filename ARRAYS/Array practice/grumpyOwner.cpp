/*
1052. Grumpy Bookstore Owner

There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
Example 2:

Input: customers = [1], grumpy = [0], minutes = 1
Output: 1
 

Constraints:

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 104
0 <= customers[i] <= 1000
grumpy[i] is either 0 or 1.

*/

// solved using sliding window approach taking window as 3 minute index
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int notGrumpySum = 0;  // Sum of satisfied customers when owner is not grumpy
        int windowSum = 0;     // Sum of additional satisfied customers in current window
        int maxWindowSum = 0;  // Maximum sum of additional satisfied customers in any window
        
        // First pass: Calculate the sum of satisfied customers when the owner is not grumpy
        // and initialize the first window
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                notGrumpySum += customers[i];
            }
            if (i < minutes && grumpy[i] == 1) {
                windowSum += customers[i];
            }
        }
        
        maxWindowSum = windowSum;
        
        // Sliding window technique
        // Window size is 'minutes', and we slide it through the entire array
        for (int i = minutes; i < n; i++) {
            // Remove the contribution of the customer leaving the window
            if (grumpy[i - minutes] == 1) {
                windowSum -= customers[i - minutes];
            }
            
            // Add the contribution of the new customer entering the window
            if (grumpy[i] == 1) {
                windowSum += customers[i];
            }
            
            // Update the maximum window sum if current window sum is greater
            maxWindowSum = max(maxWindowSum, windowSum);
        }
        
        // The total satisfied customers is the sum of:
        // 1. Customers satisfied when the owner is not grumpy (notGrumpySum)
        // 2. Additional customers satisfied during the 'minutes' when the secret technique is used (maxWindowSum)
        return notGrumpySum + maxWindowSum;
    }
};

int main(){
    
    return 0;
}