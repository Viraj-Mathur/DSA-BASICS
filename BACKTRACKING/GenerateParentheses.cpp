/*
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]


*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:
    void solve(string &temp, int Copen, int Cclose, int remOpen, int remClose, vector<string> &res)
    {
        // base case
        if (remClose == 0 && remOpen == 0)
        {
            res.push_back(temp);
            return;
        }
        // "(" waali recursive call
        if (remOpen > 0)
        {
            temp.push_back('(');
            solve(temp, Copen + 1, Cclose, remOpen - 1, remClose, res);

            // backtrack
            temp.pop_back();
        }
        // ")" waali recursive call
        if (remClose > 0 && Copen > Cclose)
        {
            temp.push_back(')');
            solve(temp, Copen, Cclose + 1, remOpen, remClose - 1, res);

            // backtrack
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string temp = "(";
        int currOpen = 1;
        int currClose = 0;
        int remOpen = n - 1;
        int remClose = n;

        vector<string> result;

        solve(temp, currOpen, currClose, remOpen, remClose, result);
        return result;
    }
};

int main()
{

    return 0;
}