// Last updated: 12/8/2025, 11:26:54 PM
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
//         int n = quality.size();
//         double totalCost = numeric_limits<double>::max();
//         double currentTotalQuality = 0;
//         vector<pair<double, int>> wageToQuality;
//         for (int i = 0; i < n; ++i) {
//             wageToQuality.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
//         }

//         sort(wageToQuality.begin(), wageToQuality.end());
//         priority_queue<int> workers;

//         for (int i = 0; i < n; ++i) {
//             workers.push(wageToQuality[i].second);
//             currentTotalQuality += wageToQuality[i].second;

//             if (workers.size() > k) {
//                 currentTotalQuality -= workers.top();
//                 workers.pop();
//             }

//             if (workers.size() == k) {
//                 totalCost = min(totalCost, currentTotalQuality * wageToQuality[i].first);
//             }
//         }
//         return totalCost;

//     }
// };

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        int n = wage.size();
        workers.reserve(n);

        for(int i = 0; i < n; i++) {
            double r = (double) wage[i] / (double) quality[i];
            workers.emplace_back(r, quality[i]);
        }

        sort(workers.begin(), workers.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        priority_queue<int, vector<int>> pq;
        long long sum = 0;
        double ans = numeric_limits<double>::infinity();

        for(const auto& [r, q]: workers) {
            pq.push(q);
            sum += q;

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) {
                ans = min(ans, (double) sum * r);
            }
        }
        return ans;
    }
};