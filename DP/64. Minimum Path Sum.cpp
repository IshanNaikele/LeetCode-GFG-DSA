//Recursion 
class Solution
{
public:
    int solve(vector<vector<int>>& grid,int row,int col )
    {
        int m=grid.size(),n=grid[0].size(),right=INT_MAX,down=INT_MAX;
        if(row==m-1 && col==n-1)    return grid[row][col];
       
        if(row+1<m) down=grid[row][col]+solve(grid,row+1,col);
        if(col+1<n) right=grid[row][col]+solve(grid,row,col+1);
       
        return min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        return solve(grid,0,0);
    }
};

//Memoization
class Solution
{
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>&dp ,int row,int col )
    {
        int m=grid.size(),n=grid[0].size(),right=INT_MAX,down=INT_MAX;
        if(row==m-1 && col==n-1)    return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        if(row+1<m) down=grid[row][col]+solve(grid,dp,row+1,col);
        if(col+1<n) right=grid[row][col]+solve(grid,dp,row,col+1);
       
        return dp[row][col]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,dp,0,0);
    }
};

//Tabulation 
class Solution
{
public:
   
    int minPathSum(vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[0][0]=grid[0][0];
                    continue;
                }
                int left=INT_MAX,up=INT_MAX;
                if(i-1>=0) up=grid[i][j]+dp[i-1][j];
                if(j-1>=0) left=grid[i][j]+dp[i][j-1];


                dp[i][j]=min(left,up);
            }
        }
        return dp[m-1][n-1];
    }
};


//Space Optimization 
class Solution
{
public:
     
    int minPathSum(vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
       
        vector<int>prev(n,0);
        prev[0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,INT_MAX);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[0]=prev[0];
                    continue;
                }
                int left=INT_MAX,up=INT_MAX;
                if(i-1>=0) up=grid[i][j]+prev[j];
                if(j-1>=0) left=grid[i][j]+temp[j-1];
   
                temp[j]=min(left,up);
            }
            prev=temp;
        }
        return prev[n-1];
    }
};
