//Recursion 
class Solution
{
public:
    int findSum(vector<int>&nums)
    {
        int totalSum=0;
        for(int num:nums)  totalSum+=num;
        return totalSum;
    }
   
    bool solve(vector<int>&nums,int index,int target)
    {
        int n=nums.size();
        if(target==0) return true;
        if(index==n) return false;
        bool notTake=solve(nums,index+1,target);
        bool take=false;


        if(target-nums[index]>=0)
           take=solve(nums,index+1,target-nums[index]);
       
        return take || notTake;
    }
    bool canPartition(vector<int>& nums)
    {
        int totalSum=findSum(nums);
        if(totalSum%2==1) return false;
       
        return solve(nums,0,totalSum/2);
    }
};

//Memoization 
class Solution
{
public:
    int findSum(vector<int>&nums)
    {
        int totalSum=0;
        for(int num:nums)  totalSum+=num;
        return totalSum;
    }
   
    bool solve(vector<int>&nums,int index,int target,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(target==0) return true;
        if(index==n) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool notTake=solve(nums,index+1,target,dp);
        bool take=false;


        if(target-nums[index]>=0)
           take=solve(nums,index+1,target-nums[index],dp);
       
        return dp[index][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size();
        int totalSum=findSum(nums);
        if(totalSum%2==1) return false;
        int target=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};

//Tabulation 
class Solution
{
public:
    int findSum(vector<int>&nums)
    {
        int totalSum=0;
        for(int num:nums)  totalSum+=num;
        return totalSum;
    }
   
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size();
        int totalSum=findSum(nums);
        if(totalSum%2==1) return false;
        totalSum/=2;
        vector<vector<bool>>dp(n,vector<bool>(totalSum+1,false));
         
        for(int index=0;index<n;index++) dp[index][0]=true;
        if(nums[n-1] <= totalSum)
        dp[n-1][nums[n-1]]=true;


        for(int index=n-2;index>=0;index--)
        {
            for(int target=1;target<=totalSum;target++)
            {
                bool notTake=dp[index+1][target];
                bool take=false;


                if(target-nums[index]>=0)
                take=dp[index+1][target-nums[index]];
                 
                dp[index][target]=take || notTake;
            }
        }
        return dp[0][totalSum];
    }
};


//Space Optimization 
class Solution
{
public:
    int findSum(vector<int>&nums)
    {
        int totalSum=0;
        for(int num:nums)  totalSum+=num;
        return totalSum;
    }
   
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size();
        int totalSum=findSum(nums);
        if(totalSum%2==1) return false;
        totalSum/=2;
        vector<bool>prev(totalSum+1,false);
         
        prev[0]=true;
        if(nums[n-1] <= totalSum)
        prev[nums[n-1]]=true;


        for(int index=n-2;index>=0;index--)
        {
            vector<bool>curr(totalSum+1,false);
            curr[0]=true;
            for(int target=1;target<=totalSum;target++)
            {
                bool notTake=prev[target];
                bool take=false;


                if(target-nums[index]>=0)
                take=prev[target-nums[index]];
                 
                curr[target]=take || notTake;
            }
            prev=curr;
        }
        return prev[totalSum];
    }
};
