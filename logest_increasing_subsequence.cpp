#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{

    vector<int> dp(nums.size());

    dp[0] = 1;

    for (int i = 1; i < nums.size(); i++)
    {

        int best = 1;

        for (int j = i - 1; j >= 0; j--)
        {

            if (nums[i] > nums[j])
            {

                best = max(dp[j] + 1, best);
            }
        }

        dp[i] = best;
    }

    int best = 0;

    for (int i = 0; i < dp.size(); i++)
        best = max(dp[i], best);

    return best;
}