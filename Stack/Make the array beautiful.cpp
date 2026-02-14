// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) 
    {
        // code here
        stack<int>st;
        for(int x:arr)
        {
            if(st.empty()) st.push(x);
            else
            {
                if(x>=0 && st.top()>=0) st.push(x);
                else if(x<0 && st.top()<0) st.push(x);
                else st.pop();
            }
        }
        
        vector<int>ans;
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};