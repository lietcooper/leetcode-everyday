// Last updated: 12/8/2025, 11:25:58 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long sum = 0;
        int freq = 0;
        int j = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if ((long)nums[i] * (i - j + 1) - sum > k) {
                sum -= nums[j];
                j++;
            }
            freq = max(freq, i - j + 1);
        }
        return freq;
    }
};