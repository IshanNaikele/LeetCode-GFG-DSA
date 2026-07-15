class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>&mat )
    {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int dist=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                ans[row][col]=dist;
                q.pop();
                
                if(row+1<m && visited[row+1][col]==0)
                {
                    q.push({row+1,col});
                    visited[row+1][col]=1;
                }
                if(row-1>=0 && visited[row-1][col]==0)
                {
                    q.push({row-1,col});
                    visited[row-1][col]=1;
                }
                if(col+1<n && visited[row][col+1]==0)
                {
                    q.push({row,col+1});
                    visited[row][col+1]=1;
                }
                if(col-1>=0 && visited[row][col-1]==0)
                {
                    q.push({row,col-1});
                    visited[row][col-1]=1;
                }
            } 
            dist++;
        }
        return ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        return bfs(mat);
    }
};