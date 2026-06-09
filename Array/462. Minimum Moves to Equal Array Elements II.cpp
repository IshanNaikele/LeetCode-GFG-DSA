class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int n=nums.size(),median;
        sort(nums.begin(),nums.end());
        if(n%2==1) median=nums[n/2];
        else       median=(nums[n/2]+nums[(n/2)-1])/2;
        int operation=0;
        for(int num:nums)
        operation+=(abs(median-num));
        return operation;
    }
};