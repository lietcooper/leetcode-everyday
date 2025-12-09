// Last updated: 12/8/2025, 11:29:01 PM
class RandomizedSet {
private:
    unordered_map<int, int> index;
    vector<int> nums;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (index.find(val) == index.end()) {
            nums.push_back(val);
            index[val] = nums.size() - 1;
            return true;
        } else return false;
    }
    
    bool remove(int val) {
        if (index.find(val) != index.end()) {
            index[nums[nums.size() - 1]] = index[val];
            swap(nums[nums.size() - 1], nums[index[val]]);
            nums.pop_back();
            index.erase(val);
            return true;
        } else return false;
    }
    
    int getRandom() {
        int rd = rand () % (index.size());
        return nums[rd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */