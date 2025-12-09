// Last updated: 12/8/2025, 11:28:34 PM
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(const vector<int>& nums, int startIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        unordered_set<int> set;
        for (int i = startIndex; i < nums.size(); ++i) {
            if ((path.empty() || nums[i] >= path[path.size() - 1]) && set.find(nums[i]) == set.end()) {
                set.insert(nums[i]);
                path.push_back(nums[i]);
                backtrack(nums, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;   
    }
};