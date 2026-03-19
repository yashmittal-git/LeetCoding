class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)

        count = defaultdict(int)
        good = 0

        for i in range(n):
            key = nums[i] - i
            good = good + count[key]
            count[key] =count[key] + 1

        return int((n * (n-1) / 2) - good)