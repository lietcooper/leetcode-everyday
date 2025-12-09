# Last updated: 12/8/2025, 11:29:02 PM
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        dp = [[0] * (len(s) + 1) for _ in range(2)]

        for i in range(1, len(t) + 1):
            for j in range(1, len(s) + 1):
                if t[i - 1] == s[j - 1]:
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1
                else:
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1])

        return dp[len(t) % 2][len(s)] == len(s)
                