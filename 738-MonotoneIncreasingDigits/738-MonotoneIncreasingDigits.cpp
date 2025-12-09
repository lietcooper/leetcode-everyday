// Last updated: 12/8/2025, 11:27:50 PM
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        
        int start = 0;  // if s[i] == s[i + 1] == s[i + 2] == ... , set start as the first.
        int end = -1;   // if s[i] > s[i + 1], ends at start.
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] == s[i]) {
                continue;
            } else if (s[i - 1] < s[i]) {
                start = i;
            } else {
                end = start;
                break;
            }
        }
        // if break, build the new integer
        if (end != -1) {
            int ans = 0;
            // normally build before the end;
            for (int i = 0; i < end; ++i) {
                ans = ans * 10 + (s[i] - '0');
            }
            // decreast s[end] by 1
            ans = ans * 10 + (s[end] - '0' - 1);
            end++;
            // set the remaining digits to 9
            while (end < s.length()) {
                ans = ans * 10 + 9;
                end++;
            }
            return ans;
        }
        // if not break, return original integer
        return n;
    }
};