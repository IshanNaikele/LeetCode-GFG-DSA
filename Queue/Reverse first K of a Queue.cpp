class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) 
    {
        // code here
        int n=q.size();
        if(k>n) return q;
        int remain=n-k;
        stack<int>st;
        while(k--)
        {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        
        while(remain--)
        {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    } 
};