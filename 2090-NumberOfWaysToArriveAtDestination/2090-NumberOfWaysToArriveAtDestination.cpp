// Last updated: 12/8/2025, 11:25:53 PM
class Solution {
public:
    const int MOD = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> graph(n);
        for (vector<int>& e : roads) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<int> count(n, 0);
        vector<long long> minDist(n, LLONG_MAX);
        count[n - 1] = 1;
        minDist[n - 1] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, n - 1});
        while (!pq.empty()) {
            long long dist = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (dist > minDist[cur]) continue;
            for (auto& [nei, cost] : graph[cur]) {
                if (minDist[nei] == (dist + cost)) {
                    count[nei] = (count[nei] + count[cur]) % MOD;
                }
                if (minDist[nei] > dist + cost) {
                    minDist[nei] = dist + cost;
                    pq.push({minDist[nei], nei});
                    count[nei] = count[cur];
                }
            }
        }
        return count[0];
    }
};