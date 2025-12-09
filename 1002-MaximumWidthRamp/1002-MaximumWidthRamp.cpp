// Last updated: 12/8/2025, 11:26:40 PM
// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         stack<int> st;
//         st.push(0);
//         int ramp = 0;
//         for (int i = 1; i < nums.size(); ++i) {
//             if (nums[i] < nums[st.top()]) {
//                 st.push(i);
//             }
//         }

//         // queue<int> q;
//         // for (int i = nums.size() - 1; i >= 0; --i) {
//         //     if (nums[i] >= nums[st.top()]) {
//         //         q.push(i);
//         //     }
//         // }

//         // while (!st.empty() && !q.empty() && st.top() <= q.front()) {
//         //     ramp = max(ramp, q.front() - st.top());
//         //     st.pop();
//         //     while (!q.empty() && !st.empty() && nums[st.top()] > nums[q.front()]) {
//         //         q.pop();
//         //     }
//         // }
//         int i = nums.size() - 1;
//         while (!st.empty()) {
//             if (nums[i] >= nums[st.top()]) {
//                 ramp = max(ramp, i - st.top());
//                 st.pop();
//             } else i--;
//         }

//         return ramp;
//     }
// };

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n, 0);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int l = 0, r = 0;
        int ramp = 0;
        while (r < n) {
            while (l < r && nums[l] > rightMax[r]) {
                l++;
            }
            ramp = max(ramp, r - l);
            r++;
        }
        return ramp;
    }
};