//Recursion 
class Solution {
public:
    int solve(vector<vector<int>>& matrix,int row,int col)
    {
        int n=matrix.size();
        int bottomLeft=INT_MAX,bottom=INT_MAX,bottomRight=INT_MAX;
        if(row==n-1) return matrix[row][col];
        
        if(col-1>=0)
        bottomLeft=matrix[row][col]+solve(matrix,row+1,col-1);
        bottom=matrix[row][col]+solve(matrix,row+1,col);
        if(col+1<n)
        bottomRight=matrix[row][col]+solve(matrix,row+1,col+1);

        return min({bottomLeft,bottom,bottomRight});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(),minSum=INT_MAX;
        for(int i=0;i<n;i++)
            minSum=min(minSum,solve(matrix,0,i));

        return minSum;
    }
};

//Memoization 
class Solution {
public:
    int solve(vector<vector<int>>& matrix,vector<vector<int>>&dp,int row,int col)
    {
        int n=matrix.size();
        int bottomLeft=INT_MAX,bottom=INT_MAX,bottomRight=INT_MAX;
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        if(col-1>=0)
        bottomLeft=matrix[row][col]+solve(matrix,dp,row+1,col-1);
        bottom=matrix[row][col]+solve(matrix,dp,row+1,col);
        if(col+1<n)
        bottomRight=matrix[row][col]+solve(matrix,dp,row+1,col+1);

        return dp[row][col]=min({bottomLeft,bottom,bottomRight});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(),minSum=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++)
            minSum=min(minSum,solve(matrix,dp,0,i));

        return minSum;
    }
};

//Tabulation 
class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(),minSum=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
           dp[n-1][i]=matrix[n-1][i];

        for(int i=n-2;i>=0;i--)
        {
            int bottomLeft=INT_MAX,bottom=INT_MAX,bottomRight=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(j-1>=0)
                bottomLeft=matrix[i][j]+dp[i+1][j-1];
                bottom=matrix[i][j]+dp[i+1][j];
                if(j+1<n)
                bottomRight=matrix[i][j]+dp[i+1][j+1];


                dp[i][j]=min({bottomLeft,bottom,bottomRight});
            }   
        }  

        for(int i=0;i<n;i++)
            minSum=min(minSum,dp[0][i]);

        return minSum;
    }
};

//Space Optimized 
class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(),minSum=INT_MAX;
        vector<int>prev(n,0);
        
        for(int i=0;i<n;i++)
           prev[i]=matrix[n-1][i];

        for(int i=n-2;i>=0;i--)
        {
            vector<int>temp(n,0);
            int bottomLeft=INT_MAX,bottom=INT_MAX,bottomRight=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(j-1>=0)
                bottomLeft=matrix[i][j]+prev[j-1];
                bottom=matrix[i][j]+prev[j];
                if(j+1<n)
                bottomRight=matrix[i][j]+prev[j+1];


                temp[j]=min({bottomLeft,bottom,bottomRight});
            }   
            prev=temp;
        }  

        for(int i=0;i<n;i++)
            minSum=min(minSum,prev[i]);

        return minSum;
    }  
};   