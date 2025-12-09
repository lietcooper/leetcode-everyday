// Last updated: 12/8/2025, 11:27:05 PM
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(const vector<vector<int>>& graph) {
        int start = path.back();
        if (start == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[start].size(); ++i) {
            path.push_back(graph[start][i]);
            dfs(graph);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph);
        return result;
    }
};