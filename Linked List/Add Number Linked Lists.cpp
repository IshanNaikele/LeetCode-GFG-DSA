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
    
    Node *reverseLL(Node *curr,Node *prev)
    {
        if(curr==NULL) return prev;
        Node *fut=curr->next;
        curr->next=prev;
        prev=curr;
        return reverseLL(fut,curr);
    }
    
    Node* addTwoLists(Node* head1, Node* head2) 
    {
        
        Node *list1=reverseLL(head1,NULL);
        Node *list2=reverseLL(head2,NULL);
        Node *head=NULL,*tail=NULL;
        int carry=0;
        
        while(list1 || list2 || carry)
        {
            int sum=carry;
            if(list1)
            {
               sum+=list1->data;
               list1=list1->next;
            }
            
            if(list2)
            {
                sum+=list2->data;
                list2=list2->next;
            }
            
            carry=sum/10;
            Node *newNode=new Node(sum%10);
            if(head==NULL)
            {
                head=newNode;
                tail=newNode;
            }
            else
            {
                tail->next=newNode;
                tail=tail->next;
            }
        }
        
        Node *ans=reverseLL(head,NULL);
        while(ans->data==0 && ans->next)    ans=ans->next;
        return ans;
    } 
};

