#include<iostream>
/* Quick sort work in the idea that elements are sorted if other elements before it is less and after it is greater
// let first element be pivot , i will be looking for element greater than pivot and j(at the end of the list) for less than or equal to pivot
// works on divide and conqour 
// swapping takes place of element greater than pivot(i) with element less than pivot(j)
// at the end where j is pointing it is the place of the pivot element
// once pivot is sorted sort other halves by recursion

time complexity of O(nlog n).
space complexity of O(log n)

However, in the worst case, when the input array is already sorted or nearly sorted, the partition step can take O(n^2) time. 
This happens when the pivot element is chosen as the smallest or largest element in the array
the algorithm has to make n comparisons at each level of the tree. 
Therefore, the worst-case time complexity of Quick Sort is O(n^2)
*/
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i=l,j=h;

    do{
        do{(i++);}while(A[i]<=pivot);
        do{(j--);}while(A[j]>pivot);

        if(i<j)swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[],int l, int h){
    int j;
    if(l<h){
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main(){
    cout<<"Unsorted Array: "<<endl;
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2,INT32_MAX};
    int n = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    cout<<endl;
    cout<<"After Quick Sort"<<endl;
    QuickSort(A,0,n-1);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }    
    return 0;
}