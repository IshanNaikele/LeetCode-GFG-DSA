class Solution {
  public:
    int solve(vector<int> &val, vector<int> &wt,int index,int W,vector<vector<long long>>&dp)
    {
        int n=val.size();
        if(index==n) 
        {
            return 0;
        }
        if(dp[index][W]!=-1) return dp[index][W];
        int take=0,skip=0;
        skip=solve(val,wt,index+1,W,dp);
        if(W>=wt[index])
        take=val[index]+solve(val,wt,index,W-wt[index],dp);
        
        return dp[index][W]=max(take,skip);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int n=val.size();
        vector<vector<long long>>dp(n,vector<long long>(capacity+1,-1));
        return solve(val,wt,0,capacity,dp);
    }
};