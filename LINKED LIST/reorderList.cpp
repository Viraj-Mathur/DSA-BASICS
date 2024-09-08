/*
143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

*/

#include <bits/stdc++.h>

using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
Approach:
This problem can be broken down into three simple sub problems and can be solve sequentially to arrive at our final solution.

Finding the mid: take slow and fast ptr and find the start of the second half of Linked List
Reverse Linked List: reverse the second half and split the original Linked list into two independent linked list
Merge Linked List: take each node one by one from both the sublists and merge them into single linked list.
*/

class Solution {
private:
    // Function to reverse the linked list
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)  // Base case: if the list is empty or has one node, return the head
            return head;

        ListNode *temp = head;   // Temporary pointer for traversal
        ListNode *prev = nullptr;  // Pointer to store the previous node (initially null)
        ListNode *curr = head;    // Pointer to the current node (initially head)

        // Iterate over the list to reverse the pointers
        while(temp != nullptr) {
            temp = curr->next;  // Move temp to the next node
            curr->next = prev;  // Reverse the current node's next pointer to point to the previous node
            prev = curr;        // Move prev to the current node (step forward in reversed list)
            curr = temp;        // Move curr to the next node (step forward in original list)
        }
        
        head = prev;  // After the loop, prev will point to the new head of the reversed list
        return head;  // Return the new head of the reversed list
    }

public:
    // Function to reorder the linked list as per the problem requirements
    void reorderList(ListNode* head) {
        // Edge case: if the list is empty or has only one node, no need to reorder
        if (head == nullptr || head->next == nullptr)
            return;

        // Use the slow and fast pointer approach to find the middle of the list
        ListNode* slow = head, *fast = head, *first_half = head;
        fast = fast->next;  // Move fast one step ahead initially to prevent fast from being at the same pace as slow

        // Move slow pointer one step at a time and fast pointer two steps at a time until fast reaches the end
        while(fast && fast->next) {
            slow = slow->next;         // Slow moves one step
            fast = fast->next->next;   // Fast moves two steps
        }

        // Now, slow is at the middle of the list. Split the list into two halves
        ListNode* second_half = reverse(slow->next);  // Reverse the second half of the list starting from slow->next
        slow->next = NULL;  // Break the connection between the first and second halves

        // Merge the two halves: the first half starts from head, the second half from the reversed part
        while(second_half) {
            // Store the next nodes of both halves temporarily
            ListNode* temp1 = first_half->next,  *temp2 = second_half->next;
            
            // Rearrange pointers to alternate between nodes of first half and second half
            first_half->next = second_half;   // Link the current first_half node to the second_half node
            second_half->next = temp1;        // Link the second_half node to the next first_half node

            // Move the pointers forward for both halves
            first_half = temp1;        // Move first_half to the next node in the first half
            second_half = temp2;       // Move second_half to the next node in the second half
        }
    }
};


int main(){
    
    return 0;
}