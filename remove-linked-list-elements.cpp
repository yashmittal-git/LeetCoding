// 203. Remove Linked List Elements

// Remove all elements from a linked list of integers that have value val.

// Example:

// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5


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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        while(head->val==val)
        {   head=head->next;
            if(head==NULL)  return head;
        }
        
        ListNode* temp=head,*temp2=temp->next;
        while(temp2!=NULL)
        {   
            if(temp2->val==val) {
                temp->next=temp2->next;
                temp2=temp->next;
            }
            else    {
                temp=temp2;
                temp2=temp2->next;
            }
        }
        return head;
    }
};