// Last updated: 12/8/2025, 11:28:43 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};