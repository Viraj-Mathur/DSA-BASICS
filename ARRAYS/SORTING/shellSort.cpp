#include<iostream>

using namespace std;

// complexity: O(nlog n)

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*LOGIC:
The function takes an integer array A and the size of the array n as input parameters.
The outer loop is responsible for dividing the array into smaller sub-arrays using a gap sequence.
 In this implementation, the gap sequence starts with n/2 and is divided by 2 in each iteration until the gap becomes 1.
*/

// Code is similar to Insertion Sort with some modifications

void ShellSort(int A[],int n){
    for(int gap=n/2;gap>=1;gap/=2){  //starts with a gap of n/2, where n is the size of the array, and divides the gap by 2 in each iteration until it reaches 1.
        for(int j=gap;j<n;j++){
            int temp = A[j];
            int i = j - gap;
            while(i>=0 && A[i]>temp){
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
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
    cout<<"After Shell Sort: "<<endl;
    ShellSort(A, n);
    for (int i=0; i<n; i++){
        cout << A[i]<<" ";
    }
    return 0;
}