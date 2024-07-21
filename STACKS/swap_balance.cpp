/*
1963. Minimum Number of Swaps to Make the String Balanced

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.


*/

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '['){
                st.push(s[i]);

            }
            else{
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }

        count = st.size();
        int ans = 0;
        ans = ceil(count/4.0);

        return ans;// each swap can resolve at max 4 brackets.
    }
};


//the count in this question will give number of remaining brackets in the stack

// Approach 2: 2 pointer
class Solution {
public:
    int minSwaps(string s) {
        int i = 0;
        int j = 0;

        for (int br = 0; br < s.size(); br++) {
            if (s[br] == '[') {
                i++;
            } else {
                if (i == 0) {
                    j++;
                } else {
                    i--;
                }
            }
        }

        i += j;

        return ceil(i / 4.0);


    }
};