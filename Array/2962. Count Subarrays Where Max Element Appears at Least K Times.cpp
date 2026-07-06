class Solution 
{
public:
    int findMaxElement(vector<int>&nums)
    {
        int maxElement=INT_MIN;
        for(int num:nums) maxElement=max(num,maxElement);
        return maxElement;
    }
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int maxElement=findMaxElement(nums);

        int left=0,n=nums.size();
        long long count=0,occurence=0;

        for(int right=0;right<n;right++)
        {
            if(nums[right]==maxElement) occurence++;
            while(occurence>=k)
            {
                count+=(n-right);
                if(nums[left]==maxElement) occurence--;
                left++;
            }
        }
        return count;
    }
};