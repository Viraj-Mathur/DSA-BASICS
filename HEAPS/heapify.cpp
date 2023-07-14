/*HEAPIFY ALGO 
Heapify refers to the process of rearranging the elements in a heap to maintain the heap property.
   In other words, it ensures that the largest (in a max-heap)
   or smallest (in a min-heap) element is always at the root of the heap.

   T.C: O(log n)
*/

#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
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
        size --;
        // step 2: reorder
        heapify(arr,size,1);
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

    // heapsort
    heapSort(arr,n);

    cout << "Printing the array after HeapSort: " << endl;
    for (int i = 1; i <=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;


    // WE CAN ALSO USE PRIORITY QUEUE FOR MIN AND MAX HEAP
    
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