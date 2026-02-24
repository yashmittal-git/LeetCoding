class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        results = set()
        for i in range(0,len(nums)-2):
            if i > 0 and nums[i-1] == nums[i]:
                continue
            else:
                req_sum = 0 - nums[i]
                low = i + 1
                high = len(nums) - 1
                while low < high:
                    if nums[low] + nums[high] == req_sum:
                        results.add((nums[i],nums[low],nums[high]))
                        low = low + 1
                        high = high - 1
                    elif nums[low] + nums[high] < req_sum:
                        low = low + 1
                    else:
                        high = high - 1
        
        return list(results)