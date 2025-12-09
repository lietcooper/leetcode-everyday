// Last updated: 12/8/2025, 11:28:50 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() <= 1) return s.length();
        int maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);
        int l = 0;
        for (int r = 0; r < s.length(); ++r) {
            freq[s[r] - 'A']++;
            if (freq[s[r] - 'A'] > maxFreq) maxFreq = freq[s[r] - 'A'];
            if ((r - l + 1 - maxFreq) > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};