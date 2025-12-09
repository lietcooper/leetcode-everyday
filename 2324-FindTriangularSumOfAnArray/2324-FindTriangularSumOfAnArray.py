# Last updated: 12/8/2025, 11:25:49 PM
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        if (n == 1):
            return nums[0]

        n -= 1
        while n > 0:
            for i in range(n):
                nums[i] = (nums[i] + nums[i + 1]) % 10

            n -= 1

        return nums[0]
        