// Last updated: 12/8/2025, 11:26:16 PM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxProb(n, 0);
        maxProb[start_node] = 1;
        for (int _ = 1; _ < n; ++_) {
            bool update = false;
            vector<double> copy(maxProb);
            for (int i = 0; i < edges.size(); ++i) {
                if (copy[edges[i][0]] != 0 && maxProb[edges[i][1]] < copy[edges[i][0]] * succProb[i]) {
                    maxProb[edges[i][1]] = copy[edges[i][0]] * succProb[i];
                    update = true;
                }

                if (copy[edges[i][1]] != 0 && maxProb[edges[i][0]] < copy[edges[i][1]] * succProb[i]) {
                    maxProb[edges[i][0]] = copy[edges[i][1]] * succProb[i];
                    update = true;
                }
            }
            if (update == false) break;
        }
        return maxProb[end_node];
    }
};