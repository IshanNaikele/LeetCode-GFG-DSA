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
    Node* sortedMerge(Node* head1, Node* head2) 
    {
        // code here
        Node *head=NULL,*tail=NULL;
        
        while(head1 && head2)
        {
            if(head1->data <=head2->data)
            {
                if(head==NULL)
                { 
                    head=head1;
                    tail=head1;
                }
                else
                {
                    tail->next=head1;
                    tail=tail->next;
                }
                head1=head1->next;
            }
            else
            {
                if(head==NULL)
                { 
                    head=head2;
                    tail=head2;
                }
                else
                {
                    tail->next=head2;
                    tail=tail->next;
                }
                head2=head2->next;
            }
        }
        
        if(head1)  tail->next=head1;
        else       tail->next=head2;
        
        
        return head;
    }
};