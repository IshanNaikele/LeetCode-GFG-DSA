//Recursion 
class Solution
{
public:
    bool solve(vector<int>&nums,int index)
    {
        int n=nums.size();
        if(index==n-1) return true;
        if(index>=n)   return false;
        if(nums[index]==0) return false;


        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums)
    {
        return solve(nums,0);
    }
};


//Memoization 
class Solution
{
public:
    bool solve(vector<int>&nums,int index,vector<int>&dp)
    {
        int n = nums.size();


        if(index >= n - 1)
            return true;


        if(dp[index] != -1)
            return dp[index];


        for(int jump = 1; jump <= nums[index]; jump++)
        {
            if(solve(nums, index + jump, dp))
                return dp[index] = true;
        }


        return dp[index] = false;
    }
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};

//Greedy 
class Solution
{
public:
     
    bool canJump(vector<int>& nums)
    {
        int n=nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++)
        {
            if(maxIndex>=i && nums[i]+i>maxIndex)  maxIndex=nums[i]+i;
            if(maxIndex>=(n-1)) return true;
        }
        return false;
    }
};
