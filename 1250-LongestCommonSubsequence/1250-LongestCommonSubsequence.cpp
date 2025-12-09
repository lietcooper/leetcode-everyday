// Last updated: 12/8/2025, 11:26:19 PM
class Solution {
public:
    // int longestCommonSubsequence(string text1, string text2) {
    //     /**
    //         [1, 2, 3, 4]
    //         [1, 4, 1, 1]

    //         0 1 2 3 4
    //     0   0 0 0 0 0
    //     1   0 1 1 1 1
    //     2   0 1 1 1 1
    //     3   0 1 1 1 1
    //     4   0 1 2 2 2

    //     */
    //     int m = text1.size(), n = text2.size();
    //     int dp[m + 1][n + 1];
    //     memset(dp, 0, sizeof(dp));
    //     for (int i = 1; i <= m; ++i) {
    //         for (int j = 1; j <= n; ++j) {
    //             if (text1[i - 1] == text2[j - 1]) {
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }

    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size()) return longestCommonSubsequence(text2, text1);
        // vector<int> dp[2] = {vector<int>(text1.size() + 1, 0)};
        vector<vector<int>> dp(2, vector<int>(text1.size() + 1, 0));
        for (int i = 1; i <= text2.length(); ++i) {
            for (int j = 1; j <= text1.length(); ++j) {
                if (text2[i - 1] == text1[j - 1]) {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                } else {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[text2.length() % 2][text1.length()];
    }
};