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