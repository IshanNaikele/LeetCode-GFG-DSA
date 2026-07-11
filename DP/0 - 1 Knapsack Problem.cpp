//Recursion 
class Solution 
{
  public:
    int solve(int W,vector<int>&val,vector<int>&wt,int index)
    {
        int n=val.size();
        if(index==n || W==0)  return 0;
        
        int notTake=solve(W,val,wt,index+1);
        int take=0;
        
        if(W>=wt[index])
        take=val[index]+solve(W-wt[index],val,wt,index+1);
        
        return max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // code here
        return solve(W,val,wt,0);
    }
};


//Memoization 
class Solution 
{
    public:
    int solve(int W,vector<int>&val,vector<int>&wt,int index,vector<vector<int>>&dp)
    {
        int n=val.size();
        if(index==n || W==0)  return 0;
        if(dp[index][W]!=-1) return dp[index][W];
        int notTake=solve(W,val,wt,index+1,dp);
        int take=0;
        
        if(W>=wt[index])
        take=val[index]+solve(W-wt[index],val,wt,index+1,dp);
        
        return dp[index][W]=max(take,notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,(vector<int>(W+1,-1)));
        return solve(W,val,wt,0,dp);
    }
};

//Tabulation 
class Solution 
{
    public:
     
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n+1,(vector<int>(W+1,0)));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int weight=0;weight<=W;weight++)
            {
                int notTake=dp[index+1][weight]; 
                int take=0;
                
                if(weight>=wt[index])
                take=val[index]+dp[index+1][weight-wt[index]];
                 
                dp[index][weight]=max(take,notTake);
            }
        }
        return dp[0][W]; 
    }
};


//Space Optimization 
class Solution 
{
    public:
     
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // code here
        int n=val.size();
        vector<int>prev(W+1,0);
        
        for(int index=n-1;index>=0;index--)
        {
            vector<int>curr(W+1,0);
            for(int weight=0;weight<=W;weight++)
            {
                int notTake=prev[weight]; 
                int take=0;
                
                if(weight>=wt[index])
                take=val[index]+prev[weight-wt[index]];
                 
                curr[weight]=max(take,notTake);
            }
            prev=curr;
        }
        return prev[W]; 
    }
};
