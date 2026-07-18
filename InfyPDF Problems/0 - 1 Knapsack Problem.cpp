//  0/1 Knapsack Problem 
// Given n items, each with a specific weight and value, and a knapsack 
// with a capacity of W, the task is to put the items in the knapsack such 
// that the sum of weights of the items <= W and the sum of values 
// associated with them is maximized.


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
        take=val[index]+solve(val,wt,index+1,W-wt[index],dp);
        
        return dp[index][W]=max(take,skip);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<long long>>dp(n,vector<long long>(W+1,-1));
        return solve(val,wt,0,W,dp);
    }
};