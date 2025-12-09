// Last updated: 12/8/2025, 11:26:42 PM
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int j = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && popped[j] == st.top()) {
                st.pop();
                j++;
            }
        }
        return j == n;
    }
};