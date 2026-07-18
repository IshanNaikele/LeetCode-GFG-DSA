// Given a rod of length n and an array price[] where price[i] represents the 
// price of a rod of length i+1, determine the maximum total value 
// obtainable by cutting up the rod and selling the pieces. You may cut the 
// rod into any number of pieces, and you can use the same length multiple 
// times. 
// Constraints: 
// 1 ≤ n ≤ 1000 
// 1 ≤ price[i] ≤ 1000 

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&prices,int index,int len)
{
    int n=prices.size();
    if(index==n) return 0;
    int take=0,skip=0;
    
    skip=solve(prices,index+1,len);
    if(len>=(index+1))
    take=prices[index]+solve(prices,index,len-(index+1));
    
    return max(skip,take);
}

class Solution {
  public:
    int solve(vector<int>&prices,int index,int len,vector<vector<int>>&dp)
    {
        int n=prices.size();
        if(index==n) return 0;
        if(dp[index][len]!=-1) return dp[index][len];
        int take=0,skip=0;
        
        skip=solve(prices,index+1,len,dp);
        if(len>=(index+1))
        take=prices[index]+solve(prices,index,len-(index+1),dp);
        
        return dp[index][len]=max(skip,take);
    }
    
    int cutRod(vector<int> &arr) 
    {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+2,-1));
        return solve(arr,0,arr.size(),dp);
    }
};

int main()
{
    vector<int>arr={3,5,8,9,10,17};
    cout<<solve(arr,0,arr.size());
    return 0;
}