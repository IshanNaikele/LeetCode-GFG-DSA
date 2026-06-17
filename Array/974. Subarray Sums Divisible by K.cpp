class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n=nums.size(),sum=0,count=0 ;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=((sum%k)+k)%k;
            count+=mpp[rem];
            mpp[rem]++;
        }
        return count;
    }
};