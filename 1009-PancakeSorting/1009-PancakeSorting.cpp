// Last updated: 12/8/2025, 11:26:38 PM
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int sorted = 0;
        while (sorted < arr.size()) {
            int large = 0;
            int index = -1;
            for (int i = 0; i < arr.size() - sorted; ++i) {
                if (arr[i] > large) {
                    large = arr[i];
                    index = i;
                }
            }

            // [5, 1, 2, 6, 3, 4]
            // [6, 2, 1, 5, 3, 4]
            // [4, 3, 5, 1, 2, 6]
            reverse(arr.begin(), arr.begin() + index + 1);
            result.push_back(index + 1);
            reverse(arr.begin(), arr.end() - sorted);
            result.push_back(arr.size() - sorted);
            sorted++;
        }

        return result;
    }
};