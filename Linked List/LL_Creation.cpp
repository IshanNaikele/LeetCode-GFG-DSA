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

int main()
{
    vector<int>arr={1,2,3,4,5};
   
    Node *temp=llCreationAtEnd(arr);
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}