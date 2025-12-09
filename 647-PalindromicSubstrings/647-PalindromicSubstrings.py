# Last updated: 12/8/2025, 11:28:06 PM
class Solution:
    def countSubstrings(self, s: str) -> int:
        def expand(i, j):
            cnt = 0
            while i >= 0 and j < len(s) and s[i] == s[j]:
                i -= 1
                j += 1
                cnt += 1

            return cnt

        res = 0
        for i in range(len(s)):
            res += expand(i, i)
            res += expand(i, i + 1)

        return res