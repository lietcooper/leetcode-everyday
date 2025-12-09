// Last updated: 12/8/2025, 11:28:21 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int total = 0, count = 0;;
        prefix[0] = 1;
        for (int num : nums) {
            total += num;
            if (k != 0)
                prefix[total] += 1;
            if (prefix.count(total - k)) {
                count += prefix[total - k];
            }

            if (k == 0)
                prefix[total] += 1;
        }
        return count;
    }
};