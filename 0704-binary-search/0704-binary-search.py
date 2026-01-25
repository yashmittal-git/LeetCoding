class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i = 0
        j = len(nums) - 1

        while i <= j:
            mid = int(i + (j-i)/2)
            if target == nums[mid]:
                return mid
            if target < nums[mid]:
                j = mid - 1
            else:
                i = mid + 1
        return -1
        