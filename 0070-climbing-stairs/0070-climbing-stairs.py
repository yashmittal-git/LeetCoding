class Solution:

    def fib(self, n:int) -> int:
        series = [1] * (n+1)
        for i in range(2,n+1):
            series[i] = series[i-1] + series[i-2]
        
        return series[n]

    def climbStairs(self, n: int) -> int:
        return self.fib(n)