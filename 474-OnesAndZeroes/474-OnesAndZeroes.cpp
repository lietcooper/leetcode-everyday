// Last updated: 12/8/2025, 11:28:37 PM
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& str : strs) {
            int zeros = 0;
            int ones = 0;
            for (char c : str) {
                if (c == '1') ones++;
                else if (c == '0') zeros++;
            }
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};