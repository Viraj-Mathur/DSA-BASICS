/*
1190. Reverse Substrings Between Each Pair of Parentheses

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.

*/




#include <bits/stdc++.h>

using namespace std;


// Approach 1 : using stacks - O(n^2)

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";

        stack<int>st;

        for(int i=0;i<=n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int start = st.top() + 1;
                int end = i;

                reverse(s.begin() + start, s.begin() + end);
                st.pop();
            }
        }

        for(auto &el : s){
            if(el!='(' && el!=')'){
                ans += el;
            }
        }

        return ans;
               

    }
};

// Approach 2 : O(n) - processes the string by alternating the traversal direction whenever it encounters a parenthesis

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> oppIndex(n,-1);
        stack<int> open;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == ')'){
                int openIndex = open.top();
                open.pop();
                oppIndex[openIndex] = i;
                oppIndex[i] = openIndex; // reversing by swapping character by character
            }
        }

        string ans = "";
        int direction = 1;
        for(int i=0;i<n;i+=direction ){
            if(s[i] == '(' || s[i] == ')'){
                i = oppIndex[i];
                direction *= -1; //direction reversed with every iterations
            }
            else{
                ans+= s[i]; //pushing string characters
            }
        }

        return ans;

    }
};

/*
Example Walkthrough
Consider the string s = "(u(love)i)".

Step 1: Matching Parentheses:

For i = 0, s[i] = '(', so open.push(0).
For i = 2, s[i] = '(', so open.push(2).
For i = 7, s[i] = ')', the top of the stack is 2, so oppIndex[2] = 7 and oppIndex[7] = 2.
For i = 8, s[i] = ')', the top of the stack is 0, so oppIndex[0] = 8 and oppIndex[8] = 0.
Now, oppIndex will look like this: [8, -1, 7, -1, -1, -1, -1, 2, 0].

Step 2: Building the Result:

Start with i = 0 and direction = 1.
At i = 0, s[i] = '(', update i = 8 and direction = -1.
At i = 7, s[i] = ')', update i = 2 and direction = 1.
At i = 3, s[i] = 'l', add 'l' to ans.
Continue this process until the entire string is processed.
The final result stored in ans will be "iloveu".
*/

int main(){
    
    return 0;
}