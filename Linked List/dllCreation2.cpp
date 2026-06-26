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
    return 0;
}

