// Last updated: 12/8/2025, 11:27:44 PM
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size() + 1);
        // dp[0] = 0;
        // dp[1] = 0;
        // for (int i = 2; i <= cost.size(); ++i) {
        //     dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
        // }
        // return dp[cost.size()];
        int dp[2] = {0};
        for (int i = 2; i <= cost.size(); ++i) {
            int minCost = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = minCost;
        }
        return dp[1];
    }
};