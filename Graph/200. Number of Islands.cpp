class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int row,int col)
    {
        int m=grid.size(),n=grid[0].size();
        visited[row][col]=1;
         
        if(row-1>=0 && visited[row-1][col]==0 && grid[row-1][col]=='1')
        dfs(grid,visited,row-1,col);
        if(row+1<m && visited[row+1][col]==0 && grid[row+1][col]=='1')
        dfs(grid,visited,row+1,col);
        if(col-1>=0 && visited[row][col-1]==0 && grid[row][col-1]=='1')
        dfs(grid,visited,row,col-1);
        if(col+1<n && visited[row][col+1]==0 && grid[row][col+1]=='1')
        dfs(grid,visited,row,col+1);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size(),n=grid[0].size(),count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};