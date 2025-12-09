// Last updated: 12/8/2025, 11:28:01 PM
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else open--;

            if (s[s.length() - 1 - i] == ')' || s[s.length() - 1 - i] == '*') {
                close++;
            } else close--;

            if (open < 0 || close < 0) {
                return false;
            }
        }
        return true;
    }
};