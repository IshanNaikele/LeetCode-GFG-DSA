#include<iostream>
using namespace std;

class Deque
{
    int front,rear;
    int *arr;
    int total_size,size;
    public:
    Deque(int n)
    {
        arr=new int[n];
        front=rear=-1;
        total_size=n;
        size=0;
    }
    
    bool isEmpty()
    {
        return front==-1;
    }
    
    bool isFull()
    {
        return (rear+1)%total_size==front;
    }
    void push_front(int x)
    {
        //
        if(isFull()) return ;
        else if(isEmpty()) 
        {
            front=rear=0;
            arr[front]=x;
        }
        else
        {
            front=(front-1+total_size)%total_size;
            arr[front]=x;
        }
        
        size++;
    }
    
    void push_back(int x)
    {
        if(isFull()) return ;
        else if(isEmpty()) 
        {
            front=rear=0;
            arr[front]=x;
        }
        else
        {
            rear=(rear+1+total_size)%total_size;
            arr[rear]=x;
        }
        size++;
    }
    
    void pop_front()
    {
        if(isEmpty()) return;
        if(front==rear)
        {
            front = rear = -1;
        }
        else
        {
            front=(front+1+total_size)%total_size;
        }
        size--;
    }
    
    void pop_back()
    {
        if(isEmpty()) return;
        if(front==rear) front=rear=-1;
        else
        {
            rear=(rear-1+total_size)%total_size;
        }
        size--;
    }
    
    void isSize()
    {
        if(front==-1) 
        {
            cout<<"Deque is Empty"<<endl;
            return;
        }
        cout<<"The size of the Deque is "<<size<<endl;
    }
    
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % total_size;
        }
        cout << endl;
    }
    
};
int main()
{
    Deque dq(5);
    dq.isSize();
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(2);

    dq.display();   // 2 5 10 20
    dq.isSize();
    dq.pop_front();
    dq.display();   // 5 10 20
    dq.isSize();
    dq.pop_back();
    dq.display();   // 5 10
    dq.isSize();
    dq.pop_back();
    dq.display();   // 5 
    dq.isSize();
    dq.pop_back();
    dq.display();   // 
    
    dq.isSize();
    return 0;
}