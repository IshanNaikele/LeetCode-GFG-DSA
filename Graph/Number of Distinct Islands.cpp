class Solution {
  public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int row,int col,vector<pair<int,int>>&vec,int row0,int col0)
    {
        int m=grid.size(),n=grid[0].size();
        visited[row][col]=1;
        vec.push_back({row-row0,col-col0});
        if(row+1<m && visited[row+1][col]==0 && grid[row+1][col]=='L') 
        dfs(grid,visited,row+1,col,vec,row0,col0);
        if(col+1<n && visited[row][col+1]==0 && grid[row][col+1]=='L')
        dfs(grid,visited,row,col+1,vec,row0,col0);
        if(row-1>=0&& visited[row-1][col]==0 && grid[row-1][col]=='L')
        dfs(grid,visited,row-1,col,vec,row0,col0);
        if(col-1>=0&& visited[row][col-1]==0 && grid[row][col-1]=='L')
        dfs(grid,visited,row,col-1,vec,row0,col0);
        
        
    }
    
    int countDistinctIslands(vector<vector<char>>& grid) 
    {
        // code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        set<vector<pair<int,int>>>unique;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='L'){
                    vector<pair<int,int>>v;
                    dfs(grid,visited,i,j,v,i,j);
                    unique.insert(v);
                }
            }
        }
        return unique.size();
    }
};
