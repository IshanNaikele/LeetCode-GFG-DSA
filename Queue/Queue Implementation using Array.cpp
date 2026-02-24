#include<iostream>
#include<queue>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front=-1,rear=-1;
    public:
    Queue(int n)
    {
        arr=new int[n];
        size=n;
    }
    
    void push(int x)
    {
        if(front==-1) 
        {
            front = rear = 0;
            arr[front]=x;
            cout<<"Element is pushed into the queue "<<arr[front%size]<<endl;
        }
        else
        {
            if((rear+1)%size==front)  
            {
                cout<<"Queue Overflow "<<endl;
                return;
            }
            rear = (rear + 1) % size;
            arr[rear]=x;
            cout<<"Element is pushed into the queue "<<arr[rear%size]<<endl;
        }
    }
    
    void pop()
    {
        if(front==-1)
        {
            cout<<"Queue Underflow "<<endl;
            return;
        }
        
        cout<<"Element is popped from the Queue :" <<arr[front]<<endl;
        
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    
    bool isEmpty()
    {
        cout<<"Queue is Empty "<<endl;
        return front==-1;
    }
    
    int isFront()
    {
        if(front==-1) 
        {
            cout<<"Queue is Empty so no element "<<endl;
            return -1;
        }
        cout<<"THe element at the front is :"<<arr[front ]<<endl;
        return arr[front];
    }
    
    int isBack()
    {
        if(front==-1) 
        {
            cout<<"Queue is Empty so no element "<<endl;
            return -1;
        }
        cout<<"THe element at the back is :"<<arr[rear ]<<endl;
        return arr[rear ];
    }
    
    int getSize()
    {
        if(front == -1)
            return 0;
    
        if(rear >= front)
        {
            cout<<"Size of the queue is "<<rear-front+1<<endl;
            return rear - front + 1;
        }
        else
        {
            cout<<"Size of the queue is "<<(size - front) + (rear + 1)<<endl;
            return (size - front) + (rear + 1);
        }
    }
    
};

int main()
{
    Queue que(3);
  

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