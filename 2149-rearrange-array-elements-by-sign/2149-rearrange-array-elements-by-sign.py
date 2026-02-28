class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pve = 0
        nve = 1
        result = [0] * len(nums)
        for i in range(len(nums)):
            if nums[i] > 0:
                result[pve] = nums[i]
                pve = pve + 2
            else:
                result[nve] = nums[i]
                nve = nve + 2
        
        return result