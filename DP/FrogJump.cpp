/*

https://leetcode.com/problems/frog-jump-ii/description/

PROBLEM STATEMENT: you are given an array stones representing positions of stones in a straight line. 
You want to find the maximum jump distance a frog can make while following these conditions:

    The frog can jump forward to the next stone or to the stone after the next stone.
    The frog can only jump in positive direction, not backward.
    The frog must jump from its current position.
*/

#include <bits/stdc++.h>

using namespace std;

// Approach 1: DP with space complexity O(n)

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int dp[n];
        dp[0]=0;
        dp[1]=stones[1]-stones[0];
        if(n==2)
            return dp[1];
        dp[2]=stones[2]-stones[0];
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-1],stones[i]-stones[i-2]);
        }
        return dp[n-1];
    }
};




// Approach 2: DP with space complexity O(1)

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int prev=abs(stones[1]-stones[0]);
        int prev2=0;
        for(int i=2;i<n;i++){
            int sum= abs(stones[i]-stones[i-2]);
            int curr=max(prev,sum);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};


// Time Complexity O(n) for both the cases...

int main(){
    
    return 0;
}