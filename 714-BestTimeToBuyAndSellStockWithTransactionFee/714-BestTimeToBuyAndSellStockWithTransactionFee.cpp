// Last updated: 12/8/2025, 11:27:52 PM
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp0 = -prices[0];
        int dp1 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp0 = max(dp0, dp1 - prices[i]);
            dp1 = max(dp1, dp0 + prices[i] - fee);
        }
        return dp1;
    }
};