// Last updated: 12/8/2025, 11:26:59 PM
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        visited.insert(0);
        queue<int> q;
        for (int key : rooms[0]) {
            q.push(key);
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                for (int key : rooms[i]) {
                    q.push(key);
                }
            }
        }

        return visited.size() == n;
    }
};