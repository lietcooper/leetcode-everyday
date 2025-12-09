# Last updated: 12/8/2025, 11:28:35 PM
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)
        n = len(nums)
        dp = [[0] * (2 * total + 1) for _ in range(n)]
        dp[0][total + nums[0]] = 1
        dp[0][total - nums[0]] += 1  # could be same, so +=
        for i in range(1, n):
            for j in range(-total, total + 1):
                if dp[i - 1][j + total] > 0:
                    dp[i][j + nums[i] + total] += dp[i - 1][j + total]
                    dp[i][j - nums[i] + total] += dp[i - 1][j + total]
        return 0 if abs(target) > total else dp[n - 1][target + total]
