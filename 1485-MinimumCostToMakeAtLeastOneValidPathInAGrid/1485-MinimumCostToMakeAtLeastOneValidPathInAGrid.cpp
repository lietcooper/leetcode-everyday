// Last updated: 12/8/2025, 11:26:08 PM
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minDist(m, vector<int>(n, INT_MAX));
        deque<int> dq;
        dq.push_back(0);
        minDist[0][0] = 0;
        while (!dq.empty()) {
            int x = dq.front() / n;
            int y = dq.front() % n;
            dq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                int cost = i + 1 == grid[x][y] ? 0 : 1;
                if (0 <= nx && nx < m && 0 <= ny && ny < n && minDist[nx][ny] > minDist[x][y] + cost) {
                    minDist[nx][ny] = minDist[x][y] + cost;
                    if (cost == 1) {
                        dq.push_back(nx * n + ny);
                    } else {
                        dq.push_front(nx * n + ny);
                    }
                }
            }
        }
        return minDist[m - 1][n - 1];
    }
};