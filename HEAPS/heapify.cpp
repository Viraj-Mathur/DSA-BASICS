/*HEAPIFY ALGO 
Heapify refers to the process of rearranging the elements in a heap to maintain the heap property.
   In other words, it ensures that the largest (in a max-heap)
   or smallest (in a min-heap) element is always at the root of the heap.

//    ek element ko sahi jagah par pahochana is heapify

   T.C: O(log n)
*/


/*
in the build heap function we do not need to heapify the leaf node as they are already heaps
NOTE IN COMPLETE BINARY TREE IF TREE SIZE IS "n" then no of leaf nodes = from (n/2 + 1) to n

therefore NO NEED TO HEAPIFY NODES FROM N/2+1 TO N
HEAPIFY NODES LESS THAN N/2 

*/

#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i) // given - array, its size and the index
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left]) // updating largest for left base condition
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) // updating largest for right base condition
    {
        largest = right;
    }

    // if left is greater replace root index with left
    // if right is greater replace root index with right

    if (largest != i) // this means left or right child is greater than the current node
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// T.C of heapSort is O(n logn)

void heapSort(int arr[], int n){
    int size = n;

    while (size>1)
    {
        // step 1: swap first and last element
        swap(arr[size] ,arr[1]);
        size --; // last element is now sorted forget it
        
        // step 2: reorder using heapify function
        heapify(arr,size,1);
    }
    
}

void buildHeap(int arr[],int n){
    // We need to start from the first non-leaf node 

    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

int main()
{

    int arr[8] = {-1, 23, 45, 76, 12, 18, 37, 40};
    int n = 7;

    // creating a heap
    for (int i = 1; i < n; i++)
    {
        heapify(arr, n, i);
    }
    cout << "Printing the array: " << endl;
    for (int i = 1; i <=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    buildHeap(arr,n);
    cout<<"Printing the heap"<<endl;
    for(int i = 0;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    cout << endl;
    cout << endl;

    // heapsort
    heapSort(arr,n);

    cout << "Printing the array after HeapSort: " << endl;
    for (int i = 1; i <=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;


    // WE CAN ALSO USE PRIORITY QUEUE  - stl function which act as MIN AND MAX HEAP
    
    // for max heap
    priority_queue<int> pq;;

    pq.push(5);
    pq.push(3);
    pq.push(9);
    pq.push(7);

    cout<<"Element at the top: "<< pq.top() <<endl;
    pq.pop();
    cout<<"Element at the top after deletion: "<<pq.top()<<endl;

    cout<<"Size is : "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"pq is empty! "<<endl;
    }
    else{
        cout<<"pq is not empty!"<<endl;
    }
    cout<<endl;

    // min heap
    priority_queue<int,vector<int>,greater<int> > minheap;
    minheap.push(6);
    minheap.push(2);
    minheap.push(8);
    minheap.push(4);

    cout<<"Element at the top: "<< minheap.top() <<endl;
    minheap.pop();
    cout<<"Element at the top after deletion: "<<minheap.top()<<endl;

    cout<<"Size is : "<<minheap.size()<<endl;

    if(minheap.empty()){
        cout<<"minheap is empty! "<<endl;
    }
    else{
        cout<<"minheap is not empty!"<<endl;
    }



    return 0;
}