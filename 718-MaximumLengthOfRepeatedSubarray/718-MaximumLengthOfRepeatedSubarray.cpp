// Last updated: 12/8/2025, 11:27:58 PM
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // optimized space
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = n; j > 0; --j) {
                if (nums1[i] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;
                }
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};