#include<iostream>
#include<vector>
using namespace std;
// Stack Implementation by Array 
// Operation Need to Implement :top ,size ,push ,pop
class stack
{
    int *arr;
    int index;
    int n;
    public:
    stack(int size)
    {
        arr = new int[size];
        n=size;
        index=-1;
    }
    
    void push(int value)
    {
        if(index==n-1){
            cout<<"Stack Oveflow"<<endl ;
            return;
        }
        index++;
        arr[index]=value;
         
    }
    
    void pop()
    {
        if(index==-1) 
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Element "<<arr[index]<<" is popped from the stack "<<endl;
        index--;
    }
    
    void top()
    {
        if(index==-1) 
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<arr[index]<<" is at the top of the stack "<<endl;
    }
    
    void size()
    {
        if(index==-1) 
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"The size of the stack is "<<index+1<<endl;
    }
    
    
};
int main()
{
    stack st(4);
    st.push(1);
    st.top();
    st.size();
    st.push(2);
    st.top();
    st.size();
    st.push(3);
    st.top();
    st.size();
    st.push(4);
    st.top();
    st.size();
    st.push(5);
    st.top();
    st.size();
    st.pop();
    st.size();
    st.top();
    return 0;
}