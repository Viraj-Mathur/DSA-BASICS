#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    // approach 1 memoisation
    int memo(vector<int> &nums1, vector<int> &nums2, int index, int swapped, vector<vector<int>> &dp)
    {
        if (index >= nums1.size())
        {
            return 0;
        }

        // if solution already solved
        if (dp[index][swapped] != -1)
        {
            return dp[index][swapped];
        }

        // initializing previous elements of both the arrays for comparison
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        int ans = INT_MAX; // initializing answer with infinity to replace it with minimum

        // if element at the index were swapped then we need to swap our prev1 and prev2, logically.
        if (swapped)
        {
            swap(prev1, prev2);
        }

        // checking if swapping is needed for elements at 'index'
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            // as element is increasing no need to swap
            ans = min(ans, memo(nums1, nums2, index + 1, 0, dp));
        }
        // case for swapping
        if (nums1[index] > prev2 && nums2[index] > prev1)
        {
            // swap and increase the count +1
            ans = min(ans, 1 + memo(nums1, nums2, index + 1, 1, dp));
        }

        return dp[index][swapped] = ans;
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // we put -1 at the start of each array to make the comparison easy
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // this variable will show if the last index was swapped or not (if swapped 1, else 0);
        int swapped = 0, index = 1;
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));

        return memo(nums1, nums2, index, swapped, dp);
    }
};

// Approach 2: tabulation

class Solution2
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // we put some -1 at the start of each array to make comparison easy.
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // initialising dp array

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int index = n; index >= 1; index--)
        {
            for (int swapped = 0; swapped < 2; swapped++)
            {
                int prev1 = nums1[index - 1];
                int prev2 = nums1[index - 1];

                int ans = INT_MAX;

                if (swapped)
                {
                    swap(prev1, prev2);
                }

                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    // no need of swap
                    ans = min(ans, dp[index + 1][0]);
                }
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    // swap, count +1;
                    ans = min(ans, 1 + dp[index + 1][1]);
                }
                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};
    cout << "Minimum swaps needed: " << sol.minSwap(nums1, nums2) << endl;

    // Example 2
    vector<int> nums3 = {0, 3, 5, 8, 9};
    vector<int> nums4 = {2, 1, 4, 6, 9};
    cout << "Minimum swaps needed: " << sol.minSwap(nums3, nums4) << endl;

    return 0;
}
