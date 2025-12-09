// Last updated: 12/8/2025, 11:28:39 PM
class Solution {
private:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 1;
        }
        if (visited[x][y]) {
            return 0;
        }
        visited[x][y] = true;
        int perimeter = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            perimeter += dfs(grid, visited, nx, ny);
        }
        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, visited, i, j);
                }
            }
        } 
        return 0;
    }
};