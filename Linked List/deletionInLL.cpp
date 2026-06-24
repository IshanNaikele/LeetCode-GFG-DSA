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

Node *llCreationAtEnd(vector<int>&arr)
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

void deletionAtStart(Node *&head)
{
    if(head==NULL) return ;
    Node *temp=head;
    head=head->next;
    delete temp;
}

void deletionAtEnd(Node *&head)
{
    if(head==NULL) return;

    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        return;
    }
    
    Node *temp=head;
    while(temp->next->next)
        temp=temp->next;
       
    Node *del=temp->next; 
    temp->next=NULL;
    delete del;
}

void deletionAtParticularPos(Node *&head,int pos)
{
    if(head==NULL) return ;
    if(pos==1) 
    {
        deletionAtStart(head);
        return;
    }
    
    pos-=2;
     
    Node *temp=head;
    while(pos-- && temp->next) 
        temp=temp->next;
        
    if(temp->next==NULL) return;
    Node *del=temp->next;
    temp->next=temp->next->next;
    delete del;
}

int main()
{
    vector<int>arr={1,2,3,4,5};
    
    Node *head1=llCreationAtEnd(arr);
    Node *temp1=head1;
    cout<<"Linked List Creation :";
    while(temp1)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
    
    Node *head2=llCreationAtEnd(arr);
    Node *temp2=head2;
    
    deletionAtStart(temp2);
    cout<<"Deleting the first Node :";
    while(temp2)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    cout<<endl;
    
    Node *head3=llCreationAtEnd(arr);
    Node *temp3=head3;
    
    deletionAtEnd(temp3);
    cout<<"Deleting the last Node :";
    while(temp3)
    {
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }
    cout<<endl;
    
    
    for(int i=1;i<=arr.size()+2;i++)
    {
        Node *temp4=llCreationAtEnd(arr);
        deletionAtParticularPos(temp4,i);
        cout<<"Deleting at position "<<i<<" of the Linked List :";
        while(temp4)
        {
            cout<<temp4->data<<" ";
            temp4=temp4->next;
        }
        cout<<endl;
    }

    return 0;
}
