// Last updated: 12/8/2025, 11:26:07 PM
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> out;
        for (vector<string>& e : paths) {
            out.insert(e[0]);
        }

        for (vector<string>& e : paths) {
            if (out.count(e[1]) == 0) {
                return e[1];
            }
        }
        return "";
    }
};