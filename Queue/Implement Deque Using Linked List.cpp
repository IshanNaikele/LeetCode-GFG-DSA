#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *prev,*next;
    Node(int value)
    {
        data=value;
        prev=next=NULL;
    }
};

class Deque
{
    Node *front,*rear;
    public:
    Deque()
    {
        front=rear=NULL;
    }
    
    void push_front(int x)
    {
        if(front==NULL)
        {
            front=rear=new Node(x);
            return;
        }
        
        Node *temp=new Node(x);
        temp->next=front;
        front->prev=temp;
        front=temp;
    }
    
    void push_back(int x)
    {
        if(front==NULL)
        {
            front=rear=new Node(x);
            return;
        }
        
        Node *temp=new Node(x);
        temp->prev=rear;
        rear->next=temp;
        rear=temp;
    }
    
    void pop_front()
    {
        if(front==rear || front==NULL) 
        {
            front=rear=NULL;
            return;
        }
        Node *temp=front;
        front=front->next;
        front->prev=NULL;
        delete temp;
    }
    
    void pop_back()
    {
        if(front==rear || front==NULL) 
        {
            front=rear=NULL;
            return;
        }
        
        Node *temp=rear;
        rear=rear->prev;
        rear->next=NULL;
        delete temp;
    }
    
    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
     Deque dq;

    cout << "Push back 10\n";
    dq.push_back(10);
    dq.display();

    cout << "Push back 20\n";
    dq.push_back(20);
    dq.display();

    cout << "Push front 5\n";
    dq.push_front(5);
    dq.display();

    cout << "Push front 2\n";
    dq.push_front(2);
    dq.display();

    cout << "Pop front\n";
    dq.pop_front();
    dq.display();

    cout << "Pop back\n";
    dq.pop_back();
    dq.display();

    cout << "Pop front\n";
    dq.pop_front();
    dq.display();

    cout << "Pop back\n";
    dq.pop_back();
    dq.display();

    return 0;
}