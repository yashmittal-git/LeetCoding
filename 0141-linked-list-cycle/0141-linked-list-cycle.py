# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        if not slow or not slow.next:
            return False

        fast = head.next

        while (fast and fast.next) and slow != fast:
            slow = slow.next
            fast = fast.next.next
        
        if not (fast and fast.next):
            return False
        
        return True