// Last updated: 12/8/2025, 11:26:00 PM
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int lo = INT_MAX;
        int hi = INT_MIN;
        for (int i = 0; i < heights.size() - 1; ++i) {
            int dif = heights[i + 1] - heights[i];
            lo = min(dif, lo);
            hi = max(dif, hi);
        }
        if (lo == INT_MAX) return heights.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vector<int> result = givenThreshold(heights, bricks, ladders, mid);
            int reached = result[0];
            int laddersRemaining = result[1];
            int bricksRemaining = result[2];
            if (reached == heights.size() - 1) return heights.size() - 1;
            if (laddersRemaining > 0) {  // current threshold is too large that ladders remains
                hi = mid - 1;
                continue;
            }
            int nextClimb = heights[reached + 1] - heights[reached];
            if (nextClimb > bricksRemaining && mid > bricksRemaining) { // remaining climb is not enough for next climb and we cannot use a ladder placed at threshold
                return reached;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }

    vector<int> givenThreshold(vector<int>& heights, int bricks, int ladders, int k) {
        int ladderOnThreshold = 0;
        for (int i = 0; i < heights.size() - 1; ++i) {
            int dif = heights[i + 1] - heights[i];
            if (dif <= 0) continue;
            if (dif == k) {
                ladderOnThreshold++;
                ladders--;
            } else if (dif > k) {
                ladders--;
            } else {
                bricks -= dif;
            }
            
            if (ladders < 0) {
                if (ladderOnThreshold > 0) {
                    ladderOnThreshold--;
                    ladders++;
                    bricks -= k;
                } else {
                    return vector<int>({i, ladders, bricks});
                }
            }
            if (bricks < 0) {
                return vector<int>({i, ladders, bricks});
            }
        } 
        int n = heights.size() - 1;
        return vector<int>({n, ladders, bricks});
    }
};