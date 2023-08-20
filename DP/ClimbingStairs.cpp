/* https://leetcode.com/problems/climbing-stairs/description/ 

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

// the problem is similar to fibonacci series

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int index;
        if(n<=3) return n;
        int prev = 3;
        int prev_prev = 2;

        for(int i=4;i<=n;i++){
            index = prev + prev_prev;
            prev_prev = prev;
            prev = index;
        }
        return index;
        
    }
};



int main(){
    
    return 0;
}