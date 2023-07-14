// 632. Smallest Range Covering Elements from K Lists
// LEETCODE: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/editorial/

/*
You have k lists of sorted integers in non-decreasing order.
Find the smallest range that includes at least one number from each of the k lists.

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

*/

#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;

    int row;

    int col;

    node(int d, int r, int c)
    {

        data = d;

        row = r;

        col = c;
    }
};

class compare
{

public:
    bool operator()(node *a, node *b)
    {

        return a->data > b->data;
    }
};

class Solution
{

public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        int mini = INT_MAX, maxi = INT_MIN;

        priority_queue<node *, vector<node *>, compare> minHeap;

        for (int i = 0; i < nums.size(); i++)
        {

            int element = nums[i][0];

            mini = min(mini, element);

            maxi = max(maxi, element);

            minHeap.push(new node(element, i, 0));
        }

        int start = mini, end = maxi;

        while (!minHeap.empty())
        {

            node *temp = minHeap.top();

            minHeap.pop();

            mini = temp->data;

            if (maxi - mini < end - start)
            {

                start = mini;

                end = maxi;
            }

            if (temp->col + 1 < nums[temp->row].size())
            { // Here is the slight change bcz size of each row is not fixed So we have passed temp->row.size() inside nums

                maxi = max(maxi, nums[temp->row][temp->col + 1]);

                minHeap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }

            else
            {

                break;
            }
        }

        return {start, end};
    }
};

int main()
{

    return 0;
}