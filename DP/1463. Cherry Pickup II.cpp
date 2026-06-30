//Recursion 
class Solution 
{
public:
    int solve(vector<vector<int>>& grid,int row,int col1,int col2)
    {
        int m=grid.size(),n=grid[0].size();
        int maxCherries=0;

        if(col1<0 || col1>=n || col2<0 || col2>=n) return 0;
        if(row==m-1)
        {
            if(col1==col2) return grid[row][col1];
            else           return grid[row][col1]+grid[row][col2];
        }
        
        int cherries=(col1==col2)?grid[row][col1]:grid[row][col1]+grid[row][col2];

        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
               maxCherries=max(maxCherries,solve(grid,row+1,col1+i,col2+j));
        }

        return cherries+maxCherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        return solve(grid,0,0,n-1);
    }
};

//Memoization 
class Solution
{
public:
    int solve(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int row,int col1,int col2)
    {
        int m=grid.size(),n=grid[0].size();
        int maxCherries=0;


        if(col1<0 || col1>=n || col2<0 || col2>=n) return 0;
        if(row==m-1)
        {
            if(col1==col2) return grid[row][col1];
            else           return grid[row][col1]+grid[row][col2];
        }
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int cherries=(col1==col2)?grid[row][col1]:grid[row][col1]+grid[row][col2];


        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
               maxCherries=max(maxCherries,solve(grid,dp,row+1,col1+i,col2+j));
        }


        return dp[row][col1][col2]=cherries+maxCherries;
    }


    int cherryPickup(vector<vector<int>>& grid)
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(grid,dp,0,0,n-1);
    }
};
