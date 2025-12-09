// Last updated: 12/8/2025, 11:25:50 PM
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // build graph
        vector<vector<int>> graph(n + 1);
        for (vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> time1(n + 1, INT_MAX), time2(n + 1, INT_MAX);
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        queue<pair<int, int>> q;
        time1[1] = 0;
        // pq.push({0, 1});
        q.push({0, 1});
        while (!q.empty()) {
            // auto [t, node] = pq.top();
            // pq.pop();
            auto [t, node] = q.front();
            q.pop();
            
            if ((t / change) % 2) {
                t = (t / change + 1) * change;
            }

            for (int& nei : graph[node]) {
                if (time1[nei] > t + time) {
                    time2[nei] = time1[nei];
                    time1[nei] = t + time;
                    // pq.push({time1[nei], nei});
                    q.push({time1[nei], nei});
                } else if (time2[nei] > t + time && t + time > time1[nei]) {
                    time2[nei] = t + time;
                    // pq.push({time2[nei], nei});
                    q.push({time2[nei], nei});
                }
            }
        }
        return time2[n];
    }
};