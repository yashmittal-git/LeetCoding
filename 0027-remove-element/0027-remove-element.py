class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i, j = 0, len(nums) - 1

        while i<=j:
            if nums[j] == val:
                j -= 1
                continue

            if nums[i] == val:
                nums[i] = nums[j]
                j -= 1
            i += 1
            
        return i