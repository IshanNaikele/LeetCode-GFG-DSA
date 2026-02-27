//Approach 1 :Similar to the Rotate Array 

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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return head;
        vector<int>store;
        ListNode *curr=head;
        int size=0;
        while(curr)
        {
            store.push_back(curr->val);
            curr=curr->next;
            size++;
        }
        k=k%size;

        reverse(store.begin(),store.end());
        reverse(store.begin(),store.begin()+k);
        reverse(store.begin()+k,store.end());

        curr=head;
        int i=0;
        while(curr)
        {
            curr->val=store[i];
            curr=curr->next;
            i++;
        }

        return head;
    }
};

//Approach 2 :Making array Circular and Solving it .

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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next || k==0 ) return head;
        ListNode *curr=head;
        int size=1;
        while(curr->next)
        {
            curr=curr->next;
            size++;
        }

        k=k%size;
        curr->next=head;//Making LL circular 
        int jump=size-k-1;
        curr=head;
        while(jump--)    curr=curr->next;

        head=curr->next;
        curr->next=NULL;
        return head;
    }
};