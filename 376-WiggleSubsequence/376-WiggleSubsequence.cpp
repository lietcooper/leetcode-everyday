// Last updated: 12/8/2025, 11:29:06 PM
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int count = 1;
        int lastDif = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int nextDif = nums[i + 1] - nums[i];
            if (lastDif >= 0 && nextDif < 0 || lastDif <= 0 && nextDif > 0) {
                count++;
                lastDif = nextDif;
            }
        }
        return count;
    }
};