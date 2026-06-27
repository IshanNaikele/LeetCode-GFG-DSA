// Recursion 
#include<iostream>
#include<algorithm>
int solve(vector<vector<int>> &points,int row,int col)
{
    int n=points.size();
    int colChoice1,colChoice2;
    if(row==n) return 0;
    if(col==0)
    {
        colChoice1=1;
        colChoice2=2;
    }
    else if(col==1)
    {
        colChoice1=0;
        colChoice2=2;
    }
    else
    {
        colChoice1=0;
        colChoice2=1;
    }
    return points[row][col] +
           max(
               solve(points,row+1,colChoice1),
               solve(points,row+1,colChoice2)
           );
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return max({solve(points,0,0),
                solve(points,0,1),
                solve(points,0,2)
                });
    
}

//Memoization 
#include<iostream>
#include<algorithm>
#include<vector>
int solve(vector<vector<int>> &points,vector<vector<int>>&dp ,int row,int col)
{
    int n=points.size();
    int colChoice1,colChoice2;
    if(row<0) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    if(col==0)
    {
        colChoice1=1;
        colChoice2=2;
    }
    else if(col==1)
    {
        colChoice1=0;
        colChoice2=2;
    }
    else
    {
        colChoice1=0;
        colChoice2=1;
    }
    return dp[row][col]=points[row][col] +
           max(
               solve(points,dp,row-1,colChoice1),
               solve(points,dp,row-1,colChoice2)
           );
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(3,-1));
    return max({solve(points,dp,n-1,0),
                solve(points,dp,n-1,1),
                solve(points,dp,n-1,2)
                });
    
}

//Tabulation 
#include<iostream>
#include<algorithm>
#include<vector>
 
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(3));


    // Base
    dp[0][0]=points[0][0];
    dp[0][1]=points[0][1];
    dp[0][2]=points[0][2];


    for(int day=1; day<n; day++)
    {
        dp[day][0]=points[day][0]
                  + max(dp[day-1][1],
                        dp[day-1][2]);


        dp[day][1]=points[day][1]
                  + max(dp[day-1][0],
                        dp[day-1][2]);


        dp[day][2]=points[day][2]
                  + max(dp[day-1][0],
                        dp[day-1][1]);
    }


    return max({
        dp[n-1][0],
        dp[n-1][1],
        dp[n-1][2]
    });
    
}

//Space Optimization 
#include<iostream>
#include<algorithm>
#include<vector>
 
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
     


    // Base
    int first=points[0][0];
    int second=points[0][1];
    int third=points[0][2];
    


    for(int day=1; day<n; day++)
    {
        int one=points[day][0]
                  + max(second,
                        third);


        int two=points[day][1]
                  + max(first,
                        third);


        int three=points[day][2]
                  + max(first,
                        second);


        first=one;
        second=two;
        third=three;
    }


    return max({
        first,
        second,
        third
    });
    
}
