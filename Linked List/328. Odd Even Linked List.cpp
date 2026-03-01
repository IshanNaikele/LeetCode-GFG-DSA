//Approach 1 :The same way sorting of 0,1 & 2 are done .(Using Dummy Nodes)
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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode oddDummy(0),evenDummy(0);
        ListNode *odd=&oddDummy,*even=&evenDummy;
        ListNode *temp=head;
        int i=0;
        while(temp)
        {
            if(i%2==0)
            {
                odd->next=temp;
                odd=temp;
            }
            else
            {
                even->next=temp;
                even=temp;
            }
            i++;
            temp=temp->next;
        }
        even->next=NULL;
        odd->next=evenDummy.next;
        return oddDummy.next;
    }
};