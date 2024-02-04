// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/


#include <bits/stdc++.h>

using namespace std;

class Solution { 

    private:

    int findMax(vector<int> &piles){
        int maximum = 0;
        for(int i=0;i<piles.size();i++) {
            maximum = max(maximum, piles[i]);
        }
        return maximum;
    }

    // function that calculate total hours
    long long calculateTotalHours(vector<int> &piles, int hourly){

        long long total = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            total += ceil((double)(piles[i]) /(double)(hourly)); // as we need higher bound value --> for 2.5 hrs it will considered as 3hrs
        }
        return total;
    }
    public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, high = findMax(piles);   //range for binary search would be till maximum value of array as monkey won't eat greater than that value
        while(l<=high){
            int mid = l + (high - l) / 2;
            long long total = calculateTotalHours(piles,mid);
            if(total <=h){
                high = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l; // as minimum time is required
    }
};

int main(){
    
    return 0;
}