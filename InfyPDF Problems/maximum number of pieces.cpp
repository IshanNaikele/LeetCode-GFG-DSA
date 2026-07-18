//  Chef wanted to build the tent for which she purchased a rod of length N and she wanted to 
// cut it into maximum number of pieces each of length a,b, and c. How many such maximum 
// cuts she can make such that each cut is of length either a, b or c. if no such pair exists then 
// display -1. 
// Input1 : N = 5 a =1, b = 2 and c = 3 
// Output : 5 cuts each of length 1 
// Input 2 : N = 3 a = 2, b = 4 and c = 2 
// Output:-1


#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int solve(int N,int a,int b,int c,vector<int>&dp)
{
    if(N==0) return 0;
    if(dp[N]!=-1) return dp[N];
    int cutByA=INT_MIN,cutByB=INT_MIN,cutByC=INT_MIN;
    if(N>=a){
        int ans=solve(N-a,a,b,c,dp);
        if(ans!=INT_MIN)
        cutByA=1+ans;
    }
    if(N>=b){
        int ans=solve(N-b,a,b,c,dp);
        if(ans!=INT_MIN)
        cutByB=1+ans;
    }
    if(N>=c){
        int ans=solve(N-c,a,b,c,dp);
        if(ans!=INT_MIN)
        cutByC=1+ans;
    }
    return dp[N]=max(cutByA,max(cutByB,cutByC));
}
int main()
{
    int  N = 3 , a = 2, b = 4 , c = 2;
    vector<int>dp(N+1,-1);
    int ans=solve(N,a,b,c,dp);
    if(ans==INT_MIN) 
    cout<<-1;
    else cout<<ans;
    return 0;
}