// Last updated: 12/8/2025, 11:26:54 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // double time[i] = (target - position) / speed[i]
        // if time[i] <= time[i + 1], in same fleet;
        // if time[i] > time[i + 1], fleet += 1;
        vector<pair<double, int>> time(position.size(), {0, 0});
        auto T = [&](int i) {return ((double)(target - position[i]) / speed[i]);};
        for (int i = 0; i < position.size(); ++i)
            time[i] = {T(i), position[i]};

        sort(time.begin(), time.end(), [&](const pair<double, int>& a, const pair<double, int>& b) {
            return a.second < b.second;
        });
        
        int fleet = 1;
        int m = time.size();
        for (int i = m - 2; i >= 0; --i) {
            if (time[i].first > time[i + 1].first)
                fleet++;
            else {
                time[i].first = time[i + 1].first;
            }
        }
        return fleet;
    }
};