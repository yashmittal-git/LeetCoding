# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def printlist(self, ll, name):
        curr = ll
        print(f"ll {name}: ", end=" ")
        while curr:
            print(curr.val, end = " ")
            curr = curr.next
        print()
        
    def mergeList(self, l1, l2):
        if not l2:
            return l1
        if not l1:
            return l2
        ll = ListNode()
        curr = ll
        while l1 and l2:
            if l1.val< l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        while l1:
            curr.next = l1
            curr = curr.next
            l1 = l1.next
        while l2:
            curr.next = l2
            curr = curr.next
            l2=l2.next

        return ll.next
        
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        slow = head
        fast = head
        prev = None

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None
        
        l1 = self.sortList(head) 
        l2 = self.sortList(slow)

        return self.mergeList(l1,l2)
        