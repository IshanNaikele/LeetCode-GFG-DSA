class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) 
    {
        int n=nums.size(),start=0;
        int maxNum=nums[start],maxSum=0;
        for(int i=k;i<n;i++)
        {
            start++;
            maxSum=max(maxSum,maxNum+nums[i]);
            maxNum=max(maxNum,nums[start]);
        }
        return maxSum;
    }
};