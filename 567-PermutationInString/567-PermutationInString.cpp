// Last updated: 12/8/2025, 11:28:19 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        unordered_set<char> seen;
        vector<int> freq(26, 0);
        for (char c : s1) {
            seen.insert(c);
            freq[c - 'a']++;
        }
        int letters = seen.size();

        for (int i = 0; i < s1.length(); ++i) {
            char c = s2[i];
            if (seen.count(c)) {
                freq[c - 'a']--;
                if (freq[c - 'a'] == 0)
                    letters--;
            }
        }
        if (letters == 0) return true;
        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (seen.count(s2[l])) {
                if (freq[s2[l] -'a'] == 0) letters++;
                freq[s2[l] - 'a']++;
            }
            l++;

            if (seen.count(s2[r])) {
                freq[s2[r] - 'a']--;
                if (freq[s2[r] - 'a'] == 0)
                    letters--;
            }

            if (letters == 0) return true;
        }
        return false;
    }
};