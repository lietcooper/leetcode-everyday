// Last updated: 12/8/2025, 11:29:12 PM
class Solution {
public:
    unordered_map<int, int> freq;
    void quicksort(vector<int>& nums, int l, int r, int k) {
        if (l >= r) return;
        int p = partition(nums, l, r);
        if (p == k) return;
        else if (p > k) quicksort(nums, l, p - 1, k);
        else quicksort(nums, p + 1, r, k);
    }

    int partition(vector<int>& nums, int l, int r) {
        srand(time(NULL));
        int pivotIndex = l + rand() % (r - l + 1);
        int pivotFreq = freq[nums[pivotIndex]];
        int start = l;
        swap(nums[pivotIndex], nums[start]);
        while (true) {
            while (l < r && freq[nums[r]] < pivotFreq) r--;
            while (l < r && freq[nums[l]] >= pivotFreq) l++;
            if (l >= r) break;
            swap(nums[l], nums[r]);
        }
        swap(nums[start], nums[l]);
        return r;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        freq.clear();
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> unique_nums;
        for (auto& [num, _] : freq) 
            unique_nums.push_back(num);

        quicksort(unique_nums, 0, unique_nums.size() - 1, k - 1);
        return vector<int>(unique_nums.begin(), unique_nums.begin() + k); 
    }
};