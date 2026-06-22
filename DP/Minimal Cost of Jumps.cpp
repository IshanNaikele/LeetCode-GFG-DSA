//Recursion 
class Solution
{
  public:
    int solve(vector<int>& arr,int k ,int index)
    {
        int n=arr.size();
        if(index==n-1) return 0;
        int minSteps=INT_MAX;
        
        for(int j=1;j<=k;j++)
        {
            int jump=INT_MAX;
            if(index+j<n)
            jump=solve(arr,k,index+j)+abs(arr[index]-arr[index+j]);
            minSteps=min(minSteps,jump);
        }
        return minSteps;
    }
    
    int minimizeCost(int k, vector<int>& arr) 
    {
        // code here
        int n=arr.size();
        return solve(arr,k,0);
    }
};

//Memoization or Top-Down Approach
class Solution
{
  public:
    int solve(vector<int>& arr,vector<int>&dp,int k ,int index)
    {
        int n=arr.size();
        if(index<=0) return 0;
        int minSteps=INT_MAX;
        if(dp[index]!=-1) return dp[index];
        for(int j=1;j<=k;j++)
        {
            int jump=INT_MAX;
             
            if(index-j>=0)
            jump=solve(arr,dp,k,index-j)+abs(arr[index]-arr[index-j]);
            minSteps=min(minSteps,jump);
        }
        dp[index]=minSteps;
        return dp[index];
    }
    
    int minimizeCost(int k, vector<int>& arr) 
    {
        // code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,dp,k,n-1);
    }
};


//Tabulation or Bottom Up Approach 
class Solution
{
  public:
    
    int minimizeCost(int k, vector<int>& arr) 
    {
        // code here
        int n=arr.size() ;
        vector<int>dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int minSteps=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    int jump=
                        dp[i-j]
                        +abs(arr[i]-arr[i-j]);

                    minSteps=min(minSteps,jump);
                }
            }
            dp[i]=minSteps;
        }
        return dp[n-1];
    }
};
