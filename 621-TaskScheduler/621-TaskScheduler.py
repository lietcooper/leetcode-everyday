# Last updated: 12/8/2025, 11:28:17 PM
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = [0] * 26
        for c in tasks:
            freq[ord(c) - ord('A')] += 1

        freq.sort()
        maxFreq = freq[25] - 1
        idleSlots = maxFreq * n
        for i in range(24, -1, -1):
            idleSlots -= min(freq[i], maxFreq)

        return idleSlots + len(tasks) if idleSlots > 0 else len(tasks)
