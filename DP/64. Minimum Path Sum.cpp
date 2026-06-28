class Solution 
{
public:
     
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        
        vector<int>prev(n,0);
        prev[0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,INT_MAX);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[0]=prev[0];
                    continue;
                }
                int left=INT_MAX,up=INT_MAX;
                if(i-1>=0) up=grid[i][j]+prev[j];
                if(j-1>=0) left=grid[i][j]+temp[j-1];
   
                temp[j]=min(left,up);
            }
            prev=temp;
        }
        return prev[n-1];
    }
};