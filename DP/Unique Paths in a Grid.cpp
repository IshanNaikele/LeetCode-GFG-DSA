class Solution 
{
  public:
    int solve(vector<vector<int>> &grid ,vector<vector<int>>&dp ,int row,int col)
    {
        int n=grid.size(),m=grid[0].size(),totalPaths=0;
        if(row==n-1 && col==m-1 ) return 1;
        if(dp[row][col]!=0) return dp[row][col];
        if(grid[row][col]==0)
        {
            if(row+1<n)
            dp[row][col]+=solve(grid,dp,row+1,col);
            if(col+1<m)
            dp[row][col]+=solve(grid,dp,row,col+1);
        }
        
        return dp[row][col];
    }
    int uniquePaths(vector<vector<int>> &grid) 
    {
        // code here
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        return solve(grid,dp,0,0);
    }
};

//Memoization 
class Solution 
{
  public:
    int solve(vector<vector<int>> &grid ,vector<vector<int>>&dp ,int row,int col)
    {
        int n=grid.size(),m=grid[0].size(),totalPaths=0;
        if(row==n-1 && col==m-1 ) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        if(grid[row][col]==0)
        {
            if(row+1<n)
            totalPaths+=solve(grid,dp,row+1,col);
            if(col+1<m)
            totalPaths+=solve(grid,dp,row,col+1);
        }
        
        return dp[row][col]=totalPaths;
    }
    int uniquePaths(vector<vector<int>> &grid) 
    {
        // code here
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,dp,0,0);
    }
};

//Tabulation 
class Solution 
{
  public:
     
    int uniquePaths(vector<vector<int>> &grid) 
    {
        // code here
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[n-1][m-1]=1;
       
        for(int i=n-1;i>=0;i--)
        {
            
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) continue;
                if(grid[i][j]==1) 
                {
                    dp[i][j]=0;
                    continue;
                }
                int right=0,down=0;
                if(i+1<n)
                down=dp[i+1][j];
                if(j+1<m)
                right=dp[i][j+1];
                
                dp[i][j]=down+right;
            }
        }
        return dp[0][0];
    }
};