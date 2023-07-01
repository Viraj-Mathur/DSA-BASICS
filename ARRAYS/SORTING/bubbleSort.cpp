#include<iostream>
// comparing two element and soring it
// k passes will give k largest element
// Time Complexity: O(N^2)
// Auxiliary Space: O(1) 

using namespace std;


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n){
    int flag = 0;  // TO check if the array is already sorted or not
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            return;
        }
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
    cout<<"After Bubble Sort: "<<endl;
    BubbleSort(A, n);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    return 0;
}