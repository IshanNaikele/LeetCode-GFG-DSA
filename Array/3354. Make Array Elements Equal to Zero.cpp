class Solution {
public:
   
    int countValidSelections(vector<int>& nums) 
    {
        int totalSum=0,prefixSum=0,n=nums.size(),validAns=0;
        for(int num:nums) totalSum+=num;

        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];

            if(nums[i]==0)
            {
                int rightSum=totalSum-prefixSum;
                int leftSum=prefixSum;
                if(rightSum==leftSum)                           validAns+=2;
                else if(abs(rightSum-leftSum)==1)               validAns++;
            }
        }
        return validAns;
    }
};