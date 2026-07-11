//Recursion 
class Solution
{
public:
    long solve(vector<int>& coins,int amount,int index)
    {
        if(amount==0) return 0;
        if(index==coins.size()) return INT_MAX;
        long notTake=solve(coins,amount,index+1);
        long take=INT_MAX;
        if(amount>=coins[index])
        take=1+solve(coins,amount-coins[index],index);


        return min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount)
    {
        if(amount==0) return 0;
        long minCoins=solve(coins,amount,0);
        if(minCoins>=INT_MAX) return -1;
        return minCoins;
    }
};


//Memoization 
class Solution
{
public:
    long solve(vector<int>& coins,int amount,int index,vector<vector<long>>&dp)
    {
        if(amount==0) return 0;
        if(index==coins.size()) return INT_MAX;
        if(dp[index][amount]!=-1) return dp[index][amount];
        long notTake=solve(coins,amount,index+1,dp);
        long take=INT_MAX;
        if(amount>=coins[index])
        take=1+solve(coins,amount-coins[index],index,dp);


        return dp[index][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        vector<vector<long>>dp(n,vector<long>(amount+1,-1));
        if(amount==0) return 0;
        int minCoins=solve(coins,amount,0,dp);
        if(minCoins>=INT_MAX) return -1;
        return minCoins;
    }
};

//Tabulation 
class Solution
{
public:
 
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        if(amount==0) return 0;


        vector<vector<long>>dp(n+1,vector<long>(amount+1,INT_MAX));
        for(int index=0;index<=n;index++) dp[index][0]=0;
         
        for(int index=n-1;index>=0;index--)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                long notTake=dp[index+1][amt];
                long take=INT_MAX;
                if(amt>=coins[index])
                take=1+dp[index][amt-coins[index]];


                dp[index][amt]=min(take,notTake);
            }
        }
        long minCoins=dp[0][amount];
        if(minCoins>=INT_MAX) return -1;
        return minCoins;
    }
};

//Space Optimization 
class Solution
{
public:
 
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        if(amount==0) return 0;


        vector<long>prev(amount+1,INT_MAX);
        prev[0]=0;
         
        for(int index=n-1;index>=0;index--)
        {
            vector<long>curr(amount+1,INT_MAX);
            curr[0]=0;
            for(int amt=0;amt<=amount;amt++)
            {
                long notTake=prev[amt];
                long take=INT_MAX;
                if(amt>=coins[index])
                take=1+curr[amt-coins[index]];


                curr[amt]=min(take,notTake);
            }
            prev=curr;
        }
        long minCoins=prev[amount];
        if(minCoins>=INT_MAX) return -1;
        return minCoins;
    }
};
