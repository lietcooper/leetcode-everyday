// Last updated: 12/8/2025, 11:26:56 PM
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 1 2 3 4 5 6 3 2 1
        int left = 0, right = arr.size() - 1;
        // inclusive-exclusive?
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid + 1 < arr.size() && arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else if (mid - 1 >= 0 && arr[mid] < arr[mid - 1]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return right;
    }
};