# Last updated: 12/8/2025, 11:27:51 PM
divs = [100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1]
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        preStratDiv = 1000000000
        pre = N // preStratDiv
        
        curDiv = preStratDiv // 10
        Nmod = N
        for curDiv in divs:
            cur, nxtNmod = divmod(Nmod, curDiv)
            if cur >= pre:
                if cur > pre:
                    pre = cur
                    preStratDiv = curDiv
            else:
                N = (N // preStratDiv) * preStratDiv - 1
                break

            Nmod = nxtNmod
        
        return N