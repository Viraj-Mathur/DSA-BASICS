// 2343. Query Kth Smallest Trimmed Number
// https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/





/*
APPROACH:USINH HEAP BUT GIVES TLE IN LEETCODE
Create a priority queue: Use a max-heap priority queue to maintain k smallest trimmed numbers
For each number in nums:

    Trim it to the specified length (val = nums[i].substr(nums[i].size()-trim,trim)) if necessary.
    Create a pair containing the trimmed number and its index (pair<string,int> val1 = {val,i}).
    If the priority queue has less than k elements, add the pair directly (pq.push(val1)).
    If the priority queue is full, compare the current pair with the largest pair in the queue (pq.top()):
        If the current pair is smaller, remove the largest pair and add the current pair (pq.pop(); pq.push(val1)).
        After processing all numbers, the priority queue holds the k smallest trimmed numbers.
Add the index of the smallest trimmed number (which is at the top of the queue) to the ans vector (ans.push_back(pq.top().second)).
*/

#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<string> trimmed_nums(n); // Precalculate trimmed numbers
        for (int i = 0; i < n; i++) {
            trimmed_nums[i] = nums[i].substr(nums.size() - queries[0][1], queries[0][1]); // Initialize with first query's trim
        }

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int k = queries[i][0], trim = queries[i][1];

            // Update trimmed_nums if trim value changes
            if (trim != queries[i-1][1]) {
                for (int j = 0; j < n; j++) {
                    trimmed_nums[j] = nums[j].substr(nums.size() - trim, trim);
                }
            }

            // Use a min-heap to find the k-th smallest trimmed number
            priority_queue<pair<string, int>, vector<pair<string, int>>, greater<>> pq;
            for (int j = 0; j < n; j++) {
                pq.push({trimmed_nums[j], j});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
            ans[i] = pq.top().second;
        }
        return ans;
    }
};
// USING HEAP BUT DOES NOT GIVES TLE
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto j: queries){
            int k = j[0], i=j[1];
            int rm = nums[0].size()-i;
            priority_queue<pair<string,int>>pq;
            for(int p=0; p<nums.size(); p++){
                pq.push({nums[p].substr(rm), p});
                while(pq.size()>k) pq.pop();
            }
            if(!pq.empty())
                ans.push_back(pq.top().second);
        }   
        return ans;
    }
};



int main(){
    
    return 0;
}