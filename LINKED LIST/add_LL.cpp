/*
445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes 
first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
 
Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/

#include <bits/stdc++.h>

using namespace std;




struct ListNode {

    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// reverse the LLs and then add
class Solution {
    private:
    // function to reverese the LL
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp;

        while(head){
            temp = head->next;
            // reverse
            head->next = prev;
            // update prev and curr
            prev = head;
            head = temp;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse the list first
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);

        int totalSum = 0;
        int carry = 0;
        ListNode* ans = new ListNode(); //new list for sum result

        while(r1||r2){
            if(r1){
                totalSum += r1->val;
                r1 = r1->next;
            }
            if(r2){
                totalSum += r2->val;
                r2 = r2->next;
            }

            ans->val = totalSum%10;
            carry = totalSum/10;
            ListNode* head = new ListNode(carry);
            head->next = ans;
            ans = head;
            totalSum = carry;

        }
        if(carry ==0){
            return ans->next;
        }
        else{
            return ans;
        }
    }
};


// Q2 : if reversing is not allowed
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if reversing is not the option use stack
        stack<int>s1,s2;
        
        while(l1!=NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }



        int totalSum = 0;
        int carry = 0;
        ListNode* ans = new ListNode(); //new list for sum result

        while (!s1.empty() || !s2.empty()) {
            if(!s1.empty()){
                totalSum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                totalSum += s2.top();
                s2.pop();
            }

            ans->val = totalSum%10;
            carry = totalSum/10;
            ListNode* head = new ListNode(carry);
            head->next = ans;
            ans = head;
            totalSum = carry;

        }
        if(carry ==0){
            return ans->next;
        }
        else{
            return ans;
        }
    }
};

int main(){
    
    return 0;
}