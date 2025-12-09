// Last updated: 12/8/2025, 11:27:53 PM
class Solution {
public:
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    int area(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
        if (x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size() || grid[x][y] != 1 || visited[x][y]) {
            return 0;
        } 

        int count = 1;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            count += area(grid, nx, ny, visited);
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, area(grid, i, j, visited));
                }
            }
        }
        return maxArea;
    }
};