/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) 
    {
        // code here
        Node *temp=head;
        while(p--)
        temp=temp->next;
        
        Node *newNode=new Node(x);
        if(!temp->next)  
        {
            temp->next=newNode;
            newNode->prev=temp;
            return head;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
 
        return head;
    }
};