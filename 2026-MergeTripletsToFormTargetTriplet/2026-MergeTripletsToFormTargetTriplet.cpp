// Last updated: 12/8/2025, 11:25:56 PM
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool res = true;
        for (int i = 0; i < 3; ++i) {
            bool valid = false;
            for (vector<int>& triplet : triplets) {
                if (triplet[i] == target[i]) {
                    int k = 0;
                    while (k < 3) {
                        if (triplet[k] > target[k]) {
                            break;
                        }
                        k++;
                    } 
                    if (k == 3) {
                        valid = true;
                        break;
                    }
                    
                }
            }
            res = res && valid;
        }
        return res;
    }
};