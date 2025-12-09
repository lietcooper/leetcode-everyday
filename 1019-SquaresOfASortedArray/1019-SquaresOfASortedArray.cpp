// Last updated: 12/8/2025, 11:26:36 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());
        for (int i = right; i >= 0; i--) {
            if (abs(nums[right]) > abs(nums[left])) {
                ans[i] = (nums[right] * nums[right]);
                right--;
            } else {
                ans[i] = (nums[left] * nums[left]);
                left++;
            }
        }

        return ans;
    }
};