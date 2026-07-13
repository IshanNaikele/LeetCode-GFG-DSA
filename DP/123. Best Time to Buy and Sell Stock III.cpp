//Recursion 
class Solution
{
public:
    int solve(vector<int>&prices,int index,int buy,int count)
    {
        int n=prices.size();
        if(count==3) return 0;
        if(index==n) return 0;
        int profit=0;
        if(buy)
          profit=max(-prices[index]+solve(prices,index+1,0,count+1),solve(prices,index+1,1,count));
        else
          profit=max(prices[index]+solve(prices,index+1,1,count),solve(prices,index+1,0,count));


        return profit;
    }
    int maxProfit(vector<int>& prices)
    {
        return solve(prices,0,1,0);
    }
};

//Memoization 
class Solution
{
public:
    int solve(vector<int>&prices,int index,int buy,int count,vector<vector<vector<long long>>>&dp)
    {
        int n=prices.size();
        if(count==3) return 0;
        if(index==n) return 0;
        if(dp[index][buy][count]!=-1)  return dp[index][buy][count];
        int profit=0;
        if(buy)
          profit=max(-prices[index]+solve(prices,index+1,0,count+1,dp),solve(prices,index+1,1,count,dp));
        else
          profit=max(prices[index]+solve(prices,index+1,1,count,dp),solve(prices,index+1,0,count,dp));


        return dp[index][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(2,vector<long long >(3,-1)));
        return solve(prices,0,1,0,dp);
    }
};


//Tabulation 
class Solution
{
public:
    int solve(vector<int>&prices,int index,int buy,int count,vector<vector<vector<long long>>>&dp)
    {
        int n=prices.size();
        if(count==3) return 0;
        if(index==n) return 0;
        if(dp[index][buy][count]!=-1)  return dp[index][buy][count];
        int profit=0;
        if(buy)
          profit=max(-prices[index]+solve(prices,index+1,0,count+1,dp),solve(prices,index+1,1,count,dp));
        else
          profit=max(prices[index]+solve(prices,index+1,1,count,dp),solve(prices,index+1,0,count,dp));


        return dp[index][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(2,vector<long long >(4,0)));


        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int count=0;count<=2;count++)
                {
                    int profit=0;
                    if(buy)
                    profit=max(-prices[index]+dp[index+1][0][count+1],dp[index+1][1][count]);
                    else
                    profit=max(prices[index]+dp[index+1][1][count],dp[index+1][0][count]);


                    dp[index][buy][count]=profit;
                }
            }
        }
        return dp[0][1][0];
    }
};


//Space Optimization 
class Solution
{
public:
    int solve(vector<int>&prices,int index,int buy,int count,vector<vector<vector<long long>>>&dp)
    {
        int n=prices.size();
        if(count==3) return 0;
        if(index==n) return 0;
        if(dp[index][buy][count]!=-1)  return dp[index][buy][count];
        int profit=0;
        if(buy)
          profit=max(-prices[index]+solve(prices,index+1,0,count+1,dp),solve(prices,index+1,1,count,dp));
        else
          profit=max(prices[index]+solve(prices,index+1,1,count,dp),solve(prices,index+1,0,count,dp));


        return dp[index][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<long long>>prev(2,vector<long long>(4,0));
        vector<vector<long long>>curr(2,vector<long long>(4,0));


        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int count=0;count<=2;count++)
                {
                    int profit=0;
                    if(buy)
                    profit=max(-prices[index]+prev[0][count+1],prev[1][count]);
                    else
                    profit=max(prices[index]+prev[1][count],prev[0][count]);


                    curr[buy][count]=profit;
                }
            }
            prev=curr;
        }
        return prev[1][0];
    }
};
