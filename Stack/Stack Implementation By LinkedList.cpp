#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

class Stack
{
    public:
    int size;
    Node *top;
    
    Stack()
    {
        size=0;
        top=NULL;
    }
    
    void push(int data)
    {
        Node *temp=new Node(data);
        temp->next=top;
        top=temp;
        size++;
        
        cout<<"The element "<<top->data <<" is pushed into the stack "<<endl;
    }
    
    void pop()
    {
        if(size==0)
        {
            cout<<"Stack is Empty So it's causing Underflow Condition "<<endl;
            return;
        }
        
        cout<<"The element "<<top->data <<" is popped from the stack "<<endl;
        Node *temp=top;
        top=top->next;
        delete temp;
        size--;
    }
    
    void peek()
    {
        if(top==NULL) 
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        
        cout<<"The element at the top of the stack is "<<top->data<<endl;
        
    }
    void isSize()
    {
        cout<<"The size of the Stack is "<<size<<endl;
    }
    
    void isEmpty()
    {
        if(size==0)
        cout<<"Stack is Empty "<<endl;
        else
        cout<<"Stack is not Empty"<<endl;
    }
    
};


int main()
{
    Stack s;
    s.isEmpty();
    s.pop();
    s.push(1);
    s.pop();
    s.peek();
    s.push(20);
    s.peek();
    s.isSize();
    s.isEmpty();
    return 0;
}
