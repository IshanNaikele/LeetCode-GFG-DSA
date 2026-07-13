//Recursion
class Solution {
public:
    int solve(vector<int>&prices,int index,bool buy)
    {
        //buy -->1 means you can but ,0 means you can't
        int n=prices.size();
        if(index==n) return 0;
        int profit=0;
        if(buy)
            profit=max(-prices[index]+solve(prices,index+1,0),solve(prices,index+1,1));
        else
        {
            profit=max(prices[index]+solve(prices,index+1,1),solve(prices,index+1,0));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices)
    {
        return solve(prices,0,1);
    }
};


//Memoization
class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,vector<vector<long long>>&dp)
    {
        //buy -->1 means you can but ,0 means you can't
        int n=prices.size();
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if(buy)
            profit=max(-prices[index]+solve(prices,index+1,0,dp),solve(prices,index+1,1,dp));
        else
        {
            profit=max(prices[index]+solve(prices,index+1,1,dp),solve(prices,index+1,0,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));


        return solve(prices,0,1,dp);
    }
};


//Tabulation 
class Solution {
public:
     
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));
       
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int profit=0;
                if(buy)
                    profit=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                else
                    profit=max(prices[index]+dp[index+1][1],dp[index+1][0]);
               
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
//Space Optimized 
class Solution {
public:
     
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<long long>prev(2,0);
       
        for(int index=n-1;index>=0;index--)
        {
            vector<long long>curr(2,0);
            for(int buy=0;buy<2;buy++)
            {
                int profit=0;
                if(buy)
                    profit=max(-prices[index]+prev[0],prev[1]);
                else
                    profit=max(prices[index]+prev[1],prev[0]);
               
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};
