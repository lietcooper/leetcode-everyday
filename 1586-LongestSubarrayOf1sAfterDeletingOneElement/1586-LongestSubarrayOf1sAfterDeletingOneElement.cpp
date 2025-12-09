// Last updated: 12/8/2025, 11:26:05 PM
class Solution {
public:
    // int longestSubarray(vector<int>& nums) {
    //     int len = 0, n = nums.size();
    //     for (int l = 0, r = 0, cnt = 0; r < nums.size(); ++r) {
    //         cnt += nums[r] == 0;
    //         if (cnt > 1) {
    //             cnt -= nums[l++] == 0;
    //         }
    //         if (cnt <= 1) len = max(len, r - l + 1 - cnt);
    //     }
    //     return min(len, n - 1);
    // }

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> x = {-1};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) x.push_back(i);
        }
        x.push_back(nums.size());
        int len = 0;
        for (int i = 0; i < x.size() - 2; ++i) {
            len = max(len, x[i + 2] - x[i] - 2);
        }
        return x.size() > 2 ? len : n - 1;
    }
};
