// Last updated: 12/8/2025, 11:26:37 PM
class Solution {
public:
    int fib(int n) {
        int dp[2] = {0, 1};
        for (int i = 2; i <= n; ++i) {
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return n < 1 ? dp[0] : dp[1];
    }
};