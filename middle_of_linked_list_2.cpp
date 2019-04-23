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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast!=NULL)
        { 
            if(fast->next==NULL)
                return slow;
            if(fast->next!=NULL&&fast->next->next==NULL)
                return slow->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        return head;
    }
};
