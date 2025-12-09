// Last updated: 12/8/2025, 11:27:03 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // set<int> safe;
        vector<bool> safe(n, false);
        vector<vector<int>> grid(n);
        vector<int> out(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty()) {
                // safe.insert(i);
                safe[i] = true;
                q.push(i);
            }
            for (int j = 0; j < graph[i].size(); ++j) {
                grid[graph[i][j]].push_back(i);
                out[i]++;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < grid[cur].size(); ++i) {
                if (--out[grid[cur][i]] == 0) {
                    // safe.insert(grid[cur][i]);
                    safe[grid[cur][i]] = true;
                    q.push(grid[cur][i]);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) res.push_back(i);
        }
        // return vector<int>(safe.begin(), safe.end());
        return res;
    }
};