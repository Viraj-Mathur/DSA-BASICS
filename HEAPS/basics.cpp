// inserting in the heaps
#include <bits/stdc++.h>

using namespace std;

// to insert : first add the element at the end of the array and then swap it with its parent element (n/2th index)
// insertion time complexity: O(log n)
class heap {
    public:
    int arr[100];
    int size;

    // constructor
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index >1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) {  //if element is larger than the parent element than swap(Max heap)
                swap(arr[parent], arr[index]);
                index = parent; //updated the position of the index
            }
            else{
                return;
            }
        }
    }

    void print() {
        for(int i=1;i<=size; i++){ // i not from 0 to prevent -1
            cout<< arr[i] << " ";
        }
        cout<<endl;
    }

    /* deletion process: 1.Put last node in first node(parent node)
                         2.Remove the last node
                         3.Propagate rest of the nodes to its correct postition 
                         T.C: O(log n)
                         */

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        // step 1: Put last node in first node index(parent node)
        arr[1] = arr[size];
        // step 2;
        size--;

        // Take root node to its correct postion
        int i=1;
        while (i<size)
        {
            int leftIndex = 2*i; //formula for left index
            int rigthIndex = 2*i+1; // formula for rigth index

            if(leftIndex < size && arr[i]< arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex; // updating the index position
            }
            else if(rigthIndex < size && arr[i] < arr[rigthIndex]){
                swap(arr[i], arr[rigthIndex]);
                i = rigthIndex; // updating the index position
            }
            else{
                return;
            }
        }
        
    }
};




int main(){
    heap h;
    h.insert(23);
    h.insert(52);
    h.insert(16);
    h.insert(75);
    h.insert(20);

    h.print();

    h.deleteFromHeap();
    h.print();
    
    return 0;
}