/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"

Example 3:

Input: n = 3, k = 1
Output: "123"

 
*/



//Approach 1: use recursion 
// Approach 2: 
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        vector<int> numbers(n);
        string result;
        
        // Calculate factorials and initialize numbers
        factorial[0] = 1;
        for(int i = 1; i < n; i++) {
            factorial[i] = factorial[i-1] * i;
            numbers[i-1] = i;
        }
        numbers[n-1] = n;
        
        k--; // Convert to 0-based index
        
        for(int i = n; i > 0; i--) {
            int index = k / factorial[i-1];
            k %= factorial[i-1];
            
            result += to_string(numbers[index]);
            
            // Shift the remaining numbers
            for(int j = index; j < i - 1; j++) {
                numbers[j] = numbers[j+1];
            }
        }
        
        return result;
    }
};

/*
Let's say n = 4, k = 15 (remember, we subtract 1 from k at the start, so we're actually looking for the 14th permutation).
First iteration (i = 4):

We have 3! = 6 permutations for each starting number.
14 / 6 = 2, so we select the 3rd number (index 2).
14 % 6 = 2, so for the next iteration, we're looking for the 2nd permutation of the remaining numbers.

This process continues, using / to select the correct number and % to update our position for the next step, allowing us to systematically construct the desired permutation.
*/


