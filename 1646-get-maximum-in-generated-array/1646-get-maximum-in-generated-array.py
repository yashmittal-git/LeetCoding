class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n < 2:
            return n
        arr = [0,1]
        ans = arr[-1]
        for i in range(2,n+1):
            if i%2 == 0:
                arr.append(arr[int(i/2)])
            else:
                arr.append(arr[int(i/2)] + arr[int(i/2) + 1])
            ans = max(ans, arr[-1])
        return ans
        