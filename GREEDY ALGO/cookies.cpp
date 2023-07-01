/*
Leetcode problem 455(https://leetcode.com/problems/assign-cookies/)
Assume you are an awesome parent and want to give your children some cookies. 
But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i], 
we can assign the cookie j to the child i, and the child i will be content. 
Your goal is to maximize the number of your content children and output the maximum number.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.rbegin(),s.rend()); //decrease sort;
        sort(g.rbegin(),g.rend()); //decrease sort;

        int curr=0;
        int total=0;
        int n=g.size();
        int m=s.size();

        for (int i=0;i<n;i++){
            if(curr<m && g[i]<=s[curr]){ //only if greed satisfied totally
                total++;
                curr++;
            }
        }
        return total;
        
    }
};