/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) 
    {
        //  Code Here
        Node *curr1=head1,*curr2=head2;
        while(curr1!=curr2)
        {
            curr1=(curr1->next==NULL)?head2:curr1->next;
            curr2=(curr2->next==NULL)?head1:curr2->next;
        }
        return curr1;
    }
};