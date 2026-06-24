#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

Node *llCreation(vector<int>&arr)
{
    Node *head=NULL;
    Node *temp=head;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(temp==NULL)
        {
            head=new Node(arr[i]);
            temp=head;
        }
        else
        {
            temp->next=new Node(arr[i]);
            temp=temp->next;
        }
    }
    return head;
}

void insertAtStart(Node *&head,int num)
{
    Node *temp=new Node(num);
    if(head==NULL)  
    head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insertAtEnd(Node *&head,int num)
{
    Node *temp=new Node(num);
    Node *newHead=head;
    if(head==NULL) {
        head=temp;
        return;
    }
    
    while(newHead->next)
          newHead=newHead->next;
    newHead->next=temp;
}

void insertAtParticularPos(Node *&head,int pos,int num)
{
    // Insert at beginning
    if(pos==1)
    {
        insertAtStart(head,num);
        return;
    }

    Node *temp=head;

    for(int i=1;i<pos-1 && temp;i++)
    {
        temp=temp->next;
    }

    // Invalid position
    if(temp==NULL)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    Node *newTemp=new Node(num);

    newTemp->next=temp->next;
    temp->next=newTemp;
}

int main()
{
    vector<int>arr={1,2,3,4,5};
    Node *head1=llCreation(arr);
    
    Node *temp1=head1;
    cout<<"Linked List Creation :";
    while(temp1)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
    
    Node *head2=llCreation(arr);
    Node *temp2=head2;
    int num=6;
    insertAtStart(temp2,num);
    
    cout<<"Inserting "<<num <<" at start of the Linked List :";
    while(temp2)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    cout<<endl;
    
    Node *head3=llCreation(arr);
    
    Node *temp3=head3;
    num=6;
    insertAtEnd(temp3,num);
    cout<<"Inserting "<<num <<" at end of the Linked List :";
    while(temp3)
    {
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }
    cout<<endl;
    
     
    for(int i=1;i<=arr.size()+2;i++)
    {
        Node *temp4=llCreation(arr);
        insertAtParticularPos(temp4,i,num);
        cout<<"Inserting "<<num <<" at position "<<i<<" of the Linked List :";
        while(temp4)
        {
            cout<<temp4->data<<" ";
            temp4=temp4->next;
        }
        cout<<endl;
    }
    return 0;
}