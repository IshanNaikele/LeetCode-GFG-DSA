class Solution {
  public:
    void find(vector<int>&nums,int target,int index,int &count)
    {
        int n=nums.size();
        if(index==n) 
        {
            if(target==0)  count++;
            return;
        }
         
        find(nums,target,index+1,count);
        find(nums,target-nums[index],index+1,count);
    }
    
    int countPartitions(vector<int>& nums, int diff) 
    {
        // Code here
        int totalSum=0,index=0;
        int count=0;
        for(int num:nums) totalSum+=num;
        totalSum-=diff;
        if(totalSum%2==1) return 0;
        find(nums,totalSum/2,index,count);
        return count;
    }
};