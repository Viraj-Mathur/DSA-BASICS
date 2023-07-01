/*
Delete middle element from stack
*/


// solving using recursion


#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>&inputStack,int count, int size){
   // base case: middle element pop
   if(count == size/2){
      inputStack.pop();
      return;
   }

   // upper half elements are removed until middle one popped then they are pushed again

   int num = inputStack.top();
   inputStack.pop();

   // RECURSIVE CALL TO REMOVE MIDDLE
   solve(inputStack,count+1,size);
   inputStack.push(num); //upper half pushed again 
} 

void deleteMiddle(stack<int>&inputStack, int N){
   
   int count = 0;
   solve(inputStack,count,N);

}