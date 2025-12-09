// Last updated: 12/8/2025, 11:26:19 PM
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;  // store the index for the position of current max sum
        vector<int> dp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            
            dp[i] = (!q.empty() ? dp[q.front()] : 0) + nums[i];
            while (!q.empty() && dp[q.back()] < dp[i]) {
                q.pop_back();
            }
            if (dp[i] >= 0) {
                q.push_back(i);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};