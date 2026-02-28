/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) 
    {
        // code here
        Node *curr=head;
        while(curr)
        {
            Node *copy=new Node(curr->data);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        
        curr=head;
        
        while(curr)
        {
            if(curr->random)
            curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        curr=head;
        Node *newHead=curr->next;
        
        while(curr)
        {
            Node *copy=curr->next;
            curr->next=copy->next ;
            if(copy->next)
            copy->next=copy->next->next;
            curr=curr->next;
        }
        
        return newHead;
    }
};