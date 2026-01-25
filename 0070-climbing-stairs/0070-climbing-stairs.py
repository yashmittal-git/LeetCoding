class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 2:
            return n
        prev_prev = 1
        prev = 2
        for i in range(2,n):
            prev_prev, prev = prev, prev_prev+ prev
        
        return prev
        