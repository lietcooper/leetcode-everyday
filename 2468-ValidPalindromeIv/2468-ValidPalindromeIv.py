# Last updated: 12/8/2025, 11:25:48 PM
class Solution:
    def makePalindrome(self, s: str) -> bool:
        operations = 0
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                operations += 1
            if operations > 2:
                return False

            l += 1
            r -= 1
        
        return True
            