// Last updated: 12/8/2025, 11:26:17 PM
class Solution {
private:
    vector<int> root;
    vector<int> rank;
    int find(int u) {
        return root[u] == u ? root[u] : root[u] = find(root[u]);
    }

    // bool join(int u, int v) {
    //     u = find(u);
    //     v = find(v);
    //     if (u == v) return false;
    //     root[v] = u;
    //     return true;
    // }

    void join(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        root.resize(s.length(), 0);
        rank.resize(s.length(), 1);
        for (int i = 0; i < s.length(); ++i) {
            root[i] = i;
        }        

        for (const vector<int>& edge : pairs) {
            join(edge[0], edge[1]);
        }

        // if random join, need to compress path once more
        // for (int i = 0; i < s.length(); ++i) {
        //     find(i);
        // }

        // map to store connected components
        unordered_map<int, vector<int>> rootToComponent;
        for (int i = 0; i < s.length(); ++i) {
            // already in order
            rootToComponent[find(i)].emplace_back(i);
        }

        string smallest(s.length(), ' ');

        for (auto& [root, indices] : rootToComponent) {
            vector<char> characters;
            // retrieve all chars by index
            for (int index : indices) {
                characters.emplace_back(s[index]);
            }
            sort(characters.begin(), characters.end());

            // assign sorted chars to slots
            for (int i = 0; i < indices.size(); ++i) {
                smallest[indices[i]] = characters[i];
            }
        }
        return smallest;
    }
};