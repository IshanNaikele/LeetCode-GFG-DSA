#include<iostream>
using namespace std;

class Stack
{
    public:
    int *arr;
    int size;
    int total_size;
    Stack(int n)
    {
        total_size=n;
        arr=new int[n];
        size=0;
    }
    
    void push(int value)
    {
        if(size==total_size)
        {
            cout<<"Stack is Full So it's causing overflow condition "<<endl;
            return;
        }
        
        cout<<"The element "<<value<<" is pushed in the stack at index "<<size<<endl;
        arr[size]=value;
        size++;
    }
    
    void pop()
    {
        if(size==0) 
        {
            cout<<"Stack is Empty So it's causing Underflow Condition "<<endl;
            return ;
        }
        
        size--;
    }
    
    void top()
    {
        if(size==0) 
        {
            cout<<"Stack is Empty So 0 element is in there "<<endl;
            return ;
        }
        
        cout<<"The Element at the top of the stack is "<<arr[size-1]<<endl;
    }
    
    void isEmpty()
    {
        if(size==0) 
        {
            cout<<"Stack is Empty "<<endl;
        }
        else
        {
            cout<<"Stack is not Empty ."<<endl;
        }
    }
    
    void isFull()
    {
        if(size==total_size) 
        {
            cout<<"Stack is full "<<endl;
        }
        else
        {
            cout<<"Stack is not Full "<<endl;
        }
    }
    
    void isSize()
    {
        cout<<"The size of the stack is "<<size<<endl;
    }
    
};

int main()
{
    Stack s(10);
    s.isEmpty();
    s.pop();
    s.push(1);
    s.pop();
    s.top();
    s.push(20);
    s.top();
    s.isSize();
    s.isFull();
    s.isEmpty();
    return 0;
}
