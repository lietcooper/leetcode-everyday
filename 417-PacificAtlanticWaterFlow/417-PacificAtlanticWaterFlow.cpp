// Last updated: 12/8/2025, 11:28:51 PM
class Solution {
public:
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

    void bfs(auto& heights, int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (0 <= nx && nx < heights.size() && 0 <= ny && ny < heights[0].size() && heights[nx][ny] >= heights[x][y] && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();

        vector<vector<bool>> P(m, vector<bool>(n, false)), A(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            if (!P[i][0]) bfs(heights, i, 0, P);
            if (!A[i][n - 1]) bfs(heights, i, n - 1, A);
        }

        for (int j = 0; j < n; ++j) {
            if (!P[0][j]) bfs(heights, 0, j, P);
            if (!A[m - 1][j]) bfs(heights, m - 1, j, A);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (P[i][j] && A[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};