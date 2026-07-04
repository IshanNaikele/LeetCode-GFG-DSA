class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) 
    {
        int left=0,n=nums.size(),count=0;
        unordered_map<int,int>mpp;
        int distinctNum=0;
        for(int right=0;right<n;right++)
        {
            if(mpp[nums[right]]==0)  distinctNum++;
            mpp[nums[right]]++;
            while(  distinctNum>k)
            {
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) distinctNum--;
                left++;
            }

            count+=(right-left+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atMostKDistinct(nums,k)-atMostKDistinct(nums,k-1);
    }
};    