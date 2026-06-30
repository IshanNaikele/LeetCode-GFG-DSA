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

//Tabulation 

class Solution 
{
public:

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));

        for(int j1=0;j1<n;j1++)
        {
            for(int j2=0;j2<n;j2++)
            {
                if(j1==j2)
                dp[m-1][j1][j2]=grid[m-1][j1];
                else
                dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }
        

        for(int i=m-2;i>=0;i--)
        {
            for(int j1=0;j1<n;j1++)
            {
                for(int j2=0;j2<n;j2++)
                {
                    int maxCherries=0; 
                    for(int dj1=-1;dj1<2;dj1++)
                        {
                            for(int dj2=-1;dj2<2;dj2++)
                            {
                                int value=0;
                                if(j1+dj1<0 || j1+dj1>=n || j2+dj2<0 || j2+dj2>=n ) continue;
                                if(j1==j2) value=grid[i][j1];
                                else       value=grid[i][j1]+grid[i][j2];

                                value+=dp[i+1][j1+dj1][j2+dj2];

                                maxCherries=max(maxCherries,value);
                            }
                        }
                    dp[i][j1][j2]=maxCherries;
                }
            }
        }
        return  dp[0][0][n-1] ;
    }
};

//Space Optimized

class Solution 
{
public:

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>front(n,vector<int>(n,-1));
        for(int j1=0;j1<n;j1++)
        {
            for(int j2=0;j2<n;j2++)
            {
                if(j1==j2)
                front[j1][j2]=grid[m-1][j1];
                else
                front[j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }
        

        for(int i=m-2;i>=0;i--)
        {
            vector<vector<int>>curr(n,vector<int>(n,-1));
            for(int j1=0;j1<n;j1++)
            {
                for(int j2=0;j2<n;j2++)
                {
                    int maxCherries=0; 
                    for(int dj1=-1;dj1<2;dj1++)
                        {
                            for(int dj2=-1;dj2<2;dj2++)
                            {
                                int value=0;
                                if(j1+dj1<0 || j1+dj1>=n || j2+dj2<0 || j2+dj2>=n ) continue;
                                if(j1==j2) value=grid[i][j1];
                                else       value=grid[i][j1]+grid[i][j2];

                                value+=front[j1+dj1][j2+dj2];

                                maxCherries=max(maxCherries,value);
                            }
                        }
                    curr[j1][j2]=maxCherries;
                }
            }
            front=curr;
        }
        return  front[0][n-1];
    }
};