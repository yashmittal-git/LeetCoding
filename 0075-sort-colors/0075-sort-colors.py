class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        red = 0
        blue = n-1

        i = 0

        while i <= blue:
            if nums[i]==0:
                nums[red], nums[i] = nums[i], nums[red]
                red = red + 1
                i = i + 1
            elif nums[i]==2:
                nums[blue],nums[i] = nums[i], nums[blue]
                blue = blue - 1
            else:
                i = i + 1