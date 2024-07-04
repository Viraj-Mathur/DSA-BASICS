/*

2181. Merge Nodes in Between Zeros

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

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
    ListNode* mergeNodes(ListNode* head) {
        // Create a dummy node to simplify the new list creation
        ListNode* dummyNode = new ListNode(0);
        ListNode* newCurr = dummyNode; // Pointer to build the new list
        ListNode* curr = head; // Pointer to traverse the original list

        while(true) {
            int sum = 0; // Initialize sum for the current segment
            
            // Traverse until we find the next 0 or reach the end
            while(curr->next != nullptr && curr->next->val != 0) {
                curr = curr->next;
                sum += curr->val; // Accumulate the sum
            }
            
            // Create a new node with the calculated sum
            newCurr->next = new ListNode(sum);
            newCurr = newCurr->next; // Move the pointer in the new list
            
            curr = curr->next; // Move to the next 0 in the original list
            
            // Break if we've reached the end of the original list
            if(curr->next == nullptr) {
                break;
            }
        }

        // Get the head of the new list (skip the dummy node)
        ListNode* newHead = dummyNode->next;
        delete(dummyNode); // Free the dummy node to reduce memory usage
        
        return newHead; // Return the new merged list
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int i = 0; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    // Example input: [0,3,1,0,4,5,2,0]
    int arr[] = {0,3,1,0,4,5,2,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* mergedHead = solution.mergeNodes(head);

    std::cout << "Merged list: ";
    printList(mergedHead);

    // Clean up memory (not shown: proper deletion of all nodes)

    return 0;
}