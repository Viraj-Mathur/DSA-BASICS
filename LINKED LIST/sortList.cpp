// Given the head of a linked list, return the list after sorting it in ascending order.

#include <bits/stdc++.h>

using namespace std;

// Approach 1: convert the linked list into an array or vector, sort it using the built-in sort function, and then create a new linked list using the sorted values.
// Time Complexity: O(nlogn)

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* p1 = head;
        vector<int> arr;
        // Convert LL to array
        while(p1){
            arr.push_back(p1->val);
            p1 = p1->next;
        }
        //  sorting the array
        sort(arr.begin(), arr.end());

        // creating new LL using sorted array

        ListNode* n = new ListNode(arr[0]);
        head = n;

        ListNode* temp = head;
        for(int i=1;i<arr.size();i++){
            ListNode* n1 = new ListNode(arr[i]);
            temp->next = n1;
            temp = temp->next;
        }
        return head;
        
    }
};


// Approach 2: Using Merge Sort
// Time Complexity: O(nlogn) Space Complexity: O(1)





int main(){
    
    return 0;
}