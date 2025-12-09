// Last updated: 12/8/2025, 11:27:58 PM
class Solution {
public:
    int dfs(vector<vector<int>>& graph, int cur, int prev, vector<bool>& visited, vector<int>& parent) {
        parent[cur] = prev;
        if (visited[cur]) {
            return cur;
        }

        visited[cur] = true;
        int res = -1;
        for (int nei : graph[cur]) {
            if (nei != prev) {
                res = dfs(graph, nei, cur, visited, parent);
                if (res != -1) return res;
            }
        }
        return res;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;  // in this problem, the number of size == numebr of nodes
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        vector<vector<int>> graph(n);
        for (vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int start = dfs(graph, 1, -1, visited, parent);
        
        vector<bool> inCycle(n, false);
        int cur = start;
        do {
            inCycle[cur] = true;
            cur = parent[cur];
        } while (cur != start);

        for (int i = n - 2; i >= 0; --i) {
            if (inCycle[edges[i][0]] && inCycle[edges[i][1]])
                return edges[i];
        }

        return {};
    }
};