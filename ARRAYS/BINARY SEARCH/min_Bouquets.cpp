/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
*/



#include <bits/stdc++.h>

using namespace std;


// USING BRUTE FORCE

class Solution {
    private:
    int possible(vector<int>& bloomDay, int day, int m, int k) {
    int n = bloomDay.size();
        int cnt = 0; //a counter
        int noOFb = 0;

        // count number of bouquets
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{ //for condition where we encounter non bloomed flower till now
            noOFb += (cnt/k); // store how many of them bloomed
            cnt = 0;
            }
        }
        noOFb += (cnt/k); //final result
        return noOFb>=m;
        

        
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int net_range = m*1ll * k * 1ll; // n*k will give net total flowers req to make a bouquet from the give array 
        // The 1ll is a literal representing the integer constant 1 but with the type explicitly specified as long long so that multiplication does not overflow
        int n = bloomDay.size();
        if(net_range > n) return -1; // impossible case
        // fing min and max
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);

        }
        for(int i=mini; i<=maxi ;i++){ //ranges are specified
            if(possible(bloomDay , i, m,k))
                return i;
        }
        return -1;    

       
    }
};
// complexity : O(N) gives TLE

// APPROACH: APPLYING BINARY SEARCH

class Solution {
private:
    int possible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0; //a counter
        int noOFb = 0;

        // count number of bouquets
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{ //for condition where we encounter non bloomed flower till now
                noOFb += (cnt/k); // store how many of them bloomed
                cnt = 0;
            }
        }
        noOFb += (cnt/k); //final result
        return noOFb >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long net_range = m * 1ll * k * 1ll; // n*k will give the net total flowers required to make a bouquet from the given array 
        // The 1ll is a literal representing the integer constant 1 but with the type explicitly specified as long long so that multiplication does not overflow
        int n = bloomDay.size();
        if(net_range > n) return -1; // impossible case
        // find min and max
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        // applying binary search (on answers)
        int low = mini, high = maxi; //specifying the range  
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};


int main(){
    
    return 0;
}