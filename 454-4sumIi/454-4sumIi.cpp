// Last updated: 12/8/2025, 11:28:44 PM
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<vector<int>> lists = {nums1, nums2, nums3, nums4};
        int k = lists.size();

        auto countSum = [&](int start, int end) {
            unordered_map<int, int> cnt;
            cnt[0] = 1;
            for (int i = start; i < end; ++i) {
                unordered_map<int, int> temp;
                for (int total : lists[i]) {
                    for (const auto& [key, value] : cnt) {
                        temp[total + key] += value;
                    }
                }
                cnt = temp;
            }
            return cnt;
        };

        auto left = countSum(0, k / 2);
        auto right = countSum(k / 2, k);
        int count = 0;
        for (const auto& [key, val] : left) {
            if (right.find(-key) != right.end()) {
                count += val * right[-key];
            }
        }
        return count;

    }
};