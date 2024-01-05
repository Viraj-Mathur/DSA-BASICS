// to find duplicates in an array

#include <bits/stdc++.h>

using namespace std;

// APPROACH 1: SORTING

int findDuplicateSort(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}

// APPROACH 2: "Floyd's Tortoise and Hare" algorithm OR Linked List cycle method

int findDuplicate(vector<int>& nums) {
    // Initialize two pointers, slow and fast, both pointing to the first element of the array
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect the intersection point in the cycle
    do {
        // Move slow one step at a time
        slow = nums[slow];
        // Move fast two steps at a time
        fast = nums[nums[fast]];
    } while (slow != fast);

    // At this point, the slow and fast pointers have met, indicating the presence of a cycle

    // Reset the fast pointer to the start of the array
    fast = nums[0];

    // Phase 2: Find the entrance to the cycle (duplicate element)
    while (slow != fast) {
        // Move both pointers one step at a time
        slow = nums[slow];
        fast = nums[fast];
    }

    // At this point, the slow and fast pointers have met again, and they are at the entrance to the cycle

    // Return the duplicate element (entrance to the cycle)
    return slow;
}


int main(){

  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate number using sorting is : "<<findDuplicateSort(arr)<<endl;
  cout << "The duplicate element Using is Floyd's Tortoise and Hare algo is: " << findDuplicate(arr) << endl;
    
    return 0;
}