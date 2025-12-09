// Last updated: 12/8/2025, 11:28:54 PM
class Solution {
public:
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int res = 0;
        int seen[m][n];
        memset(seen, 0, sizeof(seen));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i * n);
            pq.emplace(heightMap[i][n - 1], i * n + n - 1);
            seen[i][0] = seen[i][n - 1] = 1;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.emplace(heightMap[0][j], j);
            pq.emplace(heightMap[m - 1][j], (m - 1) * n + j);
            seen[0][j] = seen[m - 1][j] = 1;
        }
        while (!pq.empty()) {
            auto [h, idx] = pq.top(); pq.pop();
            for (int i = 0, x = idx / n, y = idx % n; i < 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (0 <= nx && nx < m && 0 <= ny && ny < n && !seen[nx][ny]) {
                    if (heightMap[nx][ny] < h) res += h - heightMap[nx][ny];
                    pq.emplace(max(heightMap[nx][ny], h), nx * n + ny);
                    seen[nx][ny] = 1;
                }
            }
        }
        return res;
    }
};