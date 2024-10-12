#include<iostream>

// Merging two lists in one, i points to one(m size) j points to other(n size) and k points to the merged list 
using namespace std;

void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while(i<=mid && j<= high){
        if (A[i]<A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i<=mid){
        B[k++] = A[i++];
    }
    while(j<= high){
        B[k++] = A[j++];
    }
    for(int i=low;i<=high;i++){
        A[i] = B[i];
    }
}

void RecursiveMergeSort(int A[], int low,int high){
    if(low<high){
        int mid = low+(high-low)/2; //for calculating mid point

         // Sort sub-lists
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid+1, high);
 
        // Merge sorted sub-lists
        Merge(A, low, mid, high);

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
    cout<<"After Merge Sort"<<endl;
    RecursiveMergeSort(A, 0,n-1);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }    
    
    return 0;
}


/*

Complexity Analysis of Merge Sort:
Time Complexity:
Best Case: O(n log n), When the array is already sorted or nearly sorted.
Average Case: O(n log n), When the array is randomly ordered.
Worst Case: O(n log n), When the array is sorted in reverse order.
Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.


Not in-place and slower than quick sort
*/