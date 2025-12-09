// Last updated: 12/8/2025, 11:26:57 PM
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1) return 0;

        int n = graph.size();
        int endingMask = (1 << n) - 1;
        vector<vector<bool>> seen(n, vector<bool>(endingMask, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            seen[i][1 << i] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, mask] = q.front();
                q.pop();
                for (int nei : graph[node]) {
                    int nmask = mask | (1 << nei);
                    if (nmask == endingMask) {
                        return 1 + steps;
                    }

                    if (!seen[nei][nmask]) {
                        seen[nei][nmask] = true;
                        q.push({nei, nmask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};