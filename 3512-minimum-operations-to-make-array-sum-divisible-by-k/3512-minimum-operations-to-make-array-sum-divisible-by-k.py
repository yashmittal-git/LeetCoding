class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        for num in nums:
            ans = ans + num
        
        return ans%k
        