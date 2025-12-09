// Last updated: 12/8/2025, 11:27:45 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastOccurrence[26] = {0}, firstOccurrence[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        vector<int> res;
        int pEnd = 0, pStart = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (!firstOccurrence[s[i] - 'a']) {
                firstOccurrence[s[i] - 'a'] = i;
            }

            if (pEnd < firstOccurrence[s[i] - 'a']) {
                res.push_back(pEnd - pStart + 1);
                pStart = i;
                pEnd = i;
            }

            pEnd = max(pEnd, lastOccurrence[s[i] - 'a']);
        }

        if (pEnd - pStart + 1 > 0) {
            res.push_back(pEnd - pStart + 1);
        }

        return res;
    }
};