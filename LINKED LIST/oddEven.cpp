//  Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* last = head->next;

        while(odd->next && even->next){
            odd->next = even->next; // odd will go to the place next of even
            odd = odd->next; // next odd traversal
            even->next = odd->next; // even will go to the place next of odd
            even = even->next; //next even traversal
        }

        odd->next = last;
        return head;
        
    }
};

int main(){
    
    return 0;
}