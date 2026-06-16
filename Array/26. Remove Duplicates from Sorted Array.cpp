class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int left=0,right=0,n=nums.size();

        while(right<n)
        {
            if(nums[left]!=nums[right])
            {
                left++;
                nums[left]=nums[right];
            }
            right++;
        }
        return left+1;
    }
};