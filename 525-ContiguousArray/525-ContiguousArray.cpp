// Last updated: 12/8/2025, 11:28:27 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count; // count, index
        count[0] =  -1;
        int sum = 0;
        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) sum++;
            else sum--;
            if (count.find(sum) != count.end()) {
                length = max(length, i - count[sum]);
            } else {
                count[sum] = i;
            }
        }
        

        return length;
    }
};