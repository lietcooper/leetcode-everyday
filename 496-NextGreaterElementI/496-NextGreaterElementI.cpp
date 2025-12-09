// Last updated: 12/8/2025, 11:28:33 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> next(n, -1);
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i) {
            map[nums2[i]] = i;
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            if (next[map[nums1[i]]] == -1) {
                nums1[i] = -1;
            } else {
                nums1[i] = nums2[next[map[nums1[i]]]];
            }
        }
        return nums1;
    }
};