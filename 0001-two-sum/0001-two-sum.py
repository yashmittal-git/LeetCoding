class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hmap = {}
        for i, num in enumerate(nums):
            if target - num in hmap:
                return [i, hmap[target - num]]
            hmap[num] = i
        