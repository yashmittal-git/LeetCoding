class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1]

        for i in range(len(nums) - 1):
            result.append(result[i]*nums[i])
        
        suffix = nums[-1]
        for i in range(len(nums)-2,-1,-1):
            result[i] = result[i]*suffix
            suffix= suffix * nums[i]
        
        return result
        
        