class Solution {
public:
    long long solve(vector<int>&nums,int index,vector<int>&dp)
    {
        int n=nums.size();
        if(index==n-1) return 0;
        if(dp[index]!=INT_MAX) return dp[index];
        int minJumps=INT_MAX;
        for(int i=1;i<=nums[index] && index+i<n;i++)
        {
            long long ans=1+solve(nums,index+i,dp);
            if(ans!=INT_MAX){
                if(minJumps>ans)
                minJumps=ans;
            }
        }
        return dp[index]=minJumps;
    }

    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,INT_MAX);
        return solve(nums,0,dp);
    }
};