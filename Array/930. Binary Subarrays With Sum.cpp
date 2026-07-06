class Solution {
public:
    int atMostKSum(vector<int>&nums,int goal)
    {
        int n=nums.size();
        int left=0 ;
        int count=0;
        int sum=0;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right]; 
            while(sum>goal)
            {
                sum-=nums[left];
                left++;
            }

            count+=(right-left+1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        if(goal==0) return atMostKSum(nums,goal);
        return atMostKSum(nums,goal)-atMostKSum(nums,goal-1);
    }
};