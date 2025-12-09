// Last updated: 12/8/2025, 11:26:37 PM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };

        auto cmp = [&](const vector<int>& p1, const vector<int>& p2) {
            return dist(p1) < dist(p2);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto& p : points) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop();
            }
        } 

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top());
            pq.pop();
        }
        return res;
    }
};