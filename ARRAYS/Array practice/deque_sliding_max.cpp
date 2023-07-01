/*Given array A[] with sliding window of size w which is moving from the very left of the array to the very right.
Assume that we can only see the w numbers in the window. Each time the sliding window moves rightwards by one 
position. For example: The array is [1 3 -1 -3 5 3 6 7], and w is 3.
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// using deque 
void printMax(int arr[],int n, int w){
    deque<int>d(w); //creating a queue
    int i;
    
    for(i=0;i<w;++i){
        while((!d.empty() && arr[i]>=arr[d.back()])){
            d.pop_back(); //removing the smaller elements
        }
        d.push_back(i);
    }

    // for rest of the elements
    for(; i<n;++i){
        // printing the largest element front of the queue
        cout<< arr[d.front()]<<endl;
        // removing elements out of the sliding window
        while((!d.empty()) && d.front()<=i-w){
            d.pop_front();
        }
        // removing smaller elements
        while((!d.empty()) && arr[i]>= arr[d.back()]){
            d.pop_back();
        }
        // add current element at the rear
        d.push_back(i);
    }
    // printing the maximum element
    cout<<arr[d.front()]<<endl;
}

int main(){
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int W = 3;
  
    printMax(arr, N, W);
    return 0;
}
