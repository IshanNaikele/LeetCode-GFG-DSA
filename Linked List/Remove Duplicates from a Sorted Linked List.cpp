/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) 
    {
        Node *temp=head;
        while(temp->next)
        {
            if(temp->data==temp->next->data)
            {
                Node *del=temp->next;
                temp->next=temp->next->next;
                delete del;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};