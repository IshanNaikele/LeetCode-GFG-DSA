/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
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
    
    void removeLoop(Node* head) 
    {
        // code here
        Node *slow=detectLoop(head);
        if(slow==NULL) return  ;
        Node *fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        while(slow->next!=fast)   slow=slow->next;
        slow->next=NULL;
         
    }

};