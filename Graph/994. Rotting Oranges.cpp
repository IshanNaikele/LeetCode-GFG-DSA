class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>&visited)
    {
        int m=grid.size(),n=grid[0].size();
        int count=0,freshOrg=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1)
                  freshOrg++;
            }
        }

        while(!q.empty() && freshOrg!=0)
        {
            int size=q.size();
            count++;
            for(int i=0;i<size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row+1<m && visited[row+1][col]==0 && grid[row+1][col]==1)     
                {
                    visited[row+1][col]=1;
                    q.push({row+1,col});
                    grid[row+1][col]=2;
                    freshOrg--;
                }
                if(row-1>=0 && visited[row-1][col]==0 && grid[row-1][col]==1)
                {
                    visited[row-1][col]=1;
                    q.push({row-1,col});
                    grid[row-1][col]=2;
                    freshOrg--;
                }
                if(col+1<n && visited[row][col+1]==0 && grid[row][col+1]==1)
                {
                    visited[row][col+1]=1;
                    q.push({row,col+1});
                    grid[row][col+1]=2;
                    freshOrg--;
                }
                if(col-1>=0 && visited[row][col-1]==0 && grid[row][col-1]==1) 
                {
                    visited[row][col-1]=1;
                    q.push({row,col-1});
                    grid[row][col-1]=2;
                    freshOrg--;
                }
            }
        }
        return freshOrg==0?count:-1;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));
        return bfs(grid,visited);
    }
};