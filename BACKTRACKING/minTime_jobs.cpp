/*
1723. Find Minimum Time to Finish All Jobs

You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.

Example 1:

Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
Example 2:

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
*/


#include <bits/stdc++.h>

using namespace std;

// general Approach gives TLE - Time Complexity:O(k^n+1) SC: O(n+k); 


class Solution {
    private:
    void solve(int i, int k,int n,vector<int>& jobs, vector<int>& work, int ans, int &res){
        // base case
        if(i==n){
            ans = *max_element(work.begin(),work.end()); //built in function to find the maximum element in the array
            res = min(res,ans);
            return;
        }

        for(int j=0;j<k;j++){
            // action
            work[j] += jobs[i]; //assigning ith job to jth wokers
            // recursive call
            solve(i+1,k,n,jobs,work,ans,res);

            // undo assignment - backtrack
            work[j] -= jobs[i];
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k){
        // sorting the jobs array in decresing order
        // if array size of jobs = to workers then 1st element of the array will be the answer
        sort(jobs.begin(), jobs.end(), greater<int>());

        int n = jobs.size();

        if(n==k){
            return jobs[0];
        }

        vector<int> work(k,0); //creating a vector for assigning jobs to worker
        int assignmentAns = 0;//assignment will be all the maxinmum answers computed by recursion
        int finalAns = INT_MAX; //as we have to return a minimum number of computed assignmentAns
        int index = 0;

        solve(index,k,n,jobs,work,assignmentAns,finalAns);
        return finalAns;
        
    }
};

// optimisation - remove the mirror repeating recursions and and also if we found the answer which is smaller then other no need to compute larger answer

class Solution {
    private:
    void solve(int i, int k,int n,vector<int>& jobs, vector<int>& work, int ans, int &res){
        // base case
        if(i==n){
            ans = *max_element(work.begin(),work.end()); //built in function to find the maximum element in the array
            res = min(res,ans);
            return;
        }

        // optimisation 1
        if(ans > res){
            return;
        }

        


        for(int j=0;j<k;j++){

            // optimsation 2 - mirror
            if(j>0 && work[j] == work[j-1]){
                continue;
        }
            // action
            work[j] += jobs[i]; //assigning ith job to jth wokers
            // recursive call
            solve(i+1,k,n,jobs,work,ans,res);

            // undo assignment - backtrack
            work[j] -= jobs[i];
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k){
        // sorting the jobs array in decresing order
        // if array size of jobs = to workers then 1st element of the array will be the answer
        sort(jobs.begin(), jobs.end(), greater<int>());

        int n = jobs.size();

        if(n==k){
            return jobs[0];
        }

        vector<int> work(k,0); //creating a vector for assigning jobs to worker
        int assignmentAns = 0;//assignment will be all the maxinmum answers computed by recursion
        int finalAns = INT_MAX; //as we have to return a minimum number of computed assignmentAns
        int index = 0;

        solve(index,k,n,jobs,work,assignmentAns,finalAns);
        return finalAns;
        
    }
};

// Time Complexity:O(2^n*k) SC: O(n+k); 



int main(){
    
    return 0;
}