// 29. Divide Two Integers : Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.




#include <bits/stdc++.h>

using namespace std;

// Approach : we repeatedly subtract multiples of divisor from dividend until dividend becomes less than divisor. - substract divisor from divident in powers of divisor - find biggest number possible(in terms of divisor * 2^0,1..) and subtract it
/*
Dividing positive numbers: 10 and 3.
Bitwise Subtraction:
Start with 3 and double it: 3, 6 (3 << 1).
6 is less than 10, so subtract 6 from 10: 10 - 6 = 4.
We subtracted 6 once, so we add 2 (1 << 1) to the quotient.
Now, work with the remaining 4.
Start with 3 again and double it: 3.
3 is less than 4, so subtract 3 from 4: 4 - 3 = 1.
We subtracted 3 once, so we add 1 to the quotient.
Now, the remaining value is 1, which is less than 3, so we stop.
*/

// TC : (log_2 n)^2 and SC : O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        
        bool sign = 1;

        // to determine the sign of result
        if((dividend <= 0 && divisor > 0) || (dividend >= 0 && divisor < 0)) {
            sign = 0;
        }

        // Convert both dividend and divisor to positive integers
        long n = abs(dividend);
        long d = abs(divisor);
        divisor = abs(divisor);

        long ans = 0;//quotient

        // performing division
        while(n >= d) {
            int count = 0;
            // while (n >= (d * 2^(cnt+1))) as n/2 = n>>1 and 2^n is 1<<n
            while(n >= (d << (count + 1))) {
                count++;
            }
            ans += 1 << count;
            n -= d << count;
        }

        // handling the overflow cases because of logical shifts limit
        if(ans == (1 << 31) && sign == 1) return INT_MAX;
        if(ans == (1 << 31) && sign == 0) return INT_MIN;
        return sign ? ans : -ans;
    }
};


int main(){
    
    return 0;
}