// Last updated: 12/8/2025, 11:29:11 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int hash_set[1001] = {0};
        for (const auto& num : nums1) {
            hash_set[num]++;
        }

        for (const auto& num : nums2) {
            if (hash_set[num]) {
                result.push_back(num);
                hash_set[num] = 0;
            }
        }
        return result;
    }
};