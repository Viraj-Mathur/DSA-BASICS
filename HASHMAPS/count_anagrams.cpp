#include <bits/stdc++.h>

using namespace std;



// Formula used for finding a distinct anagram for single word : w = [len(word)]!/([f(a)]! * [f(b)]!* ..) where a and b are the repetitive words(frequency)

/*
But the problem here is that our answer can be a large number, so we have to return modulo 1e9+7.
Well, that's not a big problem as we can just use cnt % mod for our answer, 
but here we have to use modulo for every computation as numbers can be very large. 

In our formula: a= n!, b = (freq[i]! * freq[i+1]!... freq[n-1]! is (a / b)%mod.

But (a / b) % mod != (a% mod) / (b% mod). So here we use Modular Multiplicative Inverse, 
i.e (A / B) % mod = A * ( B ^ -1 ) % mod. Now ( B ^ -1 ) % mod we can get by Fermat's little theorem, whose end conclusion is (b ^ -1) % mod = b ^ (mod -2) if mod is prime.

now mod is 1e9+7. We can't get b ^ (mod -2) using for loop which is O(n). for this we can use Binary Exponentiation which allows us to calculate  a ^ n in O(log(n)).

*/

class Solution {
private:
    vector<long long> fact;
    int mod = 1e9 + 7;

    void factorial(){
        fact[0] = 1;
        fact[1] = 1;

        for(int i=2;i<=1e5;i++){
            fact[i] = (fact[i-1]%mod * i%mod)%mod;
        }
    }

// binary exponentiation algorithm :  efficient way to compute a^b in 𝑂(log𝑏)

    long long binpow(long long a, long long b){
        long long ans = 1;
        while(b > 0){
            if(b%2 == 1){
                ans = ans*a % mod;
            }
            a = a*a % mod;
            b = b/2;
        }
        return ans;
    }

    long long inverse(long long num){
        return binpow(num, mod-2);
    }





public:
    int countAnagrams(string s) {

        fact.resize(1e5+1);
        factorial();

        long long ans = 1, count = 0;
        unordered_map<char,int>freq;
        s += ' ';
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                long long val = fact[count];
                for(auto it:freq){
                    val = val * inverse(fact[it.second]) % mod;
                }
                ans = ans * val % mod;
                count = 0;
                freq.clear();
            }
            else{
                count++;
                freq[s[i]]++;
            }
        }

        return ans;


        
    }

    
};


/*
Let's say we want to compute \( a = 3 \), \( b = 13 \), and \( mod = 1000000007 \).

1. Convert `b` (13) to binary: `1101`.
2. Perform the loop:
   - Start with `ans = 1`, `a = 3`, and `b = 13`.
   - Since `b` is odd, multiply `ans` by `a` (ans = 3). Then square `a` (a = 9) and halve `b` (b = 6).
   - `b = 6` is even, so just square `a` (a = 81) and halve `b` (b = 3).
   - `b = 3` is odd, so multiply `ans` by `a` (ans = 243). Then square `a` (a = 6561) and halve `b` (b = 1).
   - `b = 1` is odd, so multiply `ans` by `a` (ans = 1594323). Then square `a` (a = 43046721) and halve `b` (b = 0).
   - The loop ends, and `ans` (1594323) is returned.

Thus, \( 3^{13} \mod 1000000007 = 1594323 \).



https://cp-algorithms.com/algebra/module-inverse.html
https://cp-algorithms.com/algebra/binary-exp.html
*/

int main(){
    
    return 0;
}