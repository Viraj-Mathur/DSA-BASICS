/* Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths 
 from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
 At any cell we are allowed to move in only two directions:- bottom and right.
*/

#include <bits/stdc++.h>

using namespace std;

// using recursion memoisation in tabular form with space optimisisation approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        vector<int> curr(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // base case
                if(i==0 && j==0){
                    curr[0] = 1;
                    continue;
                }

                int up =0;
                if(i>0)
                    up = prev[j];

                int left = 0;
                if(j>0)
                    left = curr[j-1];
                
                curr[j] = up+left;

            }
            prev = curr;
        }

        return prev[n-1];
    }
};

int main(){
  
    
    return 0;
}