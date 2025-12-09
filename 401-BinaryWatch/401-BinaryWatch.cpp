// Last updated: 12/8/2025, 11:28:55 PM
class Solution {
private:
    vector<int> h = {8, 4, 2, 1};
    vector<int> m = {32, 16, 8, 4, 2, 1};
    unordered_map<int, vector<int>> hourCombinations = { {0, {0}} };
    unordered_map<int, vector<int>> minuteCombinations = { {0, {0}} };
    vector<string> result;
    vector<int> p;

    void getSubsets(int startIndex, int sum, unordered_map<int, vector<int>>& map, const vector<int>& hm) {
        // if (sum > 0) {
        //     map[startIndex].push_back(sum);
        // }

        for (int i = startIndex; i < hm.size(); ++i) {
            sum += hm[i];
            p.push_back(hm[i]);
            map[p.size()].push_back(sum);
            getSubsets(i + 1, sum, map, hm);
            sum -= hm[i];
            p.pop_back();
        }
    }

    void getCombinations(int turnedOn) {
        // choose from one set;
        // choose from the other set'
        for (int i = 0; i <= h.size(); ++i) {
            vector<int> hours = hourCombinations[i];
            if (turnedOn - i > m.size()) continue;
            vector<int> minutes = minuteCombinations[turnedOn - i];
            for (int hour : hours) {
                if (hour >= 12) continue;
                string sh = to_string(hour);
                for (int minute : minutes) {
                    if (minute >= 60) continue;
                    string sm = minute >= 10 ? to_string(minute) : "0" + to_string(minute);
                    string time = sh + ":" + sm; 
                    result.push_back(time);
                }
            }
        }
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        getSubsets(0, 0, hourCombinations, h);     // combinations from hours
        getSubsets(0, 0, minuteCombinations, m);   // combinations from minutes
        getCombinations(turnedOn);
        return result;
    }
};