//Recursion 
class Solution
{
public:
    int solve(vector<vector<int>>& triangle,int row,int col)
    {
        int m=triangle.size(),n=triangle[row].size();
        int nxt=INT_MAX;
        if(row==m-1)
           return triangle[row][col];
       
        if(row+1<m)
           nxt=triangle[row][col]+min(solve(triangle,row+1,col),solve(triangle,row+1,col+1));
       
        return nxt;
    }
    int minimumTotal(vector<vector<int>>& triangle)
    {
        return solve(triangle,0,0);
    }
};

//Memoization 
class Solution
{
public:
    int solve(vector<vector<int>>& triangle,vector<vector<int>>&dp,int row,int col)
    {
        int m=triangle.size(),n=triangle[row].size();
        int nxt=INT_MAX;
        if(row==m-1)
           return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        if(row+1<m)
           nxt=triangle[row][col]+min(solve(triangle,dp,row+1,col),solve(triangle,dp,row+1,col+1));
       
        return dp[row][col]=nxt;
    }
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(triangle,dp,0,0);
    }
};
//Tabulation 
class Solution
{
public:
    int solve(vector<vector<int>>& triangle,vector<vector<int>>&dp,int row,int col)
    {
        int m=triangle.size();
       
        if(row==m-1) {
           return triangle[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
       
        int bottom=triangle[row][col]+solve(triangle,dp,row+1,col);
        int bottom_right=triangle[row][col]+solve(triangle,dp,row+1,col+1);
       
        return dp[row][col]=min(bottom,bottom_right);
    }


    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m=triangle.size();


        vector<vector<int>>dp(m,vector<int>(m,0));
       
        for(int i=0;i<m;i++)
            dp[m-1][i]=triangle[m-1][i];


        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
//Space Optimized 
class Solution
{
public:
     
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m=triangle.size();


        vector<int>prev(m,0);
       
        for(int i=0;i<m;i++)
            prev[i]=triangle[m-1][i];


        for(int i=m-2;i>=0;i--)
        {
            vector<int>temp(i+1,0);
            for(int j=0;j<=i;j++)
            {
                temp[j]=triangle[i][j]+min(prev[j],prev[j+1]);
            }
            prev=temp;
        }
        return prev[0];
    }
};
