// User function Template for C++

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) 
    {
        stack<int>sta;
        
        while(!st.empty()) 
        {
            sta.push(st.top());
            st.pop();
        }
        
        st.push(x);
        while(!sta.empty())
        {
            st.push(sta.top());
            sta.pop();
        }
        return st;
    }
};