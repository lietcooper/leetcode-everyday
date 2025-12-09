// Last updated: 12/8/2025, 11:28:13 PM
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> pos;
        for (int i = 0; i < list1.size(); ++i) {
            pos[list1[i]] = i;
        }

        int sum = INT_MAX;
        vector<string> result;
        for (int i = 0; i < list2.size(); ++i) {
            string word = list2[i];
            if (pos.find(word) != pos.end()) {
                int cur_sum = pos[word] + i;
                if (cur_sum < sum) {
                    sum = cur_sum;
                    result.clear();
                    result.push_back(word);
                } else if (cur_sum == sum) {
                    result.push_back(word);
                }
            }
        }
        return result;
    }
};