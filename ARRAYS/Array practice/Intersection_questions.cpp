#include <bits/stdc++.h>

using namespace std;



/*
Q1:349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their 
intersection. Each element in the result must be unique and you may return the result in any order.

 Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 */  

// solving using hashsets

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());

        unordered_set<int> common;

        for(auto i:nums2){
            if(set1.contains(i)){
                common.insert(i);
            }
        }

        vector<int> ans(common.begin(), common.end());
        return ans;
    }
};


/*
Q2: 2540. Minimum Common Value
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
*/

// As the arrays are sorted we can apply 2 pointers here
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;

        while(i<nums1.size() && j< nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                return nums1[i]; //If the elements pointed to by i and j are equal, a common element has been found,
            }
        }

        return -1;
        
    }
};
// Approach 2: using sets

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // // Create an unordered_set to store unique elements from nums1
        unordered_set<int> s;

        //  // Iterate through nums1 and insert each element into the unordered_set
        for(int i:nums1){
            s.insert(i);
        }

// // Iterate through nums2
        for(int i=0;i<nums2.size();i++){
            //  // If the current element is in the unordered_set (i.e., it's a common element)
            if(s.count(nums2[i])){
                // // Return the common element
                return nums2[i];
            }
        }
        //         // If no common element is found, return -1

        return -1;
    }
};

/*
Q3: 350. Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Approach - 2 pointers: we sort both lists and put a pointer at the beginning of each. Now we will go through these arrays until one of them ends (this ensures that we have collected all the necessary elements) with the following condition:
If the elements are equal, then wonderful, we have found a pair. Let's add this element to the result and increase the pointers in both lists (we took an element from each)
If an element from some list is smaller, then we need to increase the pointer of this list, since we know that by sorting lists, larger elements are on the right (when sorting in the other direction, we did the opposite)



*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        vector<int> result;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } 
            
            else if (nums1[i] > nums2[j]) {
                j++;
            } 
            
            else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
    }
};
int main(){
    
    return 0;
}