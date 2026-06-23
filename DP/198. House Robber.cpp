//Recursion 
class Solution {
public:
    int solve(vector<int>&nums,int index)
    {
        int n=nums.size();
        if(index>=n) return 0;


        int take=nums[index]+solve(nums,index+2);
        int skip=solve(nums,index+1);


        return max(take,skip);
    }
    int rob(vector<int>& nums)
    {
        return solve(nums,0);
    }
};

//Memoization 
class Solution {
public:
    int solve(vector<int>&nums,vector<int>&dp,int index)
    {
        int n=nums.size();
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int take=nums[index]+solve(nums,dp,index-2);
        int skip=solve(nums,dp,index-1);


        dp[index]=max(take,skip);
        return dp[index];
    }
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,dp,n-1);
    }
};

//Tabulation or Bottom Up Approach 
class Solution
{
public:
   
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        if(n==1) return dp[0];
        dp[1]=max(nums[0],nums[1]);


        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
       
        return dp[n-1];
    }
};

//Space Optimized 
class Solution
{
public:
   
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        int first=nums[0];
        if(n==1) return first;
        int second=max(nums[0],nums[1]);


        for(int i=2;i<n;i++)
        {
            int third=max(first+nums[i],second);
            first=second;
            second=third;
        }
        return second;
    }
};

