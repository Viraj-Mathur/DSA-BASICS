/*
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2:
*/

// USING KMP ALGO

class Solution {
private:
    void lpsFind(vector<int>&lps, string s){
        int pref = 0, suf = 1;
        while(suf<s.size()){
            if(s[pref] == s[suf]){
                lps[suf] = pref+1;
                suf++;
                pref++;
            }
            else{
                if(pref == 0){
                    lps[suf] = 0;
                    suf++;
                }
                else{
                    pref = lps[pref - 1];
                }
            }
        }
    }

    bool kmp(string p,string s){
        vector<int>lps(s.size(),0);
        lpsFind(lps,s);
        int first = 0, second =0;
        while(first < p.size() && second < s.size()){
            if(p[first] == s[second]){
                first++, second++;
            }
            else{
                if(second ==0){
                    first++;
                }
                else{
                    second = lps[second-1];
                }
            }
        }
        if(second == s.size()){
            return true;
        }
        else{
            return false;
        }
    }

public:
    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        string st = a;
        int repeat = 1;

        while(st.length() < b.length()){
            st+= a;
            repeat++;
        }
        if(kmp(st,b) == true){
            return repeat;
        }
        if(kmp(st+a,b) == true){
            return repeat+1;
        }
        else{
            return -1;
        }
        
    }
};
