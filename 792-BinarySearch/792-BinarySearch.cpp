// Last updated: 12/8/2025, 11:27:09 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l < nums.size() && nums[l] == target ? l : -1;
    }
};