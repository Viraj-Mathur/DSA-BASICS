// Given the array find the kth largest sum subarray

#include <bits/stdc++.h>
#include<algorithm>

using namespace std;


/*
Approach: Find the sum of each sub array using for loop with help of i and j loop and then store the sum of 
the subarrys in a sum -> TC: O(N^2 log N) S.C: O(N^2)
*/

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;
	int n = arr.size();

	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			sumStore.push_back(sum);
		}
	}

	sort( sumStore.begin(), sumStore.end() );

	return sumStore[sumStore.size()-k];

}


/*
APPROACH 2: USING MIN HEAP (S.C = O(K) now instead of n^2)
*/

int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>, greater<int> > min;

    int n = arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(min.size() < k){
                min.push(sum);
            }
            else{
                if(sum > min.top()) {
                    min.pop();
                    min.push(sum);
                }
            }
        }
    }
    return min.top();

}





int main(){
    
    return 0;
}