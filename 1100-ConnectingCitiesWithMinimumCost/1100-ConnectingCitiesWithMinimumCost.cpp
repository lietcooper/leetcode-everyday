// Last updated: 12/8/2025, 11:26:30 PM
class Solution {
private:
    int prim(int n, const vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (const vector<int>& edge : connections) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n + 1, false);
        vector<int> minDist(n + 1, INT_MAX);
        minDist[1] = 0;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int cur = 0;
            int dist = INT_MAX;
            for (int j = 1; j <= n; ++j) {
                if (!visited[j] && minDist[j] < dist) {
                    cur = j;
                    dist = minDist[j];
                }
            }
            if (cur == 0) return -1;  // not updated, unconnected
            sum += dist;
            visited[cur] = true;
            for (const auto& [nei, ndist] : adjList[cur]) {
                if (!visited[nei]) {
                    minDist[nei] = min(minDist[nei], ndist);
                }
            }
        }
        return sum;
    }

    int kruskal(int n, vector<vector<int>> connections) {
        vector<int> parent(n + 1, 0);
        vector<int> weight(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        sort(connections.begin(), connections.end(), [](vector<int> e1, vector<int> e2) {
            return e1[2] < e2[2];
        });
        
        int total = 1;
        int sum = 0;
        for (const vector<int>& edge : connections) {
            if (join(edge[0], edge[1], parent, weight)) {
                total++;
                sum += edge[2];
            }
        }
        for (int i = 1; i < n; i++) {
            if (find(i, parent) != find(i + 1, parent)) return -1;
        }
        return total == n ? sum : -1;
    }

    bool join(int u, int v, vector<int>& parent, vector<int>& weight) {
        u = find(u, parent);
        v = find(v, parent);
        if (u != v) {
            if (weight[u] > weight[v]) {
                parent[v] = u;
                weight[u] += weight[v];
            } else {
                parent[u] = v;
                weight[v] += weight[u];
            }
            return true;
        }
        return false;
    }

    int find(int u, vector<int>& parent) {
        // return u == parent[u] ? u : parent[u] = find(parent[u], parent);
        while (u != parent[u]) {
            parent[u] = find(parent[u], parent);
            u = parent[u];
        }
        return u;
    }

public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // return prim(n, connections);
        return kruskal(n, connections);
    }
};