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
        ListNode* temp=head;
        int c=0;
        while(temp->next!=NULL)
        {   c++;
            temp=temp->next;
        }
        ListNode* temp2=head;
        for(int i=0;i<0.5*c;i++)
            temp2=temp2->next;
        return temp2;
    }
};
