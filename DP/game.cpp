#include <bits/stdc++.h>

using namespace std;


// Try to find the maximum node and then minimise it



/*
375. Guess Number Higher or Lower II
Medium
Topics
Companies
Hint
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

 

Example 1:


Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
Example 2:

Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
Example 3:

Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
 

Constraints:

1 <= n <= 200
*/
/*

for example for range [1,10] answer is 6
if guessed 6 then done
else 
answer less than 6 so range [1,5]
or answer greater than 6 so range [7,10]

*/


// Approach 1 using recursion - gives TLE
class Solution {
private:

// Approach 1 using recursion - gives TLE
    int solveRec(int start,int end){
        // base case
        if(start>=end){
            return 0;
        }

        int ans = INT_MAX;

        for(int i=start;i<=end;i++){
            // Considering the current penalty and then trying to fetch answer from left and right  
            ans = min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));
        }

        return ans;
    }

// Approach 2 using memo
int memo(int start,int end, vector<vector<int>>&dp){

    // base case
        if(start>=end){
            return 0;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int ans = INT_MAX;

        for(int i=start;i<=end;i++){
            // Considering the current penalty and then trying to fetch answer from left and right  
            ans = min(ans,i+max(memo(start,i-1,dp),memo(i+1,end,dp)));
        }

        dp[start][end] = ans;

        return dp[start][end];

}

// Approach 3: usind tabulation

int solveTab(int n){
    // creating a dp array
    vector<vector<int>>dp(n+2,vector<int>(n+2));
    // Step 2 : Observe base case of top down
        // Handled in step 3
        // Step 3 : Reverse the flow of top down

        for(int start = n;start>=1;start--){
            for(int end = 1;end<=n;end++){
                // base case
                if(start>=end){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i=start;i<=end;i++){
                        ans = min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];//The final answer is stored in dp[1][n], representing the minimum cost for the range 1 to n.

}


//O(n^3) and a space complexity of O(n^2). 
public:
    int getMoneyAmount(int n) {

        // // Recursive code
        // int ans = solveRec(1,n);

        // // Top down approach
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = memo(1,n,dp);

        // using tabulation
        int ans = solveTab(n);

        return ans;
    }
};


int main(){
    
    return 0;
}