// Last updated: 12/8/2025, 11:25:54 PM
class Solution {
public:
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = n - 1;
        int up = 0, down = m - 1; 
        while (left <= right) {
            int mid = (left + right) / 2;
            
            int max_row = 0;
            for (int row = 0; row < m; ++row) {
                if (mat[row][mid] > mat[max_row][mid]) max_row = row;
            }

            // check left and right
            int left_val = mid > 0 ? mat[max_row][mid - 1] : INT_MIN;
            int right_val = mid < n - 1 ? mat[max_row][mid + 1] : INT_MIN;
            if (mat[max_row][mid] > left_val && mat[max_row][mid] > right_val) return {max_row, mid};
            else if (mat[max_row][mid] < left_val) right = mid - 1;
            else left = mid + 1; 
        }

        return {};
    }
};