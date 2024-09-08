/*
82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]


*/

#include <bits/stdc++.h>

using namespace std;


//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Step 1: Count the frequency of each node value
        unordered_map<int, int> freq;
        ListNode* curr = head;
        while (curr != NULL) {
            freq[curr->val]++;
            curr = curr->next;
        }

        // Step 2: Create a dummy node to simplify head removal cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        curr = head;

        // Step 3: Traverse the list again and remove nodes with duplicate values
        while (curr != NULL) {
            if (freq[curr->val] > 1) {
                // If the current node's value appears more than once, remove it
                prev->next = curr->next;
            } else {
                // Otherwise, move prev forward
                prev = curr;
            }
            curr = curr->next; //traversing next node
        }

        // Step 4: Return the modified list, skipping the dummy node
        ListNode* newHead = dummy->next;
        delete dummy;  // Free the dummy node
        return newHead;
    }
};


// similar questions:

/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* curr = head;
        while(curr->next!=NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};



int main(){
    
    return 0;
}