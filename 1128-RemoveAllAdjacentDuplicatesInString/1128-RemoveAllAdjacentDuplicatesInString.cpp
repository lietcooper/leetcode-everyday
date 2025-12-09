// Last updated: 12/8/2025, 11:26:23 PM
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        string res = s.substr(0, 1);
        for (int i = 1; i < s.size(); i++) {
            if (!st.empty() && s[i] == st.top()) {
                st.pop();
                res.resize(res.size() - 1);
            } else {
                st.push(s[i]);
                res += s[i];
            }
        }
        return res;
    }
};