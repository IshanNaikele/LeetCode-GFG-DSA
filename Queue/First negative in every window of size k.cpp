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