/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) 
    {
        // code here
        Node *temp=head,*previ=NULL;
        while(temp)
        {
            Node *fut=temp->next;
            temp->next=previ;
            temp->prev=fut;
            previ=temp;
            temp=fut;
        }
        
        return previ;
    }
};