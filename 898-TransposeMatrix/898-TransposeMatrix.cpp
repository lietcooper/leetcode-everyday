// Last updated: 12/8/2025, 11:26:51 PM
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> t_matrix(n, vector<int>(m, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                t_matrix[j][i] = matrix[i][j];
            }
        }
        return t_matrix;
    }
};