// Last updated: 12/12/2025, 7:58:46 PM
1class Solution {
2public:
3    bool isNStraightHand(vector<int>& hand, int groupSize) {
4        if (hand.size() % groupSize) return false;
5        unordered_map<int, int> freq;
6        set<int> numbers;
7        for (int n : hand) {
8            freq[n]++;
9            numbers.insert(n);
10        }
11
12        for (int i : numbers) {
13            if (freq[i] == 0) continue;
14            for (int j = 1; j < groupSize; ++j) {
15                if (freq.count(i + j) == 0 || freq[i + j] < freq[i]) {
16                    return false;
17                } else {
18                    freq[i + j] -= freq[i];
19                }
20            }
21            freq[i] = 0;
22        }    
23        return true;    
24    }
25};