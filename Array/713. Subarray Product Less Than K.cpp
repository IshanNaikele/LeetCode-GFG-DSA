class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int left=0,right=0,n=nums.size();
        int prod=1,count=0;
        while(right<n)
        {
            prod*=nums[right];
            while(left<right && prod>=k)
            {
                prod/=nums[left]; 
                left++;
            }
            if(prod<k)
            count=count+(right-left+1);
            right++;
        }
        return count;
    }
};