/*
17. Letter Combinations of a Phone Number

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};
    vector<string> res;
    vector<string> buttons{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    backtrack(res, buttons, digits, "", 0);
    return res;
  }

  void backtrack(vector<string>& res, vector<string>& buttons, string digits, string curr, int pos) {
    if (pos == digits.length()) {
      res.push_back(curr);
      return;
    }
    for (auto c : buttons[digits[pos] - '0']) { //to convert letters into their corresponding integer values
      curr.push_back(c);
      backtrack(res, buttons, digits, curr, pos + 1);
      curr.pop_back();
    }
  }
};

int main(){
    
    return 0;
}