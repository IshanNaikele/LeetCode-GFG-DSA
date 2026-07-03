class Solution {
public:
    int winner(int n,int k)
    {
        if(n==1) return 0;
        return (winner(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) 
    {
        return winner(n,k)+1;
    }
};

//Using Linked List 

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

Node *createLL(vector<int>& nums,Node *head)
{
    Node *temp=head;
    int n=nums.size();
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
            temp=temp->next;
        }
    }
    
    temp->next=head;
    return temp;
}

int findWinner(int k,int n,Node *last)
{
    Node *temp=last;
    
    while(n>1)
    {
        int moves = (k - 1) % n;
        for(int i=0;i<moves;i++)
          temp=temp->next;
        
        Node *del=temp->next;
        if(del==last) last=temp;
        temp->next=del->next;
        delete del;
        n--;
    }
    int ans = temp->data;
    delete temp;
    return ans;
}
int main()
{
    vector<int>nums={1,2,3,4,5};
    int n=nums.size(),k=2;
    //Get the last Node
    Node *last=createLL(nums,NULL);
    Node *head=last->next;
    Node *temp=head;
    //Checking Circular list formed properly ora not
    
    for(int i=0;i<n*2;i++)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<endl;
    cout<<findWinner(k,n,last);
    
    return 0;
}