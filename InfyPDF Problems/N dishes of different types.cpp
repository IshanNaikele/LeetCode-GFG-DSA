// Ramu has N dishes of different types arranged in a row: A1,A2,…,AN where Ai denotes the type of 
// the ith dish. He wants to choose as many dishes as possible from the given list but while satisfying 
// two conditions: 
// 1. He can choose only one type of dish. 
// 2. No two chosen dishes should be adjacent to each other. 
// Ramu wants to know which type of dish he should choose from, so that he can pick the maximum 
// number of dishes. 
// Example : 
// Given N= 9 and A= [1,2,2,1,2,1,1,1,1] 
// For type 1, Ramu can choose at most four dishes. One of the ways to choose four dishes of type 1 
// is A1,A4, A7 and A9. 
// For type 2, Ramu can choose at most two dishes. One way is to choose A3 and A5. 
// So in this case, Ramu should go for type 1, in which he can pick more dishes. 
// INPUT FORMAT: 
// • The first line contains T, the number of test cases. Then the test cases follow. 
// • For each test case, the first line contains a single integer N. 
// • The second line contains N integers A1,A2,…,AN. 
// OUTPUT FORMAT 
// For each test case, print a single line containing one integer ― the type of the dish that Ramu 
// should choose from. If there are multiple answers, print the smallest one. 
// CONSTRAINTS : 
// • 1 <= T <= 10^3 
// • 1 <= N <= 10^3 
// • 1 <= Ai <= 10^3 
// Sample Input : 
// 3 
// 5 
// 1 2 2 1 2 
// 6 
// 1 1 1 1 1 1 
// 8 
// 1 2 2 2 3 4 2 1 
// Sample Output : 
// 1 
// 1 
// 2

#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;

int solve(vector<int>&arr,int pickedDish,int index)
{
    int n=arr.size();
    if(index>=n) return 0;
    
    int skip=0,take=0;
    
    skip=solve(arr,pickedDish,index+1);
    if(arr[index]==pickedDish)
    take=1+solve(arr,pickedDish,index+2);
    
    return max(skip,take);
}

pair<int,int> findDishType(vector<int>&arr)
{
    set<int>unique(arr.begin(),arr.end());
    int maxDish=0,dishType=INT_MAX;
    for(auto it:unique)
    {
        int ans=solve(arr,it,0);
        if(ans==maxDish)
        {
            if(dishType>it )
            dishType=it;
        }
        else if(maxDish<ans)
        {
            dishType=it;
            maxDish=ans;
        }
    }
    return {dishType,maxDish};
}
#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;

int solve(vector<int>&arr,int pickedDish,int index,vector<int>&dp)
{
    int n=arr.size();
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];
    int skip=0,take=0;
    
    skip=solve(arr,pickedDish,index+1,dp);
    if(arr[index]==pickedDish)
    take=1+solve(arr,pickedDish,index+2,dp);
    
    return dp[index]=max(skip,take);
}

pair<int,int> findDishType(vector<int>&arr)
{
    int n=arr.size();
    set<int>unique(arr.begin(),arr.end());
    int maxDish=0,dishType=INT_MAX;
    
    for(auto it:unique)
    {
        vector<int>dp(n,-1);
        int ans=solve(arr,it,0,dp);
        if(ans==maxDish)
        {
            if(dishType>it )
            dishType=it;
        }
        else if(maxDish<ans)
        {
            dishType=it;
            maxDish=ans;
        }
    }
    return {dishType,maxDish};
}

int main()
{
    vector<int>arr={1, 2 ,2 ,2, 3 ,4 ,2 ,1};
    auto p=findDishType(arr);
    cout<<"Dish Type :"<<p.first<<endl;
    cout<<"Dish Count:"<<p.second;
    return 0;
}