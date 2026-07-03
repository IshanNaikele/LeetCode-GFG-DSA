class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int left=0,n=nums.size(),maxLen=1;
        unordered_map<int,int>mpp;
        for(int right=0;right<n;right++)
        {
            mpp[nums[right]]++;
            while(left<right && mpp[nums[right]]>k)
            {
                mpp[nums[left]]--;
                left++;
            }

            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};