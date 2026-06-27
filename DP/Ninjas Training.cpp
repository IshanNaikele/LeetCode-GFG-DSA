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

