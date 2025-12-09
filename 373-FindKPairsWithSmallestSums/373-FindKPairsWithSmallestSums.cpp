// Last updated: 12/8/2025, 11:29:06 PM
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // {sum, index of nums2}
        for (int n : nums1) pq.push({n + nums2[0], 0});
        vector<vector<int>> res;
        while (k-- && !pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int sum = cur.first;
            int index = cur.second;
            res.push_back({sum - nums2[index], nums2[index]});
            if (index + 1 < nums2.size()) pq.push({sum - nums2[index] + nums2[index + 1], index + 1});
        }
        return res;
    }
};