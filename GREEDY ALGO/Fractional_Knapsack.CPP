// Problem Statement: The weight of N items and their corresponding values are given. 
// We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

// Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.

// Space Complexity: O(1), no additional data structure has been used.
#include <bits/stdc++.h>

using namespace std;

struct Items{
    int value;
    int weight;
};

class Solution{
    public:
        bool static comp(Items a, Items b){ // comparator
            double f1 = (double) a.value/ (double) a.weight;
            double f2 = (double) b.value/ (double) b.weight;
            return f1>f2;
        }

    // for fractional weights
    double FractionalKnapsack(int W, Items arr[], int n){
        sort(arr,arr+n,comp); // sort according to value per weight in descending order
    int currWeight =0;
    double finalValue = 0.0;

    for(int i=0;i<n;i++){
        if(currWeight+arr[i].weight <=W){ //if the weights completely fits in the knapsack
            currWeight +=arr[i].weight; //add to current weight
            finalValue +=arr[i].value; //add to current value
        }
        else{
            // use fractional weights
            int  remain = W-currWeight;
            finalValue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
        }
    }

    return finalValue;
    }

};

int main(){
   int n = 3, weight = 50;
   Items arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.FractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}