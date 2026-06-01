class Solution 
{
public:
    int solve(vector<int>&cost,int index,vector<int>&dp)
    {
        int n=cost.size();
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index]=cost[index]+min(solve(cost,index+1,dp),solve(cost,index+2,dp));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return min(solve(cost,0,dp1),solve(cost,1,dp2));
    }
};