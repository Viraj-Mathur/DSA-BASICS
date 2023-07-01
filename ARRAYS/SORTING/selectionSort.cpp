#include<iostream>
// FIRST SELECT THE ELEMENT BY COMPARING THEN SORT IT
// FINDING A POSITION THEN SELECTING AN ELEMENT FOR THAT POSITION
// only algo that sorts in minimum number of swaps i.e (n-1) O(n)
// k passes will give k smallest element

/*
LOGIC:
he algorithm repeatedly selects the smallest (or largest) element from the unsorted list
swaps it with the first element of the unsorted portion.
 This process is repeated for the remaining unsorted portion of the list until the entire list is sorted. 
*/
using namespace std;
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        k=i; // TAKE THE FIRST ELEMENT TO BE SWAPPED WITH AS K
        for(j=i+1;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i], &A[k]);
    }

}


int main(){
    cout<<"Unsorted Array: "<<endl;
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    cout<<endl;
    cout<<"After Selectoin Sort"<<endl;
    SelectionSort(A, n);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    return 0;
}