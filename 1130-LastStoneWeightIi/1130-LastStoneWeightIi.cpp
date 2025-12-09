// Last updated: 12/8/2025, 11:26:21 PM
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i : stones) {
            sum += i;
        }
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = dp[j] || dp[j - stones[i]];
            }
        }
        int subSum = 0;
        for (int i = target; i >= 0; --i) {
            if (dp[i]) return sum - i - i;
        }

        return 0;
    }
};