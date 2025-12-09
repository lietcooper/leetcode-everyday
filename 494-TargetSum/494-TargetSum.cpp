// Last updated: 12/8/2025, 11:28:38 PM
class Solution {
public:
    int total = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(2 * total + 1, numeric_limits<int>::min()));
        return calculate(nums, 0, 0, target, memo);
    }

    int calculate(const vector<int>& nums, int i, int cur, int target, vector<vector<int>>& memo) {
        if (i == nums.size()) {
            if (cur == target) {
                return 1;
            } else {
                return 0;
            }
        }
        if (memo[i][cur + total] != numeric_limits<int>::min()) {
            return memo[i][cur + total];
        }

        int add = calculate(nums, i + 1, cur + nums[i], target, memo);
        int sub = calculate(nums, i + 1, cur - nums[i], target, memo);
        memo[i][cur + total] = add + sub;
        return add + sub;
    }
};