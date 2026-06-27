class Solution 
{
public:
     
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<int>prev(n,0);
        prev[0]=1;
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)   {
                    temp[j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1)
                {
                    temp[j]=0;
                    continue;
                }
                int left=0,up=0;
                if(j>=0)    up=prev[j];
                if(j-1>=0)  left=temp[j-1];
                
                temp[j]=up+left;
            }
            prev=temp;
        }
        return prev[n-1];
    }
};