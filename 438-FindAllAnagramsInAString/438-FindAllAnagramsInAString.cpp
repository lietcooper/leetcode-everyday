// Last updated: 12/8/2025, 11:28:47 PM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return vector<int>();
        vector<int> ans;
        int map[26] = {0};
        int counter = p.length();

        for (const auto& c : p) {
            map[c - 'a']++;
        }

        int begin = 0, end = 0;

        // for the first p.length substring
        for (; end < p.length(); end++) {
            if (map[s[end] - 'a']-- > 0) {
                counter--;
            }
        }
        
        if (counter == 0) ans.push_back(begin);

        while (end < s.length()) {
            if (map[s[begin++] - 'a']++ >= 0) counter++;
            if (map[s[end++] - 'a']-- > 0) counter--;
            if (counter == 0) ans.push_back(begin);
        }
        return ans;
    }
};