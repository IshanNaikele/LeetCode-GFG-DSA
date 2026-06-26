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
 
void deleteAtEnd(Node *&head)
{
    if(head==NULL ) 
    {
        return; 
    }
    if(head->next==NULL) 
    {
        delete head;
        head=NULL;
        return;
    }
    Node *temp=head;
    while(temp->next)
      temp=temp->next;
    
    temp->prev->next=NULL;
    delete temp;
}
int main()
{
    vector<int>nums={1,2,3,4,5 };
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
     
    Node *head2=dllCreation(nums);
    Node *temp2=head2;
    Node *prev2=NULL;
    deleteAtEnd(temp2);
    cout<<"Printing Doubly Linked List after deleting at End through next pointer :";
    while(temp2)
    {
      cout<<temp2->data<<" ";
      prev2=temp2;
      temp2=temp2->next;
    }
    cout<<endl;
    cout<<"Printing Doubly Linked List after deleting at End through prev pointer :";
    while(prev2)
    {
        cout<<prev2->data<<" ";
        prev2=prev2->prev;
    }
    cout<<endl;
    
    return 0;
}