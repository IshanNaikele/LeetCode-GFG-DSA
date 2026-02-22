//Approach 1 :

#include<stack>
class SpecialStack {
    stack<int>st;
        stack<int>minStack;
    public:
    SpecialStack() 
    {
        
    }

    void push(int x) 
    {
        // Add an element to the top of Stack
        st.push(x);
        if(!minStack.empty() && x<minStack.top())
        minStack.push(x);
        else if(!minStack.empty())
        minStack.push(minStack.top());
        else
        minStack.push(x);
    }

    void pop() 
    {
        // Remove the top element from the Stack
        if(!st.empty())
        {
            st.pop();
            minStack.pop();
        }
        
    }

    int peek() 
    {
        // Returns top element of the Stack
        if(st.empty()) return -1;
        return st.top();
    }

    bool isEmpty() 
    {
        // Check if stack is empty
        return st.size()==0;
    }

    int getMin() 
    {
        // Finds minimum element of Stack
        if(minStack.empty()) return -1;
        return minStack.top();
    }
};

//Approach 2 :

#include<stack>
class SpecialStack {
    stack<long long>st;
    long long mod=1e9+1;
    long long minValue=LONG_MAX;
    public:
    SpecialStack() 
    {
        
    }

    void push(int x) 
    {
         // Add an element to the top of Stack
        if(x<minValue) minValue=x;
        long long num=x*mod+minValue;
        st.push(num);
    }

    void pop() 
    {
        // Remove the top element from the Stack
        if(!st.empty())
        {
            st.pop();
            if(!st.empty())
            minValue=st.top()%mod;
            else 
            minValue=LONG_MAX;
        }
        else 
        minValue=LONG_MAX;
    }

    int peek() 
    {
        // Returns top element of the Stack
        if(st.empty()) return -1;
        return st.top()/mod;
    }

    bool isEmpty() 
    {
        // Check if stack is empty
        return st.size()==0;
    }

    int getMin() 
    {
        // Finds minimum element of Stack
        if(st.empty()) return -1;
        
        minValue=st.top()%mod;
        
        return minValue;
    }
};