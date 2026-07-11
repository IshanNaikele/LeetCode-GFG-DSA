//Recursion 
class Solution 
{
  public:
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int solve(vector<int>&arr,int index,int target)
    {
        int n=arr.size();
        
        if(index==n) return (target==0)?1:0;
        int exclude=solve(arr,index+1,target);
        int include=0;
        if(target>=arr[index])
        include=solve(arr,index+1,target-arr[index]);
        
        return include+exclude;
    }
    
    int countPartitions(vector<int>& arr, int diff) 
    {
        // Code here
        int totalSum=findTotalSum(arr);
        int target=totalSum-diff;
        if(target<0) return 0;
        if(target & 1) return 0;
        
        return solve(arr,0,target/2);
    }
};

//Memoization 
class Solution 
{
  public:
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int solve(vector<int>&arr,int index,int target,vector<vector<int>>&dp)
    {
        int n=arr.size();
        
        if(index==n) return (target==0)?1:0;
        if(dp[index][target]!=-1) return dp[index][target];
        int exclude=solve(arr,index+1,target,dp);
        int include=0;
        if(target>=arr[index])
        include=solve(arr,index+1,target-arr[index],dp);
        
        return dp[index][target]=include+exclude;
    }
    
    int countPartitions(vector<int>& arr, int diff) 
    {
        // Code here
        int n=arr.size();
        int totalSum=findTotalSum(arr);
        int target=totalSum-diff;
        if(target<0) return 0;
        if(target & 1) return 0;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(arr,0,target/2,dp);
    }
};

//Tabulation 
class Solution 
{
  public:
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int countPartitions(vector<int>& arr, int diff) 
    {
        // Code here
        int n=arr.size();
        int totalSum=findTotalSum(arr);
        int target=totalSum-diff;
        if(target<0) return 0;
        if(target & 1) return 0;
        target/=2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        for(int index=0;index<n;index++) dp[index][0]=1;
        
        if(arr[n-1]<=target) dp[n-1][arr[n-1]]+=1;
        for(int index=n-2;index>=0;index--)
        {
            for(int tar=0;tar<=target;tar++)
            {
                int exclude=dp[index+1][tar]; 
                int include=0;
                if(tar>=arr[index])
                include=dp[index+1][tar-arr[index]]; 
                
                dp[index][tar]=include+exclude;
            }
            
        }
        return dp[0][target];
    }
};

//Space Optimization 
class Solution 
{
  public:
    int findTotalSum(vector<int>&arr)
    {
        int totalSum=0;
        for(int num:arr) totalSum+=num;
        return totalSum;
    }
    
    int countPartitions(vector<int>& arr, int diff) 
    {
        // Code here
        int n=arr.size();
        int totalSum=findTotalSum(arr);
        int target=totalSum-diff;
        if(target<0) return 0;
        if(target & 1) return 0;
        target/=2;
        
        
        vector<int>prev(target+1,0);
        prev[0]=1;
        
        if(arr[n-1]<=target) prev[arr[n-1]]=1;
        for(int index=n-2;index>=0;index--)
        {
            vector<int>curr(target+1,0);
            curr[0]=1;
            for(int tar=0;tar<=target;tar++)
            {
                int exclude=prev[tar]; 
                int include=0;
                if(tar>=arr[index])
                include=prev[tar-arr[index]]; 
                
                curr[tar]=include+exclude;
            }
            prev=curr;
        }
        return prev[target];
    }
};
