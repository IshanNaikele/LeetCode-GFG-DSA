class Solution {
public:
    long long solve(vector<vector<int>>& grid,vector<vector<int>>&visited,int row,int col)
    {
        int m=grid.size(),n=grid[0].size();
 
        if(row==m-1 && col==n-1) return 1;
        visited[row][col]=1;
        long long topLeft=INT_MAX,topMid=INT_MAX,topRight=INT_MAX,left=INT_MAX,right=INT_MAX,downLeft=INT_MAX,downMid=INT_MAX,downRight=INT_MAX;
        
        if(row-1>=0)
        {
            if(col-1>=0 && grid[row-1][col-1]==0 && visited[row-1][col-1]==0)
            topLeft=1+solve(grid,visited,row-1,col-1);
            if(grid[row-1][col]==0 && visited[row-1][col]==0)
            topMid=1+solve(grid,visited,row-1,col);
            if(col+1<n && grid[row-1][col+1]==0 && visited[row-1][col+1]==0)
            topRight=1+solve(grid,visited,row-1,col+1);
        }

        if(col-1>=0 && grid[row][col-1]==0 && visited[row][col-1]==0)
        left=1+solve(grid,visited,row,col-1);
        if(col+1<n && grid[row][col+1]==0 && visited[row][col+1]==0)
        right=1+solve(grid,visited,row,col+1);

        if(row+1<m)
        {
            if(col-1>=0 && grid[row+1][col-1]==0 && visited[row+1][col-1]==0)
            topLeft=1+solve(grid,visited,row+1,col-1);
            if(grid[row+1][col]==0 && visited[row+1][col]==0)
            topMid=1+solve(grid,visited,row+1,col);
            if(col+1<n && grid[row+1][col+1]==0 && visited[row+1][col+1]==0)
            topRight=1+solve(grid,visited,row+1,col+1);  
        }

        visited[row][col]=0;
        return min({topLeft,topMid,topRight,left,right,downLeft,downMid,downRight});
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        vector<vector<int>>visited(m,vector<int>(n,0));
        long long ans=solve(grid,visited,0,0);
        return (ans==INT_MAX)?-1:ans;
    }
};