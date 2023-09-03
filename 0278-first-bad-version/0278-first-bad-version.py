# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        i, j = 1, n
        mid = i + j // 2

        while (i < j):
            mid = (i+j) // 2

            if isBadVersion(mid) == True:
                j = mid
            else:
                i = mid + 1 

        return i    

        