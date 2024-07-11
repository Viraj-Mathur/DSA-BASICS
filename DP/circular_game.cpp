/*
1823. Find the Winner of the Circular Game - similar to Josephus problem.

There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.

Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.

*/

#include <bits/stdc++.h>

using namespace std;

// Approach 1 : general stimulation - O(n^2)

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>circle;
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }

        int curr = 0;

        while(circle.size()>1){
            int remove_next = (curr + k-1 )%circle.size(); //because of circular list we use mod
            circle.erase(circle.begin() + remove_next);
            curr = remove_next;

        }
        return circle[0];
        
    }
};

// Approach 2 - recursion -  O(n)
/*
We observed that after the first turn/elimination, our problem reduces to a smaller subproblem of f(n−1,k). Accounting for the indexing offset discussed above, we can form the following relationship between f(n,k) and f(n−1,k):

f(n,k)=(f(n−1,k)+k)modn


*/
class Solution {
    private:
    int rec(int n,int k){
        if(n==1){
            return 0;
        }
        else{
            return (rec(n-1, k)+k)%n;
        }
    }
public:
    int findTheWinner(int n, int k) {
        return rec(n,k)+1;
    }
};


// bottom up -dp - the time & space complexity is O(n).
int findTheWinner(int n, int k) {
        // return rec(n,k)+1;
        // bottom up DP
        int ans = 0;
        for(int i=2;i<=n;i++){
            ans = (ans+k)%i;
        }
    return ans+1;
}

// dp - top down - the time & space complexity is O(n).
#include <vector>
using namespace std;

class Solution {
private:
    int rec(int n, int k, vector<int>& dp) {
        if (n == 1) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = (rec(n - 1, k, dp) + k) % n;
        return dp[n];
    }

public:
    int findTheWinner(int n, int k) {
        vector<int> dp(n + 1, -1);
        return rec(n, k, dp) + 1;
    }
};


int main(){
    
    return 0;
}