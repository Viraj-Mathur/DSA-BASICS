/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
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


/*
Approach: 

    Insert all nodes into a min-heap.
    Extract the smallest node from the heap and add it to the result list.
    If the extracted node has a next node, insert the next node into the heap.
    Repeat steps 2 and 3 until the heap is empty.
*/
class Solution {
private:
    // comparison function for pq to create a min heap
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min-heap comparison
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // creating a min heap priority queue
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap; // this is done coz greater do not apply in the LL
        // step 1 : insert first node of each list into min heap
        for(ListNode* list : lists){
            if(list != NULL){
                minHeap.push(list);
            }
        }
        


        // extract the smallest node from the heap, add it to the result list, and move the tail pointer.      

        // creating tail
        ListNode temp;
        ListNode* tail = &temp;

        // Step 2 : extracting smallest node and adding it in result
        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            // Step 3: If the extracted node has a next node, we insert this next node into the heap.
            if(smallest->next !=NULL){
                minHeap.push(smallest->next);
            }
        }
        return temp.next;
    }
};

int main(){
    
    return 0;
}