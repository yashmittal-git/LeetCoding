# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        i = 1
        j = n+1
        mid = i

        while(i<j):
            mid = int(i - (i-j)/2)
            if isBadVersion(mid) == True:
                j = mid
            else:
                i = mid + 1
        
        return j