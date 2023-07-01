/*
Find minimum number of coins
Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply 
of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
what is the minimum number of coins and/or notes needed to make the change.
*/

/*
Approach:
 We will keep a pointer at the end of the array i. Now while(V >= coins[i]) we will reduce V by coins[i] and add it to the ans array.

We will also ignore the coins which are greater than V and the coins which are less than V.
 We consider them and reduce the value of V by coins[I].
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int value;
    cout<<"Enter value: "<<endl;
    cin>>value;
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    for (int i=n-1;i>=0;i--){
        while(value>=coins[i]){
            value -=coins[i];
            ans.push_back(coins[i]);
        }
    }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

    return 0;
}