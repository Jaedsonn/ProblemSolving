#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>

using namespace std;

int ans = 0;
int last = -1;

int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;

        for(int i = 1; i < nums.size(); i++){
            int best = 1;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j]){
                    best = max(dp[i-1]+1, best);
                }
            }

            dp[i] = best;
        }

        return dp[nums.size() - 1];
}