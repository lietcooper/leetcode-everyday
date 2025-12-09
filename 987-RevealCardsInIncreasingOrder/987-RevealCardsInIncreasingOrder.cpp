// Last updated: 12/8/2025, 11:26:41 PM
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < deck.size(); ++i) {
            q.push(i);
        }
        vector<int> result(deck.size());
        for (int num : deck) {
            result[q.front()] = num;
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};