/*
Leetcode Problem 860(https://leetcode.com/problems/lemonade-change/)
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills).
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, 
return true if you can provide every customer with the correct change, or false otherwise.
*/

/*
The Approach is Greedy if we have max change note then change with that
Ex:- for 20 first we look for one 10's note if we have and one 5's note 
but if we do not have 10's note then change with 3 5's notes.
*/



#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    // variables for count of notes we have of each
    int count5 = 0, count10 = 0, count20 = 0;

    for (int val : bills) {
        if (val == 5)
            count5++;
        else if (val == 10) {
            if (count5 <= 0)
                return false;
            count5--;
            count10++;
        } else if (val == 20) {
            if (count10 >= 1 && count5 >= 1) {
                count10--;
                count5--;
            } else if (count5 >= 3) {
                count5 -= 3;
            } else {
                return false;
            }
            count20++;
        }
    }

    return true;
}
};