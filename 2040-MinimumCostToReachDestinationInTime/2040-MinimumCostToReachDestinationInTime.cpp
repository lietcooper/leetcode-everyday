// Last updated: 12/8/2025, 11:25:55 PM
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e: edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INT_MAX));
        dp[0][0] = passingFees[0];

        for (int t = 0; t <= maxTime; ++t) {
            for (int u = 0; u < n; ++u) {
                if (dp[t][u] == INT_MAX) continue;

                for (auto& [v, w] : graph[u]) {
                    if (t + w <= maxTime) {
                        dp[t + w][v] = min(dp[t + w][v], dp[t][u] + passingFees[v]);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int t = 0; t <= maxTime; ++t) {
            ans = min(ans, dp[t][n - 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};