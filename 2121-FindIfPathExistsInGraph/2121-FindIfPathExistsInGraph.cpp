// Last updated: 12/8/2025, 11:25:52 PM
class Solution {
private:
    vector<int> root;
    void init(int n) {
        this->root.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }

    int find(int u) {
        return u == root[u] ? u : root[u] = find(root[u]);
    }

    bool connected(int u, int v) {
        // u = find(u);
        // v = find(v);
        return find(u) == find(v);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        root[v] = u;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init(n);
        for (const vector<int>& edge : edges) {
            join(edge[0], edge[1]);
        }

        return connected(source, destination);
    }
};