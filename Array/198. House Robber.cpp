class Solution {
public:
     
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int prev = nums[0];                     
        int prev2 = max(nums[0], nums[1]);  
        int curr;     
        for(int i=2;i<n;i++)
        {
            curr=max(prev+nums[i],prev2);
            prev=prev2;
            prev2=curr;
        }
        return curr;
    }
};