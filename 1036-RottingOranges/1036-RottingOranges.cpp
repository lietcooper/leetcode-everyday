// Last updated: 12/8/2025, 11:26:34 PM
class Solution {
public:
    int dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<int> q;
        int fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push(i * n + j);
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0;

        
        int minute = 0;
        while (!q.empty()) {
            minute++;
            int sz = q.size();
            while (sz--) {
                int x = q.front() / n;
                int y = q.front() % n;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 3;
                        fresh--;
                        q.push(nx * n + ny);
                    }
                }
            }
        }
        return fresh == 0 ? minute - 1 : -1;
    }
};