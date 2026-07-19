//  Your birthday is coming soon and one of your friends, Alex, is thinking about a gift for you. 
// He knows that you really like integer arrays with interesting properties.He selected two 
// numbers, N and K and decided to write down on paper all integer arrays of length K (in form 
// a[1], a[2], …, a[K]), where every number a[i] is in range from 1 to N, and, moreover, a[i+1] is 
// divisible by a[i] (where 1 < i <= K), and give you this paper as a birthday present. Alex is very 
// patient, so he managed to do this. Now you’re wondering, how many different arrays are 
// written down on this paper? 
// Since the answer can be really large, print it modulo 10000. 
// Input: 
// · The first line contains an integer, n, denoting the maximum possible value in the arrays. 
// · The next line contains an integer, k, denoting the length of the arrays. 


#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
#include <unordered_map>
#include<algorithm>
using namespace std;

//N -->Range in the array 
//K -->Length of the array 
//len -->DP state 
//lastElement -->DP state

int solve(int N,int K,int len,int lastElement,vector<vector<int>>&dp)
{
    if(K==len) return 1;
    if(dp[len][lastElement]!=-1) return dp[len][lastElement];
    int ways=0;
    for(int i=lastElement;i<=N;i=i+lastElement)
    {
        ways=ways+solve(N,K,len+1,i,dp);
    }
    return dp[len][lastElement]=ways;
}

int findGoodArray(int N,int K)
{
    vector<vector<int>>dp(K,vector<int>(N+1,-1));
    int ans=0;
    for(int i=1;i<=N;i++)
    ans=ans+solve(N,K,1,i,dp);
    
    return ans;
}

int main()
{
    int N=2,K=1;
    cout<<findGoodArray(N,K);
    return 0;
}
