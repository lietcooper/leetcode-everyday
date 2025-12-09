// Last updated: 12/8/2025, 11:26:00 PM
// class Solution {
// private:
//     int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         // change min dist to min effort to each node
//         int n = heights.size(), m = heights[0].size();
//         vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         minEffort[0][0] = 0;
//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;  // { dif, {x, y} };
//         pq.push({0, {0, 0}});
//         while (!pq.empty()) {
//             auto [dif, xy] = pq.top();
//             auto [x, y] = xy;
//             pq.pop();
//             if (x == n - 1 && y == m - 1) return dif;
//             if (visited[x][y]) continue;
//             visited[x][y] = true;

//             for (int i = 0; i < 4; ++i) {
//                 int nx = x + dir[i][0];
//                 int ny = y + dir[i][1];
//                 if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
//                     minEffort[nx][ny] = min(minEffort[nx][ny], max(minEffort[x][y], abs(heights[x][y] - heights[nx][ny])));
//                     pq.push({minEffort[nx][ny], {nx, ny}});
//                 }
//             }
//         }
//         return minEffort[n - 1][m - 1];
//     }
// };


class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (dfsUtil(heights, mid)) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfsUtil(vector<vector<int>> &heights, int mid) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        return canReachDestinaton(0, 0, heights, visited, row, col, mid);
    }

    bool canReachDestinaton(int x, int y, vector<vector<int>> &heights,
                            vector<vector<bool>> &visited, int row, int col,
                            int mid) {
        if (x == row - 1 && y == col - 1) {
            return true;
        }
        visited[x][y] = true;
        for (auto direction : directions) {
            int adjacentX = x + direction[0];
            int adjacentY = y + direction[1];
            if (isValidCell(adjacentX, adjacentY, row, col) &&
                !visited[adjacentX][adjacentY]) {
                int currentDifference =
                    abs(heights[adjacentX][adjacentY] - heights[x][y]);
                if (currentDifference <= mid) {
                    if (canReachDestinaton(adjacentX, adjacentY, heights,
                                           visited, row, col, mid))
                        return true;
                }
            }
        }
        return false;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
};