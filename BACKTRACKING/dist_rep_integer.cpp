/*
1655. Distribute Repeating Integers - https://leetcode.com/problems/distribute-repeating-integers/description/

You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

The ith customer gets exactly quantity[i] integers,
The integers the ith customer gets are all equal, and
Every customer is satisfied.
Return true if it is possible to distribute nums according to the above conditions.

 

Example 1:

Input: nums = [1,2,3,4], quantity = [2]
Output: false
Explanation: The 0th customer cannot be given two different integers.
Example 2:

Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.
Example 3:

Input: nums = [1,1,2,2], quantity = [2,2]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= 1000
m == quantity.length
1 <= m <= 10
1 <= quantity[i] <= 105
There are at most 50 unique values in nums.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool solve(vector<int>& quantity,unordered_map<int,int>& count,int index ){
        // base case
        if(index == quantity.size()){
            return true;
        }

        for(auto it = count.begin(); it!=count.end();it++){
            if(it->second >= quantity[index]){
                count[it->first] = count[it->first] - quantity[index]; //if matched then remove the pairs

                bool aageKaSol = solve(quantity,count,index+1);
                if(aageKaSol == true){
                    return true;
                }

                // else backtrack
                count[it->first] = count[it->first] + quantity[index]; //add them back


            }
        }
        return false;
    }
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        // creating a map to store the frequency of numbers in the array
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        // sort the quantity in descending order to give priority to the bigger frequency to look for
        sort(quantity.begin(),quantity.end(),greater<int>()); //-->important step decreasing sort was the main catch of the problem
        // using recursion
        bool ans = solve(quantity,count,0);
        return ans;
        
    }
};

int main(){
    
    return 0;
}

// NOTE THIS QUESTION CAN BE DONE WITH DP AND BITMASKING FIND AND SOLVE