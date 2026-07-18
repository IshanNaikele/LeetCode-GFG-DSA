class Solution {
  public:
    long long solve(vector<int>&prices,int target,int index,vector<vector<long long>>&dp)
    {
        int n=prices.size();
        if(index==n) 
        {
            return (target==0)?1:0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        long long take=0,skip=0;
        
        skip=solve(prices,target,index+1,dp);
        if(target>=prices[index])
        take=solve(prices,target-prices[index],index+1,dp);
        
        return dp[index][target]=take+skip;
    }
    
    int perfectSum(vector<int>& arr, int target) 
    {
        // code here
        int n=arr.size();
        vector<vector<long long>>dp(n,vector<long long>(target+1,-1));
        return solve(arr,target,0,dp);
    }
};