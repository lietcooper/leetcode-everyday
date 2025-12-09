// Last updated: 12/8/2025, 11:27:47 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        vector<int> res(tmp.size(), 0);
        int hottest = 0;
        for (int i = tmp.size() - 1; i >= 0; --i) {
            if (tmp[i] >= hottest) {
                hottest = tmp[i];
                continue;
            }

            int day = 1;
            while (tmp[i] >= tmp[i + day]) {
                day += res[i + day];
            }
            res[i] = day;
        }
        return res;
    }
};