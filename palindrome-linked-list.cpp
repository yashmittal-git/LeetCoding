// 234. Palindrome Linked List
// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head)
    {   ListNode *prev=NULL,*curr=head,*nexa;
        while(curr){
            nexa=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexa;
        }
        return prev;
    }
    ListNode* findMid(ListNode* head){
        ListNode *fast=head,*slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL)
            return slow;
        else    slow=slow->next;
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* forward=head;
        ListNode* reversed=findMid(head);
        reversed=reverse(reversed);
        while(reversed!=NULL){
            if(forward->val!=reversed->val)
                return false;
            forward=forward->next;
            reversed=reversed->next;
        }
        return true;
        
    }
    
};