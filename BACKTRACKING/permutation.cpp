#include <bits/stdc++.h>

using namespace std;

void printPermutation(string &str,int i){
    // base case
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }

    // swapping with index
    for(int j=i;j<str.length();j++){
        // swap
        swap(str[i],str[j]);
        // printing permutations recursively
        printPermutation(str,i+1);
        // backtracking to undo swapping because strings are passes with reference
        swap(str[i],str[j]);
    }
}

int main(){

    string s = "abcd";
    int i=0;
    printPermutation(s,i);
    
    return 0;
}