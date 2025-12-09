// Last updated: 12/8/2025, 11:26:15 PM
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        deque<int> deq;
        int open = 0, close = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                open++;
                deq.push_back(i);
            } else if (s[i] == ')') {
                // if close < open, there are more opening in the deque, pop
                // if close >= open, there are no more opening in the deque, this closing is to be deleted
                if (close < open) {
                    deq.pop_back();
                    close++;
                } else {
                    deq.push_back(i);
                }

            }
        }

        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (!deq.empty() && i == deq.front()) {
                deq.pop_front();
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};