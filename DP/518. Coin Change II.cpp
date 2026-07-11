//Recursion 
class Solution
{
public:
    long solve(vector<int>&coins,int index,int amount)
    {
        int n=coins.size();
         
        if(index==n)  return (amount==0)?1:0;


        int notTake=solve(coins,index+1,amount);
        int take=0;
        if(amount>=coins[index])
        take=solve(coins,index,amount-coins[index]);


        return take+notTake;
    }
    int change(int amount, vector<int>& coins)
    {
        int minCoins=solve(coins,0,amount);
        return (minCoins>=INT_MAX)?0:minCoins;
    }
};

//Memoization 
class Solution
{
public:
    long solve(vector<int>&coins,int index,int amount,vector<vector<int>>&dp)
    {
        int n=coins.size();
         
        if(index==n)  return (amount==0)?1:0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=solve(coins,index+1,amount,dp);
        int take=0;
        if(amount>=coins[index])
        take=solve(coins,index,amount-coins[index],dp);


        return dp[index][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins)
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,0,amount,dp);
    }
};

//Tabulation 
class Solution
{
public:
   
    int change(int amount, vector<int>& coins)
    {
        int n=coins.size();
        vector<vector<unsigned int>> dp(n , vector<unsigned int>(amount + 1, 0));
        for(int index=0;index<n;index++) dp[index][0]=1;
        for(int amt=1;amt<=amount;amt++)
            if(amt%coins[n-1]==0)   dp[n-1][amt]=1;
       
        for(int index=n-2;index>=0;index--)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                long notTake=dp[index+1][amt];
                long take=0;
                if(amt>=coins[index])
                take=dp[index][amt-coins[index]];


                dp[index][amt]=take+notTake;
            }
        }
        return dp[0][amount];
    }
};

//Space Optimized 
class Solution
{
public:
   
    int change(int amount, vector<int>& coins)
    {
        int n=coins.size();
        vector<unsigned int> prev(amount + 1, 0);
        prev[0]=1;
       
        for(int index=n-1;index>=0;index--)
        {
            vector<unsigned int> curr(amount + 1, 0);
            curr[0]=1;
            for(int amt=0;amt<=amount;amt++)
            {
                unsigned int notTake=prev[amt];
                unsigned int take=0;
                if(amt>=coins[index])
                take=curr[amt-coins[index]];


                curr[amt]=take+notTake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
