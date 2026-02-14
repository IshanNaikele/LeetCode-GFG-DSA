// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) 
    {
        // Your code goes here
        vector<int>ans;
        stack<int>st;
        int open=0;
        
        for(char ch:str)
        {
            if(ch=='(') 
            {
                open++;
                st.push(open);
                ans.push_back(open);
            }
            else if(ch==')') 
            {
                int value=st.top();
                ans.push_back(value);
                st.pop();
            }
        }
        return ans;
    }
};