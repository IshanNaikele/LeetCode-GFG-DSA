class Solution {
public:
    int robbery1(vector<int>&nums)
    {
        int n=nums.size();
        int first=nums[0];
        if(n==1) return first;
        int second=max(nums[0],nums[1]);

        for(int i=2;i<n-1;i++)
        {
            int third=max(first+nums[i],second);
            first=second;
            second=third;
        }
        return second;
    }

     int robbery2(vector<int>&nums)
    {
        int n=nums.size();
        int first=nums[1];
        if(n==2) return first;
        int second=max(nums[2],nums[1]);

        for(int i=3;i<n;i++)
        {
            int third=max(first+nums[i],second);
            first=second;
            second=third;
        }
        return second;
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int first=robbery1(nums);
        if(n==1 || n==2) return first;
        int second=robbery2(nums);
        return max(first,second);
    }
};

