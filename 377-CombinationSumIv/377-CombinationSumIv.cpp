// Last updated: 12/8/2025, 11:29:03 PM
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // similar to coin change II
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        // for (int num : nums) {
        //     for (int i = num; i <= target; ++i) {
        //         // if i == target && dp[i - num] != 0
        //         dp[i] = dp[i] + dp[i - num];
        //         // combinations
        //     }
        // }
        for (int i = 0; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) dp[i] += dp[i - num];
            }
        }
        return dp[target] <= INT_MAX ? dp[target] : 0;

        // if negative number exists, there could be never ending loop
        // e.g. [1, -1, 1, -1, 1, ...]
    }
};