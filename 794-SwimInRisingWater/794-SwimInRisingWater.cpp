// Last updated: 12/8/2025, 11:27:14 PM
class Solution {
public:
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    int swimInWater(vector<vector<int>>& grid) {
        // heap, each time process smallest.
        // record current MAX if heap.top() > time, time = heap.top();
        // if hea.top() = grid[n - 1][n - 1], return time;
        int n = grid.size();
        int end = (n - 1) * n + (n - 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int resTime = grid[0][0];
        pq.push({grid[0][0], 0});
        visited[0][0] = true;
        while (pq.top().second != end) {
            int time = pq.top().first;
            int x = pq.top().second / n;
            int y = pq.top().second % n;
            if (time > resTime) {
                resTime = time;
            }
            pq.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (0 <= nx && nx < n && 0 <= ny && y < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx * n + ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        return max(resTime, grid[n - 1][n - 1]);
    }
};