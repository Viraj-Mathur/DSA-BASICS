/*
Problem Statement

You are standing in queue to buy the latest Batman movie ticket. You noticed the queue looked like a singly LinkedList. 
Each person has some amount of money with them, you are bored, and you want to find the amount of money 
the person is standing at the Kth' of the queue from the back.

Example:
N = 4, K = 2

NODE = 1 -> 2 -> 3 -> 4 
In the following example, the 2nd person from the back has '3' units of money.
*/

#include <bits/stdc++.h>

using namespace std;

// Following is the linkedList class structure:

   class List {
    public:
        int data;
        List *next;
        List() {};
        List(int v){
            data = v;
            next = NULL;
        };
   };

int kthMoney(List *head , int k) {

   // Write your code here.
   List *temp = head;
   int length = 0;
   // getting the length of the linked list
   while(temp!=NULL){
      length++;
      temp = temp->next;

   }

   for(int i=0;i<length-k;i++){
      head = head->next;

   }
   return head->data;
}

int main(){
    
    return 0;
}

