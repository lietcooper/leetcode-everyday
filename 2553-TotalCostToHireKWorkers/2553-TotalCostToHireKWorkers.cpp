// Last updated: 12/8/2025, 11:25:48 PM
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int i = 0, j = costs.size() - 1;
        for (i; i < candidates && i < costs.size(); ++i) {
            pq.push({costs[i], i});
        }

        for (j; j > costs.size() - 1 - candidates && j >= i; --j) {
            pq.push({costs[j], j});
        }

        long long total = 0;

        while (k--) {
            auto [cost, k] = pq.top();
            pq.pop();
            total += cost;
            if (i <= j) {
                if (k < i) {
                    pq.push({costs[i], i});
                    i++;
                }
                else {
                    pq.push({costs[j], j});
                    j--;
                }
            }
        }
        return total;
    }
};