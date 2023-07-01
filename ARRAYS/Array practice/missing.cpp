#include<iostream>

using namespace std;

// Given an array with all integers between 1 and 100 except for one, find the missing number

// find total sum of 1-100 then find sum of array than subtract or use or operator

int MissingNo(int a[], int n) {
  int i, total;
  total = (n + 1) * (n + 2) / 2;
  for (i = 0; i < n; i++)
    total -= a[i];
  return total;
}

/*Algorithm for XOR:

Create two variables a1= 0 and a2 = 0
Iterate from 1 to n with i as the counter.
For every index i update a1 as a1 = a1 ^ i
Now iterate over the array from start to end.
For every index i update a2 as a2 = a2 ^ arr[i]
Print the missing number as a1 ^ a2.
*/

int MissingNo(int arr[], int n) {
  int x1 = arr[0];
  int x2 = 1;

  for (int i = 1; i < n; i++)
    x1 = x1 ^ arr[i];

  for (int i = 2; i <= n + 1; i++)
    x2 = x2 ^ i;

  return (x1 ^ x2);
}