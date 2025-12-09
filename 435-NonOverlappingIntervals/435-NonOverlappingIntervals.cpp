// Last updated: 12/8/2025, 11:28:49 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });

        int cnt = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                cnt++;
            } else {
                end = intervals[i][1];
            }
        }
        return cnt;
    }
};