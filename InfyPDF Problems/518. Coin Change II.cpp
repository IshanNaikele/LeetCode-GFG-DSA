#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>&prices,int target,int index,vector<vector<long long>>&dp)
    {
        int n=prices.size();
        if(index==n) 
        {
            return (target==0)?1:0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int take=0,skip=0;
        
        skip=solve(prices,target,index+1,dp);
        if(target>=prices[index])
        take=solve(prices,target-prices[index],index,dp);
        
        return dp[index][target]=take+skip;
    }

    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};


class Solution {
  public:
    int solve(vector<int>&prices,int target,int index,vector<vector<long long>>&dp)
    {
        int n=prices.size();
        if(index==n) 
        {
            return (target==0)?1:0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int take=0,skip=0;
        
        skip=solve(prices,target,index+1,dp);
        if(target>=prices[index])
        take=solve(prices,target-prices[index],index,dp);
        
        return dp[index][target]=take+skip;
    }
    
    int count(vector<int>& coins, int amount) 
    {
        // code here.
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};


 

int solve(vector<int>&prices,int target,int index)
{
    int n=prices.size();
    if(index==n) 
    {
        return (target==0)?1:0;
    }
    int take=0,skip=0;
    
    skip=solve(prices,target,index+1);
    if(target>=prices[index])
    take=solve(prices,target-prices[index],index);
    
    return take+skip;
}
int main()
{
    vector<int>arr={2,3};
    int sum=7;
    cout<<solve(arr,sum,0);
    return 0;
}