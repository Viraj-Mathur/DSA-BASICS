#include<iostream>
// IN INSERTION SORT WE COMPARE NOT SWAP
// INSERTION IS BETTER USED FOR LINKED LIST
// Time Complexity: O(N^2) 
// Auxiliary Space: O(1)

using namespace std;

void InsertionSort(int A[], int n){  //This for loop is responsible for selecting an element and comparing it with the previous elements to insert it in its correct position.
    for(int i=1;i<n;i++){   //i is the pointer pointing to last element and j points to second last
        int j = i-1;
        int x = A[i];   //Element to be inserted and compared for sorting
        while(j>-1 && A[j]>x){  //will compare till it find element smaller than x and insert it, -1 so that it doesnt go beyond the array
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
/*
The while loop is responsible for shifting all the elements greater than x one position to the right 
to make space for the current element. 
The loop iterates as long as j is greater than or equal to 0 and the element at A[j] is greater than x.
*/

int main(){
    cout<<"Unsorted Array: "<<endl;
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    cout<<endl;
    cout<<"After Insertion Sort"<<endl;
    InsertionSort(A, n);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    
    return 0;
}