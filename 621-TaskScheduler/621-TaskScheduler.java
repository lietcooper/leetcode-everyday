// Last updated: 12/8/2025, 11:28:14 PM
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        int maxCount = 0;

        for (char c : tasks) {
            freq[c - 'A']++;
            maxCount = Math.max(maxCount, freq[c - 'A']);
        }

        int time = (maxCount - 1) * (n + 1);
        for (int i : freq) {
            if (i == maxCount) time++;
        }

        return Math.max(time, tasks.length);
    }
}