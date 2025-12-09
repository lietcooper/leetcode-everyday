// Last updated: 12/8/2025, 11:26:27 PM
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // count
        unordered_map<string, vector<pair<int, string>>> visit;  // user - {time, websites}
        for (int i = 0; i < username.size(); ++i) {
            visit[username[i]].push_back({timestamp[i], website[i]});
        }

        unordered_map<string, vector<string>> visitPattern;
        // sort according to timestamp, the timestamp is not guaranteed to be sorted
        // reconstruct visit pattern map - only keeping websites
        for (auto& [user, p] : visit) {
            sort(p.begin(), p.end(), [](const pair<int, string>& p1, const pair<int, string>& p2) {
                return p1.first < p2.first;
            });
            for (const pair<int, string>& site : p) {
                visitPattern[user].push_back(site.second);
            }
        }

        // get 3-websites combinations, use string as pattern for hashing
        unordered_map<string, unordered_set<string>> patternFreq;  // 3-websites as string - user

        // get all combinations
        for (auto& [user, pattern] : visitPattern) {
            if (pattern.size() >= 3) {
                for (int i = 0; i < pattern.size() - 2; ++i) {
                    for (int j = i + 1; j < pattern.size() - 1; ++j) {
                        for (int k = j + 1; k < pattern.size(); ++k) {
                            string p = pattern[i] + '#' + pattern[j] + '#' + pattern[k] + '#';
                            patternFreq[p].insert(user);
                        }
                    }
                }
            }
        }

        // retrieve the map and compare
        string max_pattern = "";
        int max_score = 0;
        for (auto& [pattern, users] : patternFreq) {
            if (users.size() > max_score) {
                max_pattern = pattern;
                max_score = users.size();
            } else if (users.size() == max_score && max_pattern > pattern) {
                max_pattern = pattern;
            }
        }

        // restore the patterns
        vector<string> res;
        string temp = "";
        for (char c : max_pattern) {
            if (c == '#') {
                res.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return res;
    }
};