/*
2933. High-Access Employees
https://leetcode.com/problems/high-access-employees/description/
*/

#include <bits/stdc++.h>

using namespace std;

// A person’s name should be in the answer list if there are 2 access times in his/her access time list (after sorting), where the index difference is at least 2 and the time difference is strictly less than 60 minutes.
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<long>>mp;
        vector<string>ans;

        for(int i=0;i<access_times.size();i++){
            string name = access_times[i][0];
            long time = stol(access_times[i][1]);
            mp[name].push_back(time);  //storing the acces time in the map
        }

        for(auto x:mp){
            if(x.second.size()>=3){ //for 3 or more acces time
                vector<long>temp;
                sort(x.second.begin(), x.second.end());
                for(auto y:x.second){
                    temp.push_back(y);
                }
                for(int i=0;i<temp.size()-2;i++){
                // temp.size() - 2: to ensure here are at least three elements remaining in the vector to check
                    int start = temp[i];
                    int target = start;
                    target = target+100;
                    // target+100 sets a threshold for identifying access times that are within 60 minutes of each other 
                    // 
                    if(temp[i+2]<target && temp[i+2]<=2359){
                        ans.push_back(x.first);
                        break;
                    }
                }

            }
        }
        return ans;
        
    }
};

// PS :stol is a standard library function that converts a string to a long integer. 
// Time Representation:Hours are in the thousands place, minutes in the hundreds place.
// Adding 100 to a time value effectively creates a 60-minute window for comparison.

    // Example: 1430 + 100 = 1530 (2:30 PM to 3:30 PM)

int main(){
    
    return 0;
}