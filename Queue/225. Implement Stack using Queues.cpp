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