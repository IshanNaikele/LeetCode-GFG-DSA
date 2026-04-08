class Solution 
{
  public:
    void subseq(vector<int>&arr,int index,int n,int &sum,vector<int>&ans)
    {
        if(index>=n) return;
        subseq(arr,index+1,n,sum,ans);
        sum+=arr[index];
        ans.push_back(sum);
        subseq(arr,index+1,n,sum,ans);
        
        sum-=arr[index];
    }
    vector<int> subsetSums(vector<int>& arr) 
    {
        // code here
        vector<int>ans;
        int index=0,n=arr.size(),sum=0;
        ans.push_back(0);
        subseq(arr,index,n,sum,ans);
        return ans;
    }
};