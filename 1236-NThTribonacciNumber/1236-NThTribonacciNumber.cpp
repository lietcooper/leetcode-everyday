// Last updated: 12/8/2025, 11:26:20 PM
class Solution {
    // int memo[38] = {0, 1, 1};
public:
    int tribonacci(int n) {
        // if (memo[n] != 0) return memo[n];
        // if (n == 0) return 0;
        // if (n == 1) return 1;
        // if (n == 2) return 1;
        // int sum = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        // memo[n] = sum;
        // return sum;
        if (n <= 1) return n;
        if (n == 2) return 1;
        int dp[3] = {0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            int sum = dp[2] + dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = sum;
        }

        return dp[2];
    }
};