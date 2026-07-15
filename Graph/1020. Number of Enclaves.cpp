class Solution {
public: 
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int row,int col)
    {
        int m=grid.size(),n=grid[0].size();
        visited[row][col]=1;
         
        if(row+1<m  && visited[row+1][col]==0 && grid[row+1][col]==1)  dfs(grid,visited,row+1,col);
        if(row-1>=0 && visited[row-1][col]==0 && grid[row-1][col]==1)  dfs(grid,visited,row-1,col);
        if(col+1<n  && visited[row][col+1]==0 && grid[row][col+1]==1)  dfs(grid,visited,row,col+1);
        if(col-1>=0 && visited[row][col-1]==0 && grid[row][col-1]==1)  dfs(grid,visited,row,col-1);
        
    }

    int solve(vector<vector<int>>&grid,vector<vector<int>>&visited)
    {
        int m=grid.size(),n=grid[0].size(),count=0;
        
        for(int i=0;i<n;i++) {
            if(visited[0][i]==0   && grid[0][i]==1)    dfs(grid,visited,0,i);
            if(visited[m-1][i]==0 &&  grid[m-1][i]==1) dfs(grid,visited,m-1,i);
        }
        for(int i=0;i<m;i++) {
            if(visited[i][0]==0  && grid[i][0]==1)   dfs(grid,visited,i,0);
            if(visited[i][n-1]==0 && grid[i][n-1]==1) dfs(grid,visited,i,n-1);
        }
         
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
                if(grid[i][j]==1 && visited[i][j]==0) count++;
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        return solve(grid,visited);
    }
};