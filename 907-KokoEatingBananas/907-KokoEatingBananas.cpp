// Last updated: 12/8/2025, 11:26:50 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0;
        for (int p : piles) 
            hi = max(hi, p);
        hi++;

        auto eatTime = [&](int k) {
            int time = 0;
            for (int p : piles) {
                time += (p + k - 1) / k; 
            } 
            return time;
        };

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            int k = eatTime(mid);
            if (k > h) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};