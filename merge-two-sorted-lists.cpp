// 21. Merge Two Sorted Lists
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        ListNode *head,*temp;
        if(l1->val<l2->val)
        {
            head=l1;
            l1=l1->next;
        }
        else
        {
            head=l2;
            l2=l2->next;
        }
        temp=head;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        while(l1)
        {
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2)
        {
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
        return head;
    }
};