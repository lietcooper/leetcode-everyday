// Last updated: 12/8/2025, 11:26:53 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for (int bill : bills) {
            if (bill == 5) fives++;
            if (bill == 10) {
                if (fives == 0) return false;
                tens++;
                fives--;
            }
            if (bill == 20) {
                if (fives == 0 || fives * 5 + tens * 10 < 15) return false;
                fives--;
                if (tens > 0) tens--;
                else fives -= 2; 
            }
        }
        return true;
    }
};