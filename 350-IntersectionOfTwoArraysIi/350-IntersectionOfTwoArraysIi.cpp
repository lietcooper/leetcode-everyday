// Last updated: 12/8/2025, 11:29:10 PM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int record[1001] = {0};
        for (int i : nums1) {
            record[i]++;
        }

        for (int i : nums2) {
            if (record[i]-- > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};