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

/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution
{
public:

    Node* reverseList(Node* head)
    {
        Node *prev=NULL;

        while(head)
        {
            Node *next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }

        return prev;
    }

    int length(Node *head)
    {
        int cnt=0;

        while(head)
        {
            cnt++;
            head=head->next;
        }

        return cnt;
    }

    Node* addTwoLists(Node* head1, Node* head2)
    {
        while(head1 && head1->data==0)
            head1=head1->next;

        while(head2 && head2->data==0)
            head2=head2->next;

        if(!head1) return new Node(0);
        if(!head2) return head1;

        int n=length(head1);
        int m=length(head2);

        // Use longer list as result container
        if(m>n)
            swap(head1,head2);

        head1=reverseList(head1);
        head2=reverseList(head2);

        Node *ans=head1;

        Node *prev=NULL;

        int carry=0;

        while(head1 || head2 || carry)
        {
            int sum=carry;

            if(head1)
                sum+=head1->data;

            if(head2)
                sum+=head2->data;

            if(head1)
            {
                head1->data=sum%10;

                prev=head1;

                head1=head1->next;
            }
            else
            {
                prev->next=new Node(sum%10);
                prev=prev->next;
            }

            if(head2)
                head2=head2->next;

            carry=sum/10;
        }

        ans=reverseList(ans);

        while(ans->next && ans->data==0)
            ans=ans->next;

        return ans;
    }
};