// Last updated: 12/8/2025, 11:26:06 PM
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            inDegree[b]++;
            adjList[a].push_back(b);
        }
        unordered_map<int, unordered_set<int>> query;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front(); 
            q.pop();
            for (int i = 0; i < adjList[cur].size(); ++i) {
                if (--inDegree[adjList[cur][i]] == 0) q.push(adjList[cur][i]);
                // add prerequisites of current course as prerequisites of next courses
                for (int pre : query[cur]) {
                    query[adjList[cur][i]].insert(pre);
                }
                // add current course as prerequisites of next courses
                query[adjList[cur][i]].insert(cur);
            }
        }
        // query;
        vector<bool> res;
        for (const vector<int> q : queries) {
            res.push_back(query[q[1]].find(q[0]) != query[q[1]].end() ? true : false);
        }
        return res;
    }
};