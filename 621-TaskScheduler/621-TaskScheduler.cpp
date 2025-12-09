// Last updated: 12/8/2025, 11:28:13 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int maxF = 0;
        int maxC = 0;
        for (char c : tasks) 
        {
            freq[c - 'A']++;
            if (freq[c - 'A'] > maxF) {
                maxF = freq[c - 'A'];
                maxC = 1;
            } else if (freq[c - 'A'] == maxF) {
                maxC++;
            }
        }

        int time = (maxF - 1) * (n + 1) + maxC;
        return max(time, (int)tasks.size());
    }
};