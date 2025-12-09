// Last updated: 12/8/2025, 11:26:33 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);
        for (const auto& t : trust) {
            out[t[0]]++;
            in[t[1]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};