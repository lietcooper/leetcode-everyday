// Last updated: 12/8/2025, 11:27:07 PM
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                stack<int> st;
                color[i] = 0;
                st.push(i);
                while (!st.empty()) {
                    int cur = st.top();
                    st.pop();
                    for (int nei : graph[cur]) {
                        if (color[nei] == -1) {
                            color[nei] = color[cur] ^ 1;
                            st.push(nei);
                        } else if (color[nei] == color[cur])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};