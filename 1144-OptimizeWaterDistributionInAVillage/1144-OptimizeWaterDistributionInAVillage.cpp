// Last updated: 12/8/2025, 11:26:22 PM
class Solution {
private:
    vector<int> root;
    void init(int n) {
        root.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            root[i] = i;
    }

    int find(int v) {
        return root[v] == v ? v : root[v] = find(root[v]);
    }

    bool join(int v, int u) {
        v = find(v);
        u = find(u);
        if (u == v) return false;
        root[u] = v;
        return true;
    }

public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 1; i <= n; ++i) {
            pipes.push_back({0, i, wells[i - 1]});
        }

        sort(pipes.begin(), pipes.end(), [](vector<int>& p1, vector<int>& p2) {
            return p1[2] < p2[2];
        });

        init(n);
        int cost = 0;
        for (vector<int>& p : pipes) {
            if (join(p[0], p[1]))
                cost += p[2];
        }
        return cost;
    }
};