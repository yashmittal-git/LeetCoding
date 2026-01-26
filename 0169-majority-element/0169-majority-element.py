class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        majority = nums[0]
        count = 0
        for num in nums:
            if count == 0 or num == majority:
                majority = num
                count = count + 1
            else:
                count = count - 1
        return majority
        