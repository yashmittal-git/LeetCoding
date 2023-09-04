# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        halfVals = []

        slow = head
        fast = head

        while fast and fast.next:
            halfVals.append(slow.val)
            slow = slow.next
            fast = fast.next.next
        
        maxSum = 0
        i = 0
        while slow:
            maxSum = max(maxSum,halfVals[-1-i]+slow.val)
            i += 1
            slow = slow.next
        
        return maxSum