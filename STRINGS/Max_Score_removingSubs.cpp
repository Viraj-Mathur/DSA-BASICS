/*
1717. Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
        // Approach 1 : using stack and greedy

// as we know ba is more than ab so greedely we try to remove ba pairs first using stacks and when all the ba pairs are removed 
// then then put the remaining chars in the stack in a new string and remove ab pairs now

// s is the string,targetString is first ba then ab, point is first 5 then 4
    int Value1(string& s, string targetString, int point) {

        int totalPoints = 0;

        // creating a stack
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && c == targetString[1] && st.top() == targetString[0]) {
                st.pop();
                totalPoints += point;
            } else {
                st.push(c);
            }
        }
        
        string newString(st.size(), ' ');
        for (int i = st.size() - 1; i >= 0; i--) {
            newString[i] = st.top();
            st.pop();
        }
        
        s = newString;  // Update the original string for the next call
        return totalPoints;
    }

    // Approach 2 : using 2 pointers
    // s is the string,targetString is first ba then ab, point is first 5 then 4

    int Value(string& s, string targetString, int point) {
        int totalPoints = 0, n = s.length(), writeIndex = 0;
        
         // Using two pointers: readIndex and writeIndex
        for(int readIndex = 0;readIndex<n;readIndex++){

            // Copy current character to writeIndex position
            s[writeIndex++] = s[readIndex];

            // Check if we have at least two characters and they match the target string
            if(writeIndex > 1 && s[writeIndex-1] == targetString[1] && s[writeIndex-2] == targetString[0]){
                writeIndex -= 2; //take writeaIndex 2 indeces back if target string is matched
                totalPoints += point;
            }

            // Continue iterating until all chars in string are processed
        }
        s = s.substr(0,writeIndex);
        return totalPoints;
    }

public:
    int maximumGain(string s, int x, int y) {
        if (y > x) {
            return Value(s, "ba", y) + Value(s, "ab", x);
        } else {
            return Value(s, "ab", x) + Value(s, "ba", y);
        }
    }
};

int main(){
    
    return 0;
}