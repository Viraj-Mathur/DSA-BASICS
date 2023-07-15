// PROGRAM TO FIND THE NUMBER OCCURING MAXIMUM TIMES IN THE GIVEN INPUT

#include <bits/stdc++.h>

using namespace std;

{
    unordered_map<int,int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq = max( maxFreq, count[arr[i]] );
    }
    // The function then iterates through the input vector arr, 
    // updating the frequency count for each element in the count map and updating the value of maxFreq 
    // if a higher frequency is found.

    for(int i=0;i<arr.size(); i++) {
        if(maxFreq == count[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }
    // After counting the frequencies, it iterates through the vector again to find the first element with a frequency equal 
    // to maxFreq. It assigns that element to maxAns and breaks out of the loop.

    return maxAns;

}

int main(){
    
    return 0;
}