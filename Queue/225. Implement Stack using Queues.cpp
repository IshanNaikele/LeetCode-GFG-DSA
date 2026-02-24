class MyStack 
{
public:

    queue<int>q;
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q.push(x);
    }
    
    int pop() 
    {
        int n=q.size()-1;
        while(n--) 
        {
            q.push(q.front());
            q.pop();
        }
        if(!q.empty())
        {
            int front=q.front();
            q.pop();
            return front;
        }
        return -1;
    }
    
    int top() 
    {
        int n=q.size()-1;
        while(n--) 
        {
            q.push(q.front());
            q.pop();
        }
        if(!q.empty())
        {       
            int front=q.front();
            q.pop();
            q.push(front);
            return front;
        }
        return -1;
    }

    
    bool empty() 
    {
        return q.size()==0  ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 //Approach 2 :

 class MyStack 
{
public:

    queue<int> q1, q2;
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty()) 
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() 
    {
        if(q1.empty()) return -1;
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    int top() 
    {
        if(q1.empty()) return -1;
        return q1.front();
    }

    
    bool empty() 
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */