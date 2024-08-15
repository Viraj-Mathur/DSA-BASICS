/*
632. Smallest Range Covering Elements from K Lists

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

*/

/*
intuition : if we pick first element from every list and find its max and min we will have atleast one element from every list in the range

take first elements from every list and find min and max (with their difference) then remove the minimum value and iterate throught the next element of the list of that perticular list

// as arrays are sorted in increasing order we use min heap

Structure of nums:

nums is a vector of vectors, i.e., a 2D vector.
Each inner vector represents a sorted list of integers.
The number of inner vectors (rows) is denoted by k.


Row (i):

The row index represents which list (inner vector) we're currently dealing with.
In the code, row or i ranges from 0 to k-1.
Each row corresponds to one of the k sorted lists.

Column (col):

The column index represents the position within a particular list.
It starts from 0 and can go up to the length of that specific list minus 1.
As we move through a list, we increment the column index.


When initializing the min heap, we start with the first element (column 0) of each list (row i).
As we process elements, we move to the next column in the same row: topCol + 1.
We check if a next element exists in a list by comparing topCol + 1 with the size of that list: nums[topRow].size().

*/

#include <bits/stdc++.h>

using namespace std;


// making a simple class consist of data row and col
class Node{
    public:
    int data;
    int row;
    int col;

    Node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};

// class to compare elements for the min heap - decrease
class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // initialising minimum and maximum elements to infinity
        int mini = INT_MAX;
        int maxi = INT_MIN;

        // creating a min heap
        priority_queue<Node*, vector<Node*>,compare>minHeap;

        // inserting first elements of every k lists
        int k = nums.size();

        for(int i=0;i<k;i++){
            int el = nums[i][0]; //getting the first element of ith array of k lists
            
            maxi = max(maxi, el);//finding the maximum element out of those list

            mini = min(mini, el);//finding the minimum element out of those list

            // pushing the ranges in the min heap
            minHeap.push(new Node(el,i,0)); 

            // NOTE: each node of heap will contain data of element,its row and its col
        }

        int ansStart = mini;
        int ansEnd = maxi;

        // now checking for ranges
        while(!minHeap.empty()){
            // fetch the top element -We extract its value, row, and column information.
            Node* top = minHeap.top();
            
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;

            // This element is removed from the heap as we've processed it
            minHeap.pop();

            // the element popped will be the minimum element so update the current minimum
            mini = topElement;
            
            // now checking for answer if we have found the smaller range
            if(maxi - mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;

                // If the current range (maxi - mini) is smaller than the previous best range, we update our answer.


            }

            // Try to add the next element from the same list by checking weather element exist or not

            if(topCol + 1< nums[topRow].size()){
                // exists
                // create a new node and insert
                // update maxi as we are inserting new node -We update maxi if this new element is larger.
                maxi = max(maxi,nums[topRow][topCol+1]);

                // We create a new node for this element and add it to the minHeap.
                Node* newNode = new Node(nums[topRow][topCol + 1], topRow,topCol+1);
                minHeap.push(newNode);

                // if there is no we break the loop - this happens if one of the list is completed
            }
            else{
                // not exists
                break;
            }

        }
            vector<int>ans;
            ans.push_back(ansStart);
            ans.push_back(ansEnd);
            return ans;
    }
};

int main(){
    
    return 0;
}