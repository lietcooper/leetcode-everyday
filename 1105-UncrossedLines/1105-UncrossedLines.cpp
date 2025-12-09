// Last updated: 12/8/2025, 11:26:28 PM
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // bottom up
        // if == : dp[i][j] = dp[i - 1][j - 1] + 1
        // else: dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                } else {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[m % 2][n];
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return dp(nums1, m - 1, nums2, n - 1, memo);
    }

    // int dp(vector<int>& nums1, int i, vector<int>& nums2, int j, vector<vector<int>>& memo) {
    //     if (i < 0 || j < 0) return 0;
    //     if (memo[i][j] != -1) return memo[i][j];
    //     int res = 0;
    //     if (nums1[i] == nums2[j]) {
    //         res = dp(nums1, i - 1, nums2, j - 1, memo) + 1;
    //     } else {
    //         res = max(dp(nums1, i, nums2, j - 1, memo), dp(nums1, i - 1, nums2, j, memo));
    //     }
    //     memo[i][j] = res;
    //     return res;
    // }
};