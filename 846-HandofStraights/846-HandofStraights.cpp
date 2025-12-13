// Last updated: 12/12/2025, 8:22:14 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int x : hand) freq[x]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;   // smallest element

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (freq[card] == 0) return false;
                freq[card]--;
                if (freq[card] == 0) freq.erase(card);
            }
        }

        return true;
    }
};
