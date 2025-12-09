// Last updated: 12/8/2025, 11:25:57 PM
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<int> sortQueries = queries;
        sort(sortQueries.begin(), sortQueries.end());
        unordered_map<int, int> res;
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] > v2[0];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int i = 0;
        for (int q : sortQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }

            while (!pq.empty() && pq.top()[1] < q) {
                pq.pop();
            }
            res[q] = pq.empty() ? -1 : pq.top()[0];
        }
        vector<int> answer(queries.size());
        for (int j = 0; j < queries.size(); ++j) {
            answer[j] = res[queries[j]];
        }
        return answer;
    }
};