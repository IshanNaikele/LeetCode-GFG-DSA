// Problem :
// 12. You have a robot with k battery cycles. 
// Given an array Tasks[] of size n representing energy required per task, 
// and each task must be either: 
// Skipped 
// Executed, which costs Tasks[i] battery 
// You can skip at most m tasks. Maximize number of completed tasks.


#include<iostream>
#include<vector> 
using namespace std;
 
int maxTasks(vector<int>&tasks,int k,int m,int index,vector<vector<vector<int>>>&dp)
{
    int n=tasks.size();
    if(index==n) return 0;
    if(k<tasks[index] && m==0) return 0;
    if(dp[index][k][m]!=-1) return dp[index][k][m];
    int execute=0,skip=0;
    
    if(m>0)
     skip=maxTasks(tasks,k,m-1,index+1,dp);
     
    if(k>=tasks[index])
    execute=1+maxTasks(tasks,k-tasks[index],m,index+1,dp);
    
    return dp[index][k][m]=max(execute,skip);
}
int main()
{
    vector<int>tasks = {5, 1, 1};
    int n=tasks.size();
    int k = 2;
    int m = 1;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(m+1,-1)));
    cout<<maxTasks(tasks,k,m,0,dp);
    return 0;
}