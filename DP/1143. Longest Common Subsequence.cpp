//Recursion 
class Solution
{
public:


    int solve(string &text1,string &text2,int index1,int index2)
    {
        if(index1<0 || index2<0) return 0;


        if(text1[index1]==text2[index2])  
           return 1+solve(text1,text2,index1-1,index2-1);


        return max(solve(text1,text2,index1-1,index2),solve(text1,text2,index1,index2-1));
    }


    int longestCommonSubsequence(string text1, string text2)
    {
        int index1=text1.size(),index2=text2.size();
        return solve(text1,text2,index1-1,index2-1);
    }
};

//Memoization
class Solution
{
public:


    int solve(string &text1,string &text2,int index1,int index2,vector<vector<int>>&dp)
    {
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(text1[index1]==text2[index2])  
           return dp[index1][index2]=1+solve(text1,text2,index1-1,index2-1,dp);


        return dp[index1][index2]=max(solve(text1,text2,index1-1,index2,dp),solve(text1,text2,index1,index2-1,dp));
    }


    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(text1,text2,m-1,n-1,dp);
    }
};

//Tabulation 
class Solution
{
public:


    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));


        for(int index1=1;index1<=m;index1++)
        {
            for(int index2=1;index2<=n;index2++)
            {
                if(text1[index1-1]==text2[index2-1])  
                    dp[index1][index2]=1+dp[index1-1][index2-1];
                else
                dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);
            }
        }
        return dp[m][n];
    }
};


//Space Optimization 
class Solution
{
public:


    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.size(),n=text2.size();
        vector<int>prev(n+1,0);


        for(int index1=1;index1<=m;index1++)
        {
            vector<int>curr(n+1,0);
            for(int index2=1;index2<=n;index2++)
            {
                if(text1[index1-1]==text2[index2-1])  
                    curr[index2]=1+prev[index2-1];
                else
                curr[index2]=max(prev[index2],curr[index2-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
};
