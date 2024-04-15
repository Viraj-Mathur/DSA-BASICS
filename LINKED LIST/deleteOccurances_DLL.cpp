// You are given the head of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key and return the new DLL.
/*
Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.
*/

#include <bits/stdc++.h>

using namespace std;

// a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref; //initialising temp at the head
        while(temp!=NULL){
            if(temp->data ==x){
                // if it is head then after deletion head will be deleted
                if(temp==*head_ref){
                    *head_ref = temp->next; //make the next one head
                }
                
                Node* nextNode = temp->next; // initialsing nextNode
                Node* prevNode = temp->prev; // initialsing prevNode
                
                if(nextNode !=NULL) nextNode->prev = prevNode;
                if(prevNode !=NULL) prevNode->next = nextNode;
                
                free(temp); //deleting the node
                temp = nextNode; //increment temp
            }
            
            else{
                temp = temp->next;
            }
        }
        // return head_ref;
    }
};


int main(){
    
    
    return 0;
}