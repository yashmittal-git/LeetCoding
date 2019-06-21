// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0),*temp=head;
        int carry=0,sum=0;
        while(l1||l2)
        {   int x=!l1?0:l1->val;
            int y=!l2?0:l2->val;
            sum=x+y+carry;
            carry=sum/10;
            sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
            if(l1)  l1=l1->next;
            if(l2)  l2=l2->next;
        }
        if(carry>0)
            temp->next=new ListNode(carry);
        return head->next;
    }
};