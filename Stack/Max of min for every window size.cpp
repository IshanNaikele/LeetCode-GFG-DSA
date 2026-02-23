//Approach 1:Brute Force 

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) 
    {
        //  code here
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                int num=INT_MAX;
                for(int k=j;k<j+i+1;k++)
                num=min(num,arr[k]);
                
                ans[i]=max(num,ans[i]);
            }
        }
        
        return ans;
    }
};

//Approach 2 :

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) 
    {
        //  code here
        int n=arr.size();
        vector<int>ans(n,0);
        vector<int>smallestLeft(n,-1);
        vector<int>smallestRight(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                smallestRight[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty())          st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                smallestLeft[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            int index=smallestRight[i]-smallestLeft[i]-1;
            ans[index-1]=max(ans[index-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(ans[i]<ans[i+1])
            ans[i]=ans[i+1];
        }
        
        return ans;
    }
};