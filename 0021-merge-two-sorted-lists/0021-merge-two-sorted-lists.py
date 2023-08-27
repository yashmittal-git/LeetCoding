# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return None
        
        if not list1:
            return list2
        
        if not list2:
            return list1
        
        mergedList = ListNode()
        mergedListItr = mergedList
        while list1 and list2:
            if list1.val < list2.val:
                mergedListItr.next = list1
                list1 = list1.next
            else:
                mergedListItr.next = list2
                list2 = list2.next
            
            mergedListItr = mergedListItr.next

        while list1:
            mergedListItr.next = list1
            list1 = list1.next
            mergedListItr = mergedListItr.next

        while list2:
            mergedListItr.next = list2
            list2 = list2.next
            mergedListItr = mergedListItr.next

        return mergedList.next