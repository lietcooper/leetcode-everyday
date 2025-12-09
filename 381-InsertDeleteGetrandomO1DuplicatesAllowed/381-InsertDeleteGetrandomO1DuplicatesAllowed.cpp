// Last updated: 12/8/2025, 11:29:01 PM
class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> index;
    vector<int> nums;

public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool inserted = index.find(val) == index.end();
        nums.push_back(val);
        index[val].insert(nums.size() - 1);
        return inserted;
    }
    
    bool remove(int val) {
        if (index.find(val) != index.end()) {
            if (nums.back() == val) {
                nums.pop_back();
                index[val].erase(nums.size());
            } else {
                int delIndex = *(index[val].begin());
                index[val].erase(delIndex);
                swap(nums[delIndex], nums.back());
                nums.pop_back();
                index[nums[delIndex]].erase(nums.size());
                index[nums[delIndex]].insert(delIndex);
            }

            if (index[val].empty()) index.erase(val);
            return true;
        } else return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */