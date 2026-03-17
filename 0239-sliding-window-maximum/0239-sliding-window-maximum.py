from collections import deque

class MaxQ:
    def __init__(self):
        self.q = deque()

    def remove(self, element):
        if self.q[0] == element:
            self.q.popleft()
        
    def add(self, element):
        while self.q and self.q[-1] < element:
            self.q.pop()
        self.q.append(element)
    
    def getmax(self):
        return self.q[0]

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = MaxQ()

        for i in range(k):
            q.add(nums[i])
        
        ans = []
        for i in range(k,len(nums)):
            ans.append(q.getmax())
            q.remove(nums[i-k])
            q.add(nums[i])
        
        ans.append(q.getmax())
        return ans