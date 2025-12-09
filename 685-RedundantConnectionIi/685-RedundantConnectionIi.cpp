// Last updated: 12/8/2025, 11:27:57 PM
class Solution {   
private:
    vector<int> parent;
    void init(int n) {
        parent.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            parent[v] = u;
            return true;
        }
        return false;
    }

    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, const vector<int>& edge) {
        init(edges.size());
        for (const vector<int>& e : edges) {
            if (e != edge) {
                if (!join(e[0], e[1])) return false;
            }
        }
        return true;
    }


public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> in(edges.size() + 1, 0);
        int delNode = 0;
        for (const vector<int>& edge : edges) {
            if (++in[edge[1]] >= 2) {
                delNode = edge[1];
                break;
            };
        }
        if (delNode != 0) {
            vector<int> delNodes;
            for (const vector<int>& edge : edges) {
                if (edge[1] == delNode) {
                    delNodes.push_back(edge[0]);
                };
            }

            for (int i = delNodes.size() - 1; i >= 0; --i) {
                if (isTreeAfterRemoveEdge(edges, {delNodes[i], delNode})) {
                    return {delNodes[i], delNode};
                }
            }
        }

        // no in degree of 2
        init(edges.size());
        for (const vector<int>& edge : edges) {
            if (!join(edge[0], edge[1])) return edge;
        }
 
        return {};

    }
};
