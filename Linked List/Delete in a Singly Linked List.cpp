/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) 
    {
        // code here
        if(x==1) 
        {
            Node *newHead=head;
            head=head->next;
            delete newHead;
            return head;
        }
        x-=2;
        Node *temp=head;
        while(x--)             temp=temp->next;
        
        Node *del=temp->next;
        temp->next=del->next;
        delete del;
        
        return head;
    }
};