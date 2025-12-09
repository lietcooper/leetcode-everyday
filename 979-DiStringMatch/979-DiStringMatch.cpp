// Last updated: 12/8/2025, 11:26:42 PM
class Solution {
public:
    vector<int> diStringMatch(string s) {
        stack<int> st;
        vector<int> res;
        int num = 0;
        for (int i = 0; i <= s.length(); ++i) {
            // st.push(num);
            if (s[i] == 'I' || i == s.length()) {
                res.push_back(num);
                while (!st.empty()) {
                    res.push_back(st.top());
                    st.pop();
                }
            } else {
                st.push(num);
            }
            num++;
        }
        return res;
    }
};