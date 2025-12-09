// Last updated: 12/8/2025, 11:28:32 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        deque<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                res[st.back()] = nums[i];
                st.pop_back();
            }
            st.push_back(i);
        }

        // int largest = st.front();
        // st.pop_front();
        // while (!st.empty()) {
        //     int i = st.front();
        //     st.pop_front();
        //     res[i] = nums[i] == nums[largest] ? -1 : nums[largest];
        // }
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                res[st.back()] = nums[i];
                st.pop_back();
            }
        }
        return res;
    }
};