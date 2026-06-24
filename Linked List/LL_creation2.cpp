#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public :
    int data;
    Node *next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

Node *llCreationAtStart(vector<int>&arr)
{
    Node *head=NULL;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        Node *newTemp=new Node(arr[i]);
        newTemp->next=head;
        head=newTemp;
    }
    return head;
}

int main()
{
    vector<int>arr={1,2,3,4,5};
    Node *head=llCreationAtStart(arr);
    Node *temp=head;
    
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}