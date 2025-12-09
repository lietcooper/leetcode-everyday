// Last updated: 12/8/2025, 11:27:48 PM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> point_of;
        for (int i : nums) point_of[i] += i;
        vector<int> numbers;
        for (auto& [num, _] : point_of) {
            numbers.push_back(num);
        }
        sort(numbers.begin(), numbers.end());
        int two_back = 0, one_back = point_of[numbers[0]];
        for (int i = 1; i < numbers.size(); ++i) {
            int cur;
            if (numbers[i] == numbers[i - 1] + 1) {
                // if adjacent, pick one
                cur = max(one_back, two_back + point_of[numbers[i]]);
            } else {
                // if not adjacent, pick both
                cur = one_back + point_of[numbers[i]];
            }
            two_back = one_back;
            one_back = cur;
        }

        return one_back;
    }
};