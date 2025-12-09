// Last updated: 12/8/2025, 11:28:58 PM
class Solution {
private:
    vector<int> original;
    vector<int> shuffled;
public:
    Solution(vector<int>& nums) {
        original = shuffled = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        for (int i = original.size() - 1; i >= 0; --i) {
            int k = rand() % (i + 1);
            swap(shuffled[i], shuffled[k]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */