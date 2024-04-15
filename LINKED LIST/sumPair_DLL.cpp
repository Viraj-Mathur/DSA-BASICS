// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

/*

Approach -1  Use nested traversal - TC: O(n^2)
take one node and keep summing up with the other node if matched keep the pair 
and traverse untill the sum does not exceeds 
after one traversal go to second node and keep summing it with other node

Approach -2 : 2 pointer approach - TC: O(2N)
Take left pointer in head and right pointer in tail as it is sorted list if we sum right and left 
while incrementing left the number will decrease therefore do not change left and decrement rigth and 
sum them until the pair is matched after matching increment left, traversal till left and rigth crosses each other

*/


#include <bits/stdc++.h>

using namespace std;

// Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution
{
    private:
    Node* findTail(Node* head){ // function to find tail of DLL
        Node* tail = head;
        while(tail->next !=NULL) tail = tail->next;
        return tail;
    }
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>> ans;
        if(head == NULL) return ans;
        Node* left = head; // left pointing at head
        Node* right = findTail(head); // right pointing at tail
        
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data, right->data});
                left = left->next; //incrementing left
                right =right->prev; //decrementing right
            }
            else if(left->data +right->data<target){
                left = left->next;
            }
            else right = right->prev;
        }
        return ans;
    }
};

// APPROACH 2 - USING HASHING

class Solution2 {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
        Node* temp = head;
        vector<pair<int, int>> ans;
        unordered_map<int, int> mpp; // Map to store visited node values

        // Traverse the linked list
        while (temp != nullptr) {
            // Insert current node's data into the map
            mpp[temp->data] = 0;

            // Calculate complement needed to make sum equal to target
            int complement = target - temp->data;

            // Check if the complement exists in the map and is not the same as current node's data
            if (mpp.find(complement) != mpp.end() && complement != temp->data) {
                // Create a pair of values that sum up to target
                pair<int, int> myPair;
                
                // Determine the correct order for the pair and add to result
                if (temp->data < complement) {
                    myPair = make_pair(temp->data, complement);
                } else {
                    myPair = make_pair(complement, temp->data);
                }

                // Add the pair to the result vector
                ans.push_back(myPair);
            }

            // Move to the next node
            temp = temp->next;
        }

        // Sort the result vector to ensure pairs are in ascending order
        sort(ans.begin(), ans.end());

        return ans;
    }
};


int main(){
    
    return 0;
}