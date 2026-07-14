class Solution {
  public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int row,int col)
    {
        int m=grid.size(),n=grid[0].size();
        visited[row][col]=1;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(row+i>=0 && col+j>=0 && row+i<m && col+j<n && visited[row+i][col+j]==0 && grid[row+i][col+j]=='L')
                dfs(grid,visited,row+i,col+j);
            }
        }
    }
    
    int countIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int m=grid.size(),n=grid[0].size(),count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='L' && visited[i][j]==0)
                {
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};