//Approach 1 :Brute Force 
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) 
    {
        // write code here
        int n=arr.size();
        vector<int>ans(n-k+1,0);
        for(int i=0;i<=n-k;i++)
        {
            for(int j=i;j<i+k && j<n;j++)
            {
                if(arr[j]<0)
                {
                    ans[i]=arr[j];
                    break;
                }
            }
        }
        return ans;
    }
};

//Approach 2 :

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) 
    {
        // write code here
        int n=arr.size();
        vector<int>ans(n-k+1);
        queue<int>q;
        
        for(int i=0;i<k-1;i++) 
        {
            if(arr[i]<0)
            q.push(i);
        }
        
        for(int i=k-1;i<n;i++)
        {
            if(arr[i]<0)
            q.push(i);
            while(!q.empty() && q.front()<i-k+1) q.pop();
            if(!q.empty())
            {
                int index=q.front();
                ans[i-k+1]=arr[index];
            }
        }
        return ans;
    }
};