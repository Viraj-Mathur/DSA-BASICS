
/*
Find Missing And Repeating : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr, int n) {
        vector<int> result;

        // cyclic sort
        int i = 0;
        while (i < n) {
            if (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            } else {
                i++;
            }
        }

        // Find the repeating and missing numbers
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                result.push_back(arr[i]);  // Repeating number
                result.push_back(i + 1);   // Missing number
                break;
            }
        }

        return result;
    }
};
int main(){
    
    return 0;
}