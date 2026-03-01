/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution 
{
  public:
    Node *reverseLL(Node *curr,Node *prev)
    {
        if(curr==NULL) return prev;
        Node *fut=curr->next;
        curr->next=prev;
        prev=curr;
        return reverseLL(fut,curr);
    }
    Node* addOne(Node* head) 
    {
        // Your Code here
        Node *l1=reverseLL(head,NULL);
        Node *temp=l1,*prev=NULL;
        int carry=1;
        while(carry && l1)
        {
             int sum=l1->data+carry;
             l1->data=sum%10;
             carry=sum/10;
             prev=l1;
             l1=l1->next;
        }
        if(carry)
        {
            Node *newNode=new Node(1);
            prev->next=newNode;
        }
        return reverseLL(temp,NULL);
    }
};