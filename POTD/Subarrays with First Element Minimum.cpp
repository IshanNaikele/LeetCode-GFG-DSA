//Approach 1 :Brute Force 
class Solution {
  public:
    int countSubarrays(vector<int> &arr) 
    {
        // code here
        int n=arr.size(),total=0;
        stack<int>st;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                int idx=st.top();
                st.pop();
                ans+=(i-idx);
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            int idx = st.top();
            st.pop();
            ans += n - idx;
        }

        return ans;
    }
};


// Approach 2 :Optimal Using Stack 

class Solution {
  public:
    int countSubarrays(vector<int> &arr) 
    {
        // code here
        int n=arr.size(),total=0;
        stack<int>st;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                int idx=st.top();
                st.pop();
                ans+=(i-idx);
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            int idx = st.top();
            st.pop();
            ans += n - idx;
        }

        return ans;
    }
};
