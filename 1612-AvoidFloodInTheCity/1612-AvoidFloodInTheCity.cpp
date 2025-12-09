// Last updated: 12/8/2025, 11:26:03 PM
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> rained;
        set<int> zero;
        vector<int> res(rains.size(), 1);

        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                zero.insert(i);
            } else {
                res[i] = -1;
                if (rained.find(rains[i]) != rained.end()) {
                    set<int>::iterator it = zero.upper_bound(rained[rains[i]]);
                    if (it == zero.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    zero.erase(it);
                }
                rained[rains[i]] = i;
            }
        }
        return res;
    }
};