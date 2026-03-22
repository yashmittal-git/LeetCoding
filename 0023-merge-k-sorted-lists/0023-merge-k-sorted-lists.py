# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge2Lists(self, list1, list2):
        list3 = ListNode()
        head = list3
        while list1 and list2:
            if list1.val<list2.val:
                list3.next = list1
                list1 = list1.next
            else:
                list3.next = list2
                list2 = list2.next
            list3 = list3.next
        while list1:
            list3.next = list1
            list1 = list1.next
            list3 = list3.next
        while list2:
            list3.next = list2
            list2 = list2.next
            list3 = list3.next
        
        return head.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not len(lists):
            return None
        mergedList = lists[0]
        for i in range(1,len(lists)):
            mergedList = self.merge2Lists(mergedList,lists[i])
        return mergedList
        

        