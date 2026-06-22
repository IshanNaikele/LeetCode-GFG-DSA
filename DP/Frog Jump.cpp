//Recursion 
class Solution 
{
  public:
    int solve(vector<int>&cost ,int index)
    {
        int n=cost.size();
        if(index==n-1) return 0;
        if(index>=n)   return 0;
        int oneStep=INT_MAX;
        int twoStep=INT_MAX;
        
        if(index+1<n)
        oneStep=abs(cost[index]-cost[index+1])+solve(cost,index+1);
        
        if(index+2<n)
        twoStep=abs(cost[index]-cost[index+2])+solve(cost,index+2);
        
        return min(oneStep,twoStep);
    }
    int minCost(vector<int>& cost) 
    {
        // Code here
        return solve(cost,0);
    }
};


//Memoization /Top Down
class Solution 
{
  public:
    int solve(vector<int>&cost ,vector<int>&dp,int index)
    {
        int n=cost.size();
        int oneStep=INT_MAX,twoStep=INT_MAX;
        if(index<=0) return 0;
        
        if(dp[index]!=-1) return dp[index];
        if(index-1>=0)
        oneStep=abs(cost[index]-cost[index-1])+solve(cost,dp,index-1);
        
        if(index-2>=0)
        twoStep=abs(cost[index]-cost[index-2])+solve(cost,dp,index-2);
        
        dp[index]=min(oneStep,twoStep);
        return dp[index];
    }
    int minCost(vector<int>& cost) 
    {
        // Code here
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(cost,dp,n-1);
    }
};


//Tabulation or Botton-Up Approach 
class Solution 
{
  public:
     
    
    int minCost(vector<int>& cost) 
    {
        int n=cost.size();
        vector<int>dp(n,-1);
         
        dp[0]=0;
        if(n==1) return dp[0];
        dp[1]=abs(cost[1]-cost[0]);
        if(n==2) return dp[1];
        
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-2]+abs(cost[i-2]-cost[i]),
                      dp[i-1]+abs(cost[i-1]-cost[i]));
        }
        return dp[n-1];
    }
};


//Space Optimized Approach 
class Solution 
{
  public:
     
    
    int minCost(vector<int>& cost) 
    {
        int n=cost.size();
        if(n==1) return 0;
        int first=0,second=abs(cost[0]-cost[1]);
        
        for(int i=2;i<n;i++)
        {
            int third=min(first+abs(cost[i-2]-cost[i]),
                          second+abs(cost[i-1]-cost[i]));
            first=second;
            second=third;
        }
        return second;
    }
};
