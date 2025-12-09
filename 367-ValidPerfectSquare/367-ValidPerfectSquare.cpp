// Last updated: 12/8/2025, 11:29:08 PM
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            long mid = static_cast<long>(left + (right - left) / 2);
            if (mid * mid < (long) num) left = mid + 1;
            else if (mid * mid == (long) num) return true;
            else right = mid - 1;
        }
        return false;
    }
};