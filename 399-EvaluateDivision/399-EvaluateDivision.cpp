// Last updated: 12/8/2025, 11:28:56 PM
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> result;
        for (int i = 0; i < equations.size(); ++i) {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            result[s1][s2] = values[i];
            result[s2][s1] = 1 / values[i];
            result[s1][s1] = result[s2][s2] = 1.0;
        }

        for (auto& [s1, map] : result) {
            queue<string> q;
            for (auto& [s2, _] : map)
                q.push(s2);
            while (!q.empty()) {
                string s2 = q.front();
                q.pop();
                for (auto& [s3, _] : result[s2]) {
                    if (result[s1].find(s3) == result[s1].end()) {
                        result[s1][s3] = result[s1][s2] * result[s2][s3];
                        result[s3][s1] = result[s3][s2] * result[s2][s1];
                        q.push(s3);
                    }
                }
            }
        }

        vector<double> ans;
        for (auto& q : queries) {
            if (result[q[0]].find(q[1]) != result[q[0]].end()) {
                ans.push_back(result[q[0]][q[1]]);
            } else {
                ans.push_back(-1.0);
            }
        }
        return ans;
        
    }
};
