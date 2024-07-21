/*
301. Remove Invalid Parentheses

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 
*/

// refer swap balance for hint in stack folder - code for finding number of removals


class Solution {
private:
    // Helper function to calculate the number of invalid parentheses that need to be removed
    int getRemovalCount(const string& s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        return st.size();
    }

    // Recursive function to generate valid strings by removing invalid parentheses
    void solve(const string& s, int removeCount, vector<string>& ans, map<string, bool>& mpp) {
        // If the string has already been processed, return to avoid duplicates
        if (mpp[s]) {
            return;
        } else {
            mpp[s] = true;
        }

        // Base case: if no more removals are allowed
        if (removeCount == 0) {
            // Check if the current string is valid
            if (getRemovalCount(s) == 0) {
                ans.push_back(s);
            }
            return;  
        }

        // Try removing each character and recursively check for valid strings
        for (int i = 0; i < s.length(); i++) {
            // Generate the new string by removing the current character
            string leftStr = s.substr(0, i);
            string rightStr = s.substr(i + 1);
            string temp = leftStr + rightStr;
            solve(temp, removeCount - 1, ans, mpp);
        }
    }

public:
    // Main function to remove invalid parentheses and return all possible valid strings
    vector<string> removeInvalidParentheses(string s) {
        // Get the initial count of invalid parentheses to be removed
        int removeCount = getRemovalCount(s);

        // Vector to store the resulting valid strings
        vector<string> ans;

        // Map to store visited strings and avoid duplicates
        map<string, bool> mpp;

        // Start the recursive function call
        solve(s, removeCount, ans, mpp);

        return ans;
    }
};


/* concept of leftStr and rightStr
string : ()())()
i=-----------^ 
let leftStr = ()()
let rightStr = ()
temp = left+rigth = ()()()

*/