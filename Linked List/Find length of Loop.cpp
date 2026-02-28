/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    
    Node *detectLoop(Node *head)
    {
        Node *fast=head,*slow=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) return slow;
        }
        return NULL;
    }
    
    int lengthOfLoop(Node *head) 
    {
        Node *slow=detectLoop(head);
        if(slow==NULL) return 0;
        
        Node *temp=head;
        while(slow!=temp)
        {
            slow=slow->next;
            temp=temp->next;
        }
        
        int count=1;
        while(temp->next!=slow)
        {
            temp=temp->next;
            count++;
        }
        
        return count;
    }
};