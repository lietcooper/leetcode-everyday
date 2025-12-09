# Last updated: 12/8/2025, 11:25:44 PM
class Solution:
    def findPeaks(self, mountain: List[int]) -> List[int]:
        res = []
        for i in range(len(mountain)):
            if i > 0 and i < len(mountain) - 1:
                if mountain[i - 1] < mountain[i] and mountain[i] > mountain[i + 1]:
                    res.append(i)
        
        return res