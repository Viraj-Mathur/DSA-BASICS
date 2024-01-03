/*
2513. Minimize the Maximum of Two Arrays
https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/
*/

/*
Intuition

When you have to minimise/maximise, there's a very high chance you can binary search on the answer. 
Here if we know a number X provides us enough numbers to fulfill both conditions, then we can simply look 
for a number smaller than X which might satisfy the condition, if not we will look for a larger number. 
Now the question is to just check if a number X satisfies the condition or not.


Approach

Now to check if a number X satisfies the condition or not, we will first calculate how many numbers are there
from 1...X that are divisible by divisor1 and divisor2. We can find out this by dividing X by divisor1, 
i.e. divisibleByD1 = X / divisor1. Then we can do the same for divisor2, i.e. divisibleByD2 = X / divisor2. 
Now the number of integers that we can add to the first array are elements1 = X - divisibleByD1 and 
number of elements we can add to the second array are elements2 = X - divisibleByD2. If you notice here there 
might be an overlap. For e.g. divisor1 = 4 and divisor2 = 6 and X = 13. Here divisibleByD1 = 3 { 4, 8, 12 } and 
divisibleByD2 = 2 { 6, 12 }. These are the elements that we cannot use in either array1 or array2. But there's 
an overlap of 12 which we can't use in either of the arrays but we've calulated it twice. To solve this, 
we will also calulate the number of elements divible by both divisor1 and divisor2 
(which is number of elements divisble by lcm(divisor1, divisor2)) (this finds out the overlapping elements). 
Now X will satisfy the condition if uniqueCnt1 <= elements1 && uniqueCnt2 <= elements2 && uniqueCnt1 + uniqueCnt2 <= X - (X / LCM).


Complexity

    Time complexity: log2(INT_MAX)log_2(INT\_MAX)log2​(INT_MAX) + log2(a+b)log_2(a + b)log2​(a+b) (to find gcd of two numbers) essentially log2(N)log_2(N)log2​(N)

    Space complexity: O(1)


*/

#include <bits/stdc++.h>

using namespace std;
class Solution {
    private:
    int gcd(int a,int b){
        if(!b) return a;
        return gcd(b,a%b);
    }
    // The base case is when b becomes zero or find recursively until base case is reached
    int lcm(long long a, long long b){
        long long temp = (a/gcd(a,b))*b;
        return temp > INT_MAX ? INT_MAX :temp;
    }
    // If temp exceeds the maximum value of an int (INT_MAX), the function returns INT_MAX;       otherwise, it returns the calculated LCM.
    public:
        int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
            int l = 1, r = INT_MAX,LCM = lcm(divisor1,divisor2);
            while(l<=r){
                int mid = l+(r-l)/2;
                int a = mid/divisor1, b = mid/divisor2;
                if(uniqueCnt1 <=mid-a && uniqueCnt2 <= mid-b && uniqueCnt1 + uniqueCnt2 <=(mid-(mid/LCM))){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            } 
            return l;
        }
    };

int main(){
    
    return 0;
}