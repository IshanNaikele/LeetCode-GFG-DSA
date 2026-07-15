class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int row,int col)
    {
        int m=grid.size(),n=grid[0].size();
        visited[row][col]=1;
         
        if(row+1<m  && visited[row+1][col]==0 && grid[row+1][col]=='O')  dfs(grid,visited,row+1,col);
        if(row-1>=0 && visited[row-1][col]==0 && grid[row-1][col]=='O')  dfs(grid,visited,row-1,col);
        if(col+1<n  && visited[row][col+1]==0 && grid[row][col+1]=='O')  dfs(grid,visited,row,col+1);
        if(col-1>=0 && visited[row][col-1]==0 && grid[row][col-1]=='O')  dfs(grid,visited,row,col-1);
        
    }

    void traverseBoundry(vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        int m=grid.size(),n=grid[0].size();
        
        for(int i=0;i<n;i++) {
            if(visited[0][i]==0   && grid[0][i]=='O')    dfs(grid,visited,0,i);
            if(visited[m-1][i]==0 &&  grid[m-1][i]=='O') dfs(grid,visited,m-1,i);
        }
        for(int i=0;i<m;i++) {
            if(visited[i][0]==0  && grid[i][0]=='O')    dfs(grid,visited,i,0);
            if(visited[i][n-1]==0 && grid[i][n-1]=='O') dfs(grid,visited,i,n-1);
        }
         
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
                if(grid[i][j]=='O' && visited[i][j]==0) grid[i][j]='X';
        }
        
    }

    void solve(vector<vector<char>>&grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        traverseBoundry(grid,visited);
    }
};