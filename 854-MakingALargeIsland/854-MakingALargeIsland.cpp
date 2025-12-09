// Last updated: 12/8/2025, 11:27:01 PM
class Solution {
private:
    int dir[4][2] = {0 ,1, 1, 0, 0, -1, -1, 0};
    int dfs(vector<vector<int>>& visited, int x, int y, int marker) {
        if (x < 0 || x >= visited.size() || y < 0 || y >= visited[0].size() || visited[x][y] == marker || visited[x][y] == 0) {
            return 0;
        } 

        visited[x][y] = marker;
        int area = 1;
        for (int i = 0; i < 4; ++i) {
            area += dfs(visited, x + dir[i][0], y + dir[i][1], marker);
        }
        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid);

        bool isLand = true;
        unordered_map<int, int> area = {{0,0}};
        int marker = 2;
        for (int i = 0; i < visited.size(); ++i) {
            for (int j = 0; j < visited[0].size(); ++j) {
                if (visited[i][j] == 0) isLand = false;
                if (visited[i][j] == 1) {
                    area[marker] = dfs(visited, i, j, marker);
                    marker++;
                }
            }
        }

        if (isLand) return grid.size() * grid[0].size();

        unordered_set<int> islands;
        int result = 0;
        for (int i = 0; i < visited.size(); ++i) {
            for (int j = 0; j < visited[0].size(); ++j) {
                if (visited[i][j] == 0) {
                    int count = 1;
                    islands.clear();
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (0 <= nx && nx < visited.size() && 0 <= ny && ny < visited[0].size() && islands.count(visited[nx][ny]) == 0) {
                            islands.insert(visited[nx][ny]);
                            count += area[visited[nx][ny]];
                        }
                    }
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};