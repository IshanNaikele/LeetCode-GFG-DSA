#include<iostream>
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

class Queue
{
    Node *front,*rear;
    int size;
    public:
    Queue()
    {
        front=rear=NULL;
        size=0;
    }
    
    bool isEmpty()
    {
        if(size==0)
        cout<<"Queue is empty"<<endl;
        return front==NULL;
    }
    void push(int x)
    {
        if(front==NULL) 
        {
            front=new Node(x);
            rear=front;
            cout<<"The Element is pushed in the Queue :"<<x<<endl;
        }
        else
        {
            rear->next=new Node(x);
            rear=rear->next;
            cout<<"The Element is pushed in the Queue :"<<x<<endl;
        }
        size++;
    }
    
    void pop()
    {
        if(front==NULL) return;
        cout<<"The Element is popped in the Queue :"<<front->data<<endl;
        front=front->next;
        size--;
    }
    
    int isFront()
    {
        if(front==NULL) 
        {
            cout<<"Queue is Empty so no element "<<endl;
            return -1;
        }
        cout<<"THe element at the front is :"<<front->data<<endl;
        return front->data;
    }
    
    int isBack()
    {
        if(front==NULL) 
        {
            cout<<"Queue is Empty so no element "<<endl;
            return -1;
        }
        cout<<"THe element at the back is :"<<rear->data<<endl;
        return rear->data;
    }
    
    int getSize()
    {
        cout<<"The Size of the Queue is "<<size<<endl;
        return size;
    }
    
};
int main()
{
    Queue que;
  

    que.push(10);
    que.push(20);
    que.getSize();
    que.push(30);
    que.getSize();
    // This should cause overflow
    que.push(40);

    que.pop();
    que.pop();
    que.getSize();
    que.pop();

    // This should cause underflow
    que.pop();

    que.isEmpty();
    que.push(3);
    que.isFront();
    que.isBack();
    que.push(8);
    que.push(9);
    que.isBack();
    que.push(4);
    que.isBack();
    que.pop();
    que.isEmpty();
    return 0;
   
}