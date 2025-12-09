// Last updated: 12/8/2025, 11:26:31 PM
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        auto cmp = [](int a, int b) {
            return abs(a) > abs(b);
        };

        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        
        while (k--) {
            nums[nums.size() - 1] *= -1;
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};