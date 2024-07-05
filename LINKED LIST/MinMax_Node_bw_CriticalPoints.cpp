/*
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] 
where minDistance is the minimum distance between any two distinct critical points and 
maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105


*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Initialize the result vector with maximum integer value for min distance and minimum integer value for max distance
        vector<int> ans = {INT_MAX, INT_MIN};
        
        // Initialize current pointer to the head of the list
        ListNode* curr = head;
        
        // Initialize variables to track previous critical node, first critical node, previous node value, and current index
        int prevCriticalNode = -1, firstCriticalNode = -1, prevNode = curr->val, index = 0;
        
        // Move to the next node
        curr = curr->next;

        // Traverse the list until the second last node
        while (curr->next != nullptr) {
            index++;
            int currNode = curr->val, nextNode = curr->next->val;

            // Check if the current node is a critical point
            if ((prevNode < currNode && currNode > nextNode) || (prevNode > currNode && currNode < nextNode)) {
                // If this is the first critical node, initialize first and previous critical node indices
                if (firstCriticalNode == -1) {
                    firstCriticalNode = index;
                    prevCriticalNode = index;
                } else {
                    // Update the minimum distance between critical points
                    ans[0] = min(ans[0], index - prevCriticalNode);
                    // Update the maximum distance between the first and current critical points
                    ans[1] = max(ans[1], index - firstCriticalNode);
                    // Update the previous critical node index to the current index
                    prevCriticalNode = index;
                }
            }
            // Update the previous node value and move to the next node
            prevNode = currNode;
            curr = curr->next;
        }

        // If no critical points are found, return {-1, -1}
        if (ans[0] == INT_MAX) {
            return {-1, -1};
        }
        
        // Return the result vector containing the minimum and maximum distances
        return ans;
    }
};



int main() {
    // Create a test linked list: 1 -> 3 -> 2 -> 2 -> 3 -> 2 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(2);

    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << ", Maximum distance: " << result[1] << endl;

    // Clean up the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}