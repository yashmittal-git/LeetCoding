class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        maxSumYet = nums[0]

        for num in nums[1:]:
            maxSumYet = max(maxSumYet+num,num)
            maxSum = max(maxSumYet,maxSum)
        
        return maxSum