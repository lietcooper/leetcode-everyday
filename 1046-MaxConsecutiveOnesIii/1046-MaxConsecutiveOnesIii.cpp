// Last updated: 12/8/2025, 11:26:32 PM
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int zeros = 0;
//         int max_len = 0;
//         int i = 0, j = 0;
//         while (j < nums.size()) {
//             if (nums[j++] == 0) {
//                 zeros++;
//             }
//             while (zeros > k) {
//                 if (nums[i++] == 0) {
//                     zeros--;
//                 }
//             }
//             max_len = max(max_len, j - i);
//         }

//         return max_len;
//     }
// };

class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     int left = 0;
    //     int curr = 0;
    //     int ans = 0;
    //     int n = nums.size();
    //     for (int right = 0; right < n; right++) {
    //         if (nums[right] == 0) {
    //             curr++;
    //         }

    //         while (curr > k) {
    //             if (nums[left] == 0) {
    //                 curr--;
    //             }

    //             left++;
    //         }

    //         ans = max(ans, right - left + 1);
    //     }
    //     return ans;
    // }

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> x = {-1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) x.push_back(i);
        }
        x.push_back(n);

        if (k >= x.size() - 2) return n;
        int len = 0;
        for (int i = 0; i < x.size() - k - 1; ++i) {
            len = max(len, x[i + k + 1] - x[i] - 1);
        }
        return len;
    }
};