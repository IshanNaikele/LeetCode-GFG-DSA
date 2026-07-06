class Solution {
public:
    int atMostKZeros(vector<int>&nums,int k)
    {
        int left=0,n=nums.size();
        int maxLen=0;
        int count=0;

        for(int right=0;right<n;right++)
        {
            int num=nums[right];
            if(num==0) count++;

            while(count>k)
            {
                if(nums[left]==0) count--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
    int longestOnes(vector<int>& nums, int k) 
    {
        return atMostKZeros(nums,k);
    }
};