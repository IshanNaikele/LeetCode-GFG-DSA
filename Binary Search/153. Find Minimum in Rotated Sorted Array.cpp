class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size();
        int start=0,end=n-1,index=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(nums[mid]>nums[n-1])
               start=mid+1;
            else
            {
               index=mid;
               end=mid-1;
            }
        }
        return nums[index];
    }
};