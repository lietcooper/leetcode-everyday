// Last updated: 12/8/2025, 11:27:46 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);  // {node : {nei : time}}
        for (const vector<int>& e : times)
            graph[e[0]].emplace_back(make_pair(e[1], e[2]));
            
        vector<int> dist(n + 1, INT_MAX);
        stack<int> st;
        dist[k] = 0;
        st.push(k);
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            for (auto& [nei, time] : graph[cur]) {
                if (dist[nei] > dist[cur] + time) {
                    dist[nei] = dist[cur] + time;
                    st.push(nei);
                }
            }
        }

        int time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] > time)
                time = dist[i];
        }
        return time == INT_MAX ? -1 : time;
    }
};