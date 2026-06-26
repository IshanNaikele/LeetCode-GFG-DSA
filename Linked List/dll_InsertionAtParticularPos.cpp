#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *next,*prev;
    Node (int value)
    {
        data=value;
        prev=next=NULL;
    }
};

Node *dllCreation(vector<int>&nums)
{
    int n=nums.size();
    Node *head=NULL;
    Node *temp=head;
    
    for(int i=0;i<n;i++)
    {
        Node *newNode=new Node(nums[i]);
        if(head==NULL)
        {
            head=newNode;
            temp=head;
        }
        else
        {
             temp->next=newNode;
             newNode->prev=temp;
             temp=temp->next;
        }
    }
    return head;
}
void insertAtStart(Node *&head,int num)
{
    Node *newNode=new Node(num);
    if(head)
    {
        newNode->next=head;
        head->prev=newNode;
    }
     head=newNode;
}

void insertAtEnd(Node *&head,int num)
{
    Node *temp=head;
    Node *newNode=new Node(num);
    if(head==NULL) 
    {
        head=newNode;
        return;
    }
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertAtParticularPos(Node *&head,int pos,int num)
{
    
    if(pos==1) 
    {
        insertAtStart(head,num);
        return;
    }
     
     
    Node *temp=head;
    int jump=pos-2;
    while(jump-- && temp)
       temp=temp->next;
      
    if(temp==NULL ) 
    {
        cout<<”Invalid Position”<<endl;
        return;
    }
    if(temp->next==NULL)
    {
        insertAtEnd(head,num);
        return ;
     }
    Node *newNode=new Node(num);
    Node *nxt=temp->next;
    nxt->prev=newNode;
    newNode->prev=temp;
    newNode->next=nxt;
    temp->next=newNode;
}

int main()
{
    vector<int>nums={1,2,3,4,5};
    Node *head1=dllCreation(nums);
    Node *temp1=head1;
    Node *prev1=NULL;
    cout<<"Printing Doubly Linked List Element through next pointer :";
    while(temp1)
    {
      cout<<temp1->data<<" ";
      prev1=temp1;
      temp1=temp1->next;
    }
    cout<<endl;
    cout<<"Printing Doubly Linked List Element through prev pointer :";
    while(prev1)
    {
        cout<<prev1->data<<" ";
        prev1=prev1->prev;
    }
    cout<<endl<<endl<<endl;
    cout<<"_________________________________________________________________"<<endl;
    int num=6;
    for(int i=1;i<=nums.size()+1;i++)
    {
        Node *head2=dllCreation(nums);
        Node *temp2=head2;
        Node *prev2=NULL;
        insertAtParticularPos(temp2,i,num);
        cout<<"Printing Doubly Linked List after inserting "<<num<<" at positon "<<i<<" through next pointer :";
        while(temp2)
        {
          cout<<temp2->data<<" ";
          prev2=temp2;
          temp2=temp2->next;
        }
        cout<<endl;
        cout<<"Printing Doubly Linked List after inserting "<<num<<" at positon "<<i<<" through next pointer :";
        while(prev2)
        {
            cout<<prev2->data<<" ";
            prev2=prev2->prev;
        }
        cout<<endl;
    }
    return 0;
}
