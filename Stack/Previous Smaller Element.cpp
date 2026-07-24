class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty())
            {
                if(arr[i]<=arr[st.top()]) st.pop();
                else {
                    ans[i]=arr[st.top()];
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
};