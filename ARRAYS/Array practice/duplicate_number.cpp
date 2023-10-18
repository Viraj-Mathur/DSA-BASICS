// 287. Find the Duplicate Number:
/*
Input: nums = [1,3,4,2,2]
Output: 2
*/

/*
APPROACH:
Floyd's Tortoise and Hare
THIS ALSO efficiently finds the duplicate element in an array with a time complexity of O(n) and a space complexity of O(1).

Here's a step-by-step explanation of the approach implemented in the code:

    Initialize two integer variables, slow and fast, to 0. These two pointers will be used to traverse the vector nums.

    Use a do-while loop to perform the following steps until slow and fast pointers meet:

    Update the slow pointer by moving it to the element at the index nums[slow] in the nums vector.

    Update the fast pointer by moving it to the element at the index nums[nums[fast]] in the nums vector. 
    The fast pointer moves twice as fast as the slow pointer.

    This loop continues until the slow and fast pointers meet at the same element within the array. 
    This meeting point is within the cycle of duplicates in the array.

    After the slow and fast pointers have met, reset the slow pointer to the beginning (0 index) of the array while keeping the fast pointer at the meeting point.

    Use a while loop to traverse the array again with both slow and fast pointers. Increment both pointers one step at a time in each iteration.

    The while loop continues until slow and fast meet again. The point where they meet is the duplicate element in the nums vector.

    Return the value pointed to by slow as the duplicate element.

The idea behind this algorithm is to detect a cycle in the array. The slow and fast pointers move within the array, and since there is a duplicate element, 
they will eventually meet at some point within the cycle. The second traversal ensures that the duplicate element is found.

    Time complexity:0(N)

    Space complexity:0(1)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        slow = 0;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;        
    }
};

int main(){
    
    return 0;
}