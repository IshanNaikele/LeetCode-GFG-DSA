class Solution {
  public:
  
    long long solve(vector<int>&prices,int target,int index,vector<vector<long long >>&dp)
    {
        int n=prices.size();
        if(target==0) return 0;
        if(index==n) 
        {
            return INT_MAX;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        long long take=INT_MAX,skip=INT_MAX;
        
        skip=solve(prices,target,index+1,dp);
        if(target>=prices[index])
        take=1+solve(prices,target-prices[index],index,dp);
        
        return dp[index][target]=min(take,skip);
    }
    
    int minCoins(vector<int> &coins, int sum) 
    {
        // code here
        int n=coins.size();
        vector<vector<long long >>dp(n,vector<long long>(sum+1,-1));
        long long ans=solve(coins,sum,0,dp);
        return ans==INT_MAX?-1:ans;
    }
};