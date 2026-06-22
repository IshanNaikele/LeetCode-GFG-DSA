#include<iostream>
#include<vector>
using namespace std;

//Recursion 
long long climbingStairsR(int n)
{
    if(n<=2) return n;
    return  climbingStairsR(n-1)+climbingStairsR(n-2);
}

//Memoization 
long long climbingStairsM(int n,vector<long long>&dp)
{
    if(n<=2) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=climbingStairsM(n-1,dp)+climbingStairsM(n-2,dp);
    return dp[n];
}

//Tabulation 
long long climbingStairsT(int n)
{
    vector<long long>dp(n+1,-1);
    if(n<=2) return n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];
    
    return dp[n];
}

//Space Optimized 
long long climbingStairsSO1(int n)
{
    vector<long long>dp(4,-1);
    if(n<=2) return n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[3]=dp[1]+dp[2];
        dp[1]=dp[2];
        dp[2]=dp[3];
    }
    return dp[3];
}

//Space Optimized 
long long climbingStairsSO2(int n)
{
    if(n<=2) return n;
    long long first=1,second=2;
    n-=2;
    while(n--)
    {
        long long third=first+second;
        first=second;
        second=third;
    }
    return second;
}

int main()
{
    int range=45;
    for(int i=0;i<range;i++)
    cout<<climbingStairsR(i)<<" ";
    cout<<endl;
    
    vector<long long>dp1(range,-1);
    for(int i=0;i<range;i++)
    cout<<climbingStairsM(i,dp1)<<" ";
    cout<<endl;
    
    for(int i=0;i<range;i++)
    cout<<climbingStairsT(i)<<" ";
    cout<<endl;
    
    for(int i=0;i<range;i++)
    cout<<climbingStairsSO1(i)<<" ";
    cout<<endl;
    
    for(int i=0;i<range;i++)
    cout<<climbingStairsSO2(i)<<" ";
    cout<<endl;
    return 0;
}