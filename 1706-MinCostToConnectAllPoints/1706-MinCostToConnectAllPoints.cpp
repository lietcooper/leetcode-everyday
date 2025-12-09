// Last updated: 12/8/2025, 11:26:03 PM
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cost = 0;
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        minDist[0] = 0;
        for (int k = 0; k < n; ++k) {
            int cur = -1;
            int dist = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && dist > minDist[i]) {
                    cur = i;
                    dist = minDist[i];
                }
            }
            if (cur == -1) break;
            visited[cur] = true;
            cost += minDist[cur];

            for (int i = 0; i < n; ++i) {
                int d = abs(points[cur][0] - points[i][0]) + abs(points[cur][1] - points[i][1]);
                if (!visited[i] && minDist[i] > d) {
                    minDist[i] = d;
                }
            }
        }
        return cost;
    }
};