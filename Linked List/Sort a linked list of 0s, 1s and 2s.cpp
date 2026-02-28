/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) 
    {
        Node dummyZero(0),dummyOne(0),dummyTwo(0);
        Node *zero=&dummyZero,*one=&dummyOne,*two=&dummyTwo;
        
        
        while(head)
        {
            if(head->data==0)
            {
                zero->next=head;
                zero=zero->next;
            }
            else if(head->data==1)
            {
                one->next=head;
                one=one->next;
            }
            else
            {
                two->next=head;
                two=two->next;
            }
            head=head->next;
        }
        
        two->next=NULL;
        one->next=dummyTwo.next;
        zero->next=dummyOne.next;
        
        return dummyZero.next;
    }
};
