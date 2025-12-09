// Last updated: 12/8/2025, 11:25:44 PM
class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.length(); ++i) {
            
            if (s[i] < s[i - 1] && (s[i] + '0') % 2 == (s[i - 1] + '0') % 2) {
                swap(s[i], s[i - 1]);
                break;
            }
        }
        return s;
    }
};