# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head

        prev = None
        
        while fast and fast.next:
            fast = fast.next.next
            slow.next, prev, slow = prev, slow, slow.next
        
        maxSum = 0
        while prev:
            maxSum = max(maxSum,prev.val+slow.val)
            prev, slow = prev.next, slow.next
        
        return maxSum