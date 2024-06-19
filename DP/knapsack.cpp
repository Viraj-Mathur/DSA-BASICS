#include <bits/stdc++.h>

using namespace std;

// Approach 1 : using recursion

// index - last element index

int solveRec(int weight[], int value[], int index, int capacity){

    // base case - only one item present
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    // we have to option either to include an object or 
    // exclude it on the basis of the capacity so recursive call is given accordingly

    // include case
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveRec(weight, value, index-1, capacity - weight[index]);
    }
    // exclude call
    int exclude = 0 + solveRec(weight, value, index-1, capacity);

    int ans = max(include,exclude); //choose the max of include and exclude
    return ans;
}

// solve using dp memoisation -> 2D dp as capacity and index is changing

int solveMemo(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp){
    // base case - only one item present
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    // if answer already exists
    if(dp[index][capacity]!= -1){
        return dp[index][capacity];
    }



    // we have to option either to include an object or 
    // exclude it on the basis of the capacity so recursive call is given accordingly

    // include case
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveMemo(weight, value, index-1, capacity - weight[index],dp);
    }
    // exclude call
    int exclude = 0 + solveMemo(weight, value, index-1, capacity,dp);

    dp[index][capacity] = max(include,exclude); //choose the max of include and exclude
    return  dp[index][capacity];


}

// solve using bottopUP tabulation approach

int solveTab(int weight[], int value[], int n, int capacity){
    // Step 1 : Create dp array
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // Step 2 : Observe base case of top down
    // We have to run a loop for 0th index
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    // Replace n with index and capacity with wt
    for (int index = 1; index < n; index++)
    {
        for (int wt = weight[0]; wt <= capacity; wt++)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + dp[index-1][wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + dp[index-1][wt];
            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n-1][capacity];
}


// space optimised approach

int space(int weight[], int value[], int n, int capacity){
    // Step 1 : Create 2 dp 1D array
    vector<int>curr(capacity+1,0);
    vector<int>prev(capacity+1,0);

    // Step 2 : 
    // We have to run a loop for 0th index
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    // Replace n with index and capacity with wt
    for (int index = 1; index < n; index++)
    {
        for (int wt = weight[0]; wt <= capacity; wt++)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + prev[wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + prev[wt];
            curr[wt] = max(include, exclude);
        }

        // Shifting logic (we can forget this)
        prev = curr;
    }
    return prev[capacity];
}

// space optimised 2 more optimisation
int space2(int weight[], int value[], int n, int capacity){
    // Step 1 : Create a dp 1D array
    vector<int>curr(capacity+1,0);
   

    // Step 2 : 
    // We have to run a loop for 0th index
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    // Replace n with index and capacity with wt
    for (int index = 1; index < n; index++)
    {
        for (int wt = weight[0]; wt <= capacity; wt++)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + curr[wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + curr[wt];
            curr[wt] = max(include, exclude);
        }

        
    }
    return curr[capacity];
}

int main(){

    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // // Recursive code
    // int ans = solveRec(weight,value,n-1,capacity);

    // // Top down approach
    // // Step 1 : Create dp array
    // // Here we can stuck (Initialization part)
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = solveMemo(weight, value, n - 1, capacity, dp);

    // Bottom up approach
    int ans = solveTab(weight,value,n,capacity);



    cout << "Maximum profit = " << ans<<endl;
    return 0;

     // Space optimization - 1
    int ans1 = space(weight,value,n,capacity);

    // Space optimization - 2
    int ans2 = space2(weight,value,n,capacity);
    cout << "Maximum profit = " << ans1;
    cout << "Maximum profit = " << ans2;

    
    
}