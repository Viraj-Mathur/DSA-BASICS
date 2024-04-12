//  Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of the list, which contains the least significant digit.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); // Dummy head to simplify insertion
        ListNode *temp = dummy; // Pointer to the current position in the result list

        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10); // Create a new node with the sum mod 10
            temp->next = node; // Append the new node to the result list
            temp = temp->next; // Move the temp pointer to the new node
        } 

        ListNode *result = dummy->next; // Store the result (skip the dummy head)
        delete dummy; // Free the memory allocated for the dummy node
        return result; // Return the result list
    }
};


int main(){
    
    return 0;
}