// Maximum Nesting Depth of the Parentheses
/*
Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3

*/

// Approach : use stacks - TC:O(N)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stack;
        int maxi = 0;
        for(char c : s){
            if(c=='('){
                stack.push(c);
            }
            else if(c==')'){
                maxi = max((int)stack.size(), maxi);
                stack.pop();
            }
        }
        return maxi;
        
    }
};

int main(){
    
    return 0;
}