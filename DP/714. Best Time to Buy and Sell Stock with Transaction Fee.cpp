//Recursion 
class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,int fee)
    {
        int n=prices.size();
        if(index==n) return 0;
        int profit=0;
        if(buy)
          profit=max(-prices[index]+solve(prices,index+1,0,fee),solve(prices,index+1,1,fee));
        else
          profit=max(prices[index]-fee+solve(prices,index+1,1,fee),solve(prices,index+1,0,fee));


        return profit;
    }
    int maxProfit(vector<int>& prices, int fee)
    {
        return solve(prices,0,1,fee);
    }
};

//Memoization 
class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,int fee,vector<vector<long long>>&dp)
    {
        int n=prices.size();
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if(buy)
          profit=max(-prices[index]+solve(prices,index+1,0,fee,dp),solve(prices,index+1,1,fee,dp));
        else
          profit=max(prices[index]-fee+solve(prices,index+1,1,fee,dp),solve(prices,index+1,0,fee,dp));


        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee)
    {
        int n=prices.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solve(prices,0,1,fee,dp);
    }
};

//Tabulation 
class Solution {
public:
   
    int maxProfit(vector<int>& prices, int fee)
    {
        int n=prices.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));


        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                profit=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                else
                profit=max(prices[index]-fee+dp[index+1][1],dp[index+1][0]);


                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};

//Space Optimization
class Solution {
public:
     
    int maxProfit(vector<int>& prices, int fee)
    {
        int n=prices.size();
        vector<long long>prev(2,0);
        vector<long long>curr=prev;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                profit=max(-prices[index]+prev[0],prev[1]);
                else
                profit=max(prices[index]-fee+prev[1],prev[0]);


                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};
