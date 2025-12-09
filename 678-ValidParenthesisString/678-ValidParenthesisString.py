# Last updated: 12/8/2025, 11:28:04 PM
class Solution:
    def checkValidString(self, s: str) -> bool:
        '''
         input: string
         output: true / false

         1. (): true
         2. (*): true
         3. (*)): true
         4. **( : false

            Plan:
                stack: store (
                    if ), p

            * count 
            stack_left: store index of (
                if c = ) and left is empty():
                    if start is empty:
                        return False
                    else:
                        star.pop()
                
                in the end, if left is not empty:
                    compare the index of star and left(
                        while (left is not empty && star.top() > left.top())
                            left.pop()
                    )

                return left is empty
            stack_star: store index of *
        '''
        left = []
        star = []
        for i in range(len(s)):
            if (s[i] == '*'):
                star.append(i)
            elif (s[i] == '('):
                left.append(i)
            else:
                if len(left) > 0:
                    left.pop()
                elif len(star) > 0:
                    star.pop()
                else:
                    return False
        

        while (len(left) > 0 and len(star) > 0 and left[-1] < star[-1]):
            left.pop()
            star.pop()

        return len(left) == 0