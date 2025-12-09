// Last updated: 12/8/2025, 11:29:04 PM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (s.length() > t.length()) return false;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
            if (i >= s.length()) return true;
        }
        return false;
    }
};