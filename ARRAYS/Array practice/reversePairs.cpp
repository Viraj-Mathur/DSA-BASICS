/*
493. Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 10^4
-231 <= nums[i] <= 231 - 1

*/

#include <bits/stdc++.h>

using namespace std;

// brute force n^2 approach
int reversePairs1(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

// using merge sort approach - Time Complexity: O(2N*logN)

/*
a bit same logic as count inversion question but it won't work because  nums[i] > 2 * nums[j].
*/


void Merge(vector<int>& A, int low, int mid, int high) {
        vector<int> temp;
        int left = low;     // starting index of the left half
        int right = mid + 1; // starting index of the right half

        // Merge the two halves while comparing the elements
        while (left <= mid && right <= high) {
            if (A[left] <= A[right]) {
                temp.push_back(A[left]);
                left++;
            } else {
                temp.push_back(A[right]);
                right++;
            }
        }

        // Copy remaining elements from the left half
        while (left <= mid) {
            temp.push_back(A[left]);
            left++;
        }

        // Copy remaining elements from the right half
        while (right <= high) {
            temp.push_back(A[right]);
            right++;
        }

        // Copy back the merged array to the original array
        for (int i = low; i <= high; i++) {
            A[i] = temp[i - low];
        }
    }

    // Function to count the reverse pairs
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;

        // Count reverse pairs using the condition nums[i] > 2 * nums[right]
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    // Recursive Merge Sort function that sorts and counts reverse pairs
    int RecursiveMergeSort(vector<int>& A, int low, int high) {
        int count = 0;
        if (low >= high) return count;  // base case

        int mid = low + (high - low) / 2;

        // Sort left and right halves and count reverse pairs
        count += RecursiveMergeSort(A, low, mid);   // left half
        count += RecursiveMergeSort(A, mid + 1, high); // right half

        // Count reverse pairs across the two halves
        count += countPairs(A, low, mid, high);

        // Merge the sorted halves
        Merge(A, low, mid, high);

        return count;
    }


int RecursiveMergeSort(vector<int>&A, int low, int high){
    int count = 0;
    if(low >= high) return count;  // base case
    
    int mid = low + (high - low) / 2; // for calculating mid point

    // Sort sub-lists
    count += RecursiveMergeSort(A, low, mid);   // left half
    count += RecursiveMergeSort(A, mid+1, high); // right half
    
    count+= countPairs(A, low,mid,high);
    // Merge sorted sub-lists
    Merge(A, low, mid, high); // merging sorted halves
    return count;
}

int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return RecursiveMergeSort(nums, 0, n - 1);
}



int main(){
    
    vector<int> a = {40,25,19,12,9,6,2};
    int n = 7;
    int cnt = reversePairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}