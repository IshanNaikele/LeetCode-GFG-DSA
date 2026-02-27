//Approach 1 :
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
    ListNode* reverseList(ListNode* head) 
    {
        //Approach 1:Store the data in the vector and then change the data .

        ListNode *temp=head;
        vector<int>store;
        while(temp)
        {
            store.push_back(temp->val);
            temp=temp->next;
        }

        reverse(store.begin(),store.end());
        
        temp=head;
        int i=0;
        while(temp)
        {
            temp->val=store[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};


//Approach 2 :
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
    ListNode* reverseList(ListNode* head) 
    {
        //Approach 2: Reverse the direction of each node .

        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp)
        {
            ListNode *tail=temp->next;
            temp->next=prev;
            prev=temp;
            temp=tail;
        }
        return prev;
    }
};


//Approach 3 :
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

    ListNode* reverseLL(ListNode *curr,ListNode *prev)
    {
        if(curr==NULL) return prev;
        ListNode *fut=curr->next;
        curr->next=prev;
        
        return reverseLL(fut,curr);
    }
    ListNode* reverseList(ListNode* head) 
    {
        //Approach 3: Reverse the direction of each node using recursion. 
        return reverseLL(head, NULL);
    }
};