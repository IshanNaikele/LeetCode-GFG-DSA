class Solution 
{
public:
    bool solve(vector<int>&nums,int target,int index,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(index==n) return false;
        if(target==0) return true;
        if(dp[index][target]!=-1) return dp[index][target];
        bool take = false;
        if(nums[index]<=target)
        take=solve(nums,target-nums[index],index+1,dp);
        bool notTake=solve(nums,target,index+1,dp);

        return dp[index][target]= take || notTake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int totalSum=0,n=nums.size();
        for(int i=0;i<n;i++) totalSum+=nums[i];
        if(totalSum%2==1) return false;
        int target=totalSum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums,target,0,dp);
    }
};