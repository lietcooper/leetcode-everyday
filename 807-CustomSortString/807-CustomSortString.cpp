// Last updated: 12/8/2025, 11:27:05 PM
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        string ans = "";
        for (char c : order) {
            while (freq[c]-- > 0) {
                ans += c;
            }
        }

        for (auto& [ch, count] : freq) {
            while (freq[ch]-- > 0) {
                ans += ch;
            }
        }
        return ans;
    }
};