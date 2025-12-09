# Last updated: 12/8/2025, 11:27:59 PM
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def isValid(left: int, right: int) -> bool:
            l, r = left, right
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            
            return True
        
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return isValid(l + 1, r) or isValid(l, r - 1)
            l += 1
            r -= 1
        
        return True

