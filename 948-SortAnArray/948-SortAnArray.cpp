// Last updated: 12/8/2025, 11:26:45 PM
class Solution {
private:
    void heapify(vector<int>& nums, int i, int n) {
        int left = i * 2;
        int right = i * 2 + 1;
        if (left <= n && right <= n) {
            int larger_child = nums[left] < nums[right] ? right : left;
            if (nums[i] < nums[larger_child]) {
                swap(nums[i], nums[larger_child]);
                heapify(nums, larger_child, n);
            }
        } else if (left <= n && nums[i] < nums[left]) {
            swap(nums[i], nums[left]);
            heapify(nums, left, n);
        }
    }

    void heap_pop(vector<int>& nums, int n) {
        if (n > 0) {
            swap(nums[0], nums[n]);
            heapify(nums, 0, n - 1);
            heap_pop(nums, n - 1);
        }
    }

    void heap_sort(vector<int>& nums) {
        int n = nums.size() - 1;
        for (int i = n / 2; i >= 0; --i) {
            heapify(nums, i, n);
        }
        heap_pop(nums, n);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums);
        return nums;
    }
};