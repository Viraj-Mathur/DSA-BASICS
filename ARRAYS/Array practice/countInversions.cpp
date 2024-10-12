/*
Count Inversions
Given an array of integers. Find the Inversion Count in the array.  
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Expected Time Complexity: O(n*logn).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ arr.size(),arr[i] ≤ 10^5
*/

#include <bits/stdc++.h>

using namespace std;


// brute force n^2 approach
int numberOfInversions1(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++; //using condition only
        }
    }
    return cnt;
}


// using merge sort - optimised code(O(N*logN))
/*
intuition : Assume two sorted arrays are given i.e. a1[] = {2, 3, 5, 6} and a2[] = {2, 2, 4, 4, 8}. Now, we have to count the pairs i.e. a1[i] and a2[j] such that a1[i] > a2[j].
as the element is sorted if for one element the condition satisied then because it is sorted we can add the next remaining element also  in the pair this makes our apprach in linear m+n times

now using merge sort we can break the array in two parts and with the broken tree from bottom to up with the same approach we can find the count


n the merge function, we will use a temp array to store the elements of the two sorted arrays after merging. Here, the range of the left array is low to mid and the range for the right half is mid+1 to high.
*/

// making a merge sort function
int merge(vector<int>&a, int low,int mid,int high){
    // making a temporary array
    vector<int>temp; // making a temporary array
    int left = low; // starting index of left half of arr
    int right = mid+1; // starting index of right half of arr

    // count to count pairs
    int count = 0;

    //storing elements in the temporary array in a sorted manner

    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++; //increment indexes
        }
        else{
            temp.push_back(a[right]);
            count+=(mid-left+1);
            // add to count if condition matches
            right++;
        }
    }
    // Leftover conditions

     // if elements on the left half are still left 
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }

    //  if elements on the right half are still left 
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }

    // transfering all elements from temporary to arr 
    for(int i= low;i<=high;i++){
        a[i] = temp[i-low];
    }

    return count;
}

int mergeSort(vector<int>&a, int low,int high){
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;
    count += mergeSort(a, low, mid);  // left half
    count += mergeSort(a, mid + 1, high); // right half
    count += merge(a, low, mid, high);  // merging sorted halves
    return count;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);

}



int main(){
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    
    return 0;
}