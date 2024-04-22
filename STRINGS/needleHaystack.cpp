// 28. Find the Index of the First Occurrence in a String
/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

*/
// Approach 1: TC - O(n * m)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // Handle the case when the needle is empty
        if (m == 0) {
            return 0;
        }

        // Iterate through the haystack string
        for (int i = 0; i <= n - m; i++) {
            // Check if the substring starting at index i matches the needle
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        // If the needle is not found in the haystack
        return -1;
    }
};


// Approach 2 - optimised and vv.imp : using KMP method
class Solution {
public:
// function for finding longest prefix sum
    void findlps(vector<int> &lps, string s) {
        int pre = 0;
        int suff = 1;

        while(suff < s.size()){
            if(s[pre] == s[suff]){
                lps[suff] = pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre == 0){
                    lps[suff] = 0;
                    suff++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
	}

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0); // finding the lps of needle
        findlps(lps, needle);

        //initialising pointers
        int first = 0;
        int second = 0;

        while(first < haystack.size() && second < needle.size()){

            // if matched
            if(haystack[first] == needle[second]){ //if strings matched increment both the counter till it meet the requirement
                first++;
                second++;
            }

            // if not matched
            else{
                if(second == 0){
                    first++;
                }
                else{
                    second = lps[second-1]; //go to the previous index of needle and check the lps of it
                }
            }
        }
        
        // answer if exists
        if(second == needle.size()){
            return first - second; // answer will be the difference between indexes of haystack and needle
        }
        // if not exists
        return -1;
    }
};

// TC = O(n+m) : linear time



// // Approach: first check if first letter of needle macthes  with the first character of haystack, then use two pointers to find the next occurrence.
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         for(int i=0;i<haystack.length();i++){
//             //check if first letter matches
//             if(haystack.substr(i,needle.length())==needle){
//                 int j=0; //pointer for needle
//                 int k=0; //pointer for haystack
//                 while(j<needle.length() && k<haystack.length() && needle.){
//                     j++;
//                     k++;
//                     if(j==needle.lenght()){
//                         return i;
//                     }
//                 }
//         }
//     }
//     return -1;
// }
// };