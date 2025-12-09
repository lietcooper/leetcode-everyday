// Last updated: 12/8/2025, 11:29:05 PM
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int n = matrix.size();
        int high = matrix[n-1][n-1];
        while(low < high){
            int mid = low + (high - low)/2;
            if (countLessEqual(matrix,mid) < k)
                low = mid +1;
            else
                high = mid;
        }
        return low;
    }
private:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int col = 0;
        int row = n -1;
        int count = 0;
        while (row >=0 && col < n){
            if (matrix[row][col] <= mid){
                count += row + 1;
                col++; // move right
            } else{
                row--; // move up
            }
        }
        return count;
    }

};