/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseLL(ListNode *curr,ListNode *prev)
    {
        if(curr==NULL) return prev;
        ListNode *fut=curr->next;
        curr->next=prev;
        prev=curr;
        return reverseLL(fut,curr);
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow=head,*fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast!=NULL) slow=slow->next;
        ListNode *revLL=reverseLL(slow,NULL);
        while(revLL)
        {
            if(revLL->val!=head->val) return false;
            revLL=revLL->next;
            head=head->next;
        }
        return true;
    }
};