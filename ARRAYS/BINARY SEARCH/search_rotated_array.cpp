//  Program to Search In Rotated Sorted Array using BINARY SEARCH

// WITH PIVOTING USING CONCEPT OF BINARY SEARCH
#include<vector>
using namespace std;

int getPivot(vector<int> & arr,int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid]>= arr[0]){  //The first line
            s = mid+1;  
        }
        else{
            e = mid-1;
        }
        
        mid = s+(e-s)/2;  //updating the value of mid;
    
    return s;
}
}

// int binarySearch(int arr[], int s, int e, int key){
    int binarySearch(vector<int>& arr,int s, int e, int key){
    int start = s;
    int end = e;
    
    int mid = start + (end-start)/2;
    
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
//         go right
        if(key>arr[mid]){
            start = mid + 1;
        }
        else{   //key<arr[mid]
            end = mid -1;
        }
        return -1;
    }
    
}
int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getPivot(arr,n);
    if(k>= arr[pivot] && k<=arr[n-1]){
        return binarySearch(arr, pivot, n-1,k);  //second line
        }
    else{
        return binarySearch(arr,0,pivot-1,k);   // first line
    }
}

