/*
2220. Minimum Bit Flips to Convert Number
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

*/

#include <bits/stdc++.h>

using namespace std;


// Hint : the only operator that works on different bits is XOR 

// Approach : XOR start and goal and the number you will get has exactly number of "1(set)" bits that are needed to be flipped

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int number = start^goal;
        int count = 0;
        while(number!=0){
            number = number &(number-1);
            count++;
        }
        return count;
        
    }
};

int main(){
    
    return 0;
}