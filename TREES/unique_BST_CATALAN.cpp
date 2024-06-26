#include <bits/stdc++.h>

using namespace std;

/*
96. Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.

Approach:
the given question is asking us to find the Catalan Number C of a number n:
C(n)= C(i) * C(n-i-1) => i varies from 0 to n-1

Meaning of the symbols:

C(n) represents the nth Catalan number, which in our context is the number of unique BSTs with n nodes.
i represents the root node we're considering (1 ≤ i ≤ n).


Left and right subtrees:

When we choose i as the root, we have:

i-1 nodes smaller than i (left subtree)
n-i nodes larger than i (right subtree)




Counting combinations:

C(i-1) represents the number of unique BSTs for the left subtree
C(n-i) represents the number of unique BSTs for the right subtree


Multiplication principle:

For each unique left subtree, we can pair it with any unique right subtree
Therefore, we multiply C(i-1) and C(n-i) to get the total number of unique BSTs with root i




*/

// solving using dp - tabulation
class Solution1 {
public:
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0] = 1; //base case
        for(int i=1;i<=n;i++){
            dp[i] = 0;
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

// using memo

class Solution2 {
    private:
    int memo(int n, vector<int>&dp){
        if(n<=1) return 1;

         // Check if already computed
        if (dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += memo(i-1,dp) * memo(n-i,dp);
        }

        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};


int main(){
    Solution2 sol;

    vector<int> testCases = {1, 3, 5, 10};

    for (int n : testCases) {
        int result = sol.numTrees(n);
        std::cout << "Number of unique BSTs with " << n << " nodes: " << result << std::endl;
    }

    return 0;
}