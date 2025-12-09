// Last updated: 12/8/2025, 11:28:22 PM
class Solution {
public:
    string reverseStr(string s, int k) {
        int l = 0;
        while (l < s.length()) {
            int i = l, r = l + k - 1;
            while (i < r) {
                while (r >= s.length()) {
                    r--;
                }
                swap(s[i++], s[r--]);
            }
            l += 2 * k;
        }
        return s;
    }
};