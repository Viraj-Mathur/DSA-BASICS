// C++ program to implement iterative Binary Search
#include <bits/stdc++.h>
using namespace std;

// A iterative binary search function. It returns
// location of x in given array arr[l..h] if present,
// otherwise -1, time complexity O(Log n). 
int binarySearch(int arr[], int l, int h, int x)
{
	while (l <= h) {
		int m = l + (h - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			h = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int x = 11;
   

    
    int index =  binarySearch(arr,0,n,x);
    if (index != -1) {
        cout << "Found " << x << " at index " << index << endl;
    }
    else {
        cout << "Not found " << x << endl;
    }

    return 0;
}