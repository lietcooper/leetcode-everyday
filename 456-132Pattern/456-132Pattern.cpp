// Last updated: 12/8/2025, 11:28:41 PM
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         if (nums.size() < 3) return false;
//         vector<int> left(nums.size());
//         left[0] = nums[0];
//         for (int i = 1; i < nums.size(); ++i) {
//             left[i] = min(left[i - 1], nums[i]);
//         }

//         stack<int> st;
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             if (nums[i] == left[i]) {  // if is the min number in the left, skip
//                 continue;
//             }
//             while (!st.empty() && st.top() <= left[i]) {
//                 st.pop();  // keep the values in the stack larger than min values in the left
//             }
//             if (!st.empty() && nums[i] > st.top()) {
//                 return true;  // now we have ensured that nums[i] is larger than min left and min left smaller than st.top(), we only need nums[i] larger than st.top()
//             }
//             st.push(nums[i]);
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }

        for (size_t j = nums.size() - 1, k = nums.size(); j > 0; j--) {
            if (nums[j] <= min_array[j]) {
                continue;
            }
            while (k < nums.size() and nums[k] <= min_array[j]) {
                k++;
            }
            if (k < nums.size() and nums[k] < nums[j]) {
                return true;
            }
            nums[--k] = nums[j];
        }
        return false;
    }
};