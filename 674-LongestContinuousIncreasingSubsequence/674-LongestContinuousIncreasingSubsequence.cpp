// Last updated: 12/8/2025, 11:28:00 PM
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // iteraive - bottom up
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};