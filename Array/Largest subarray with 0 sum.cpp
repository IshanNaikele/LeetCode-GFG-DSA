class Solution {
  public:
    int maxLength(vector<int>& nums) 
    {
        // code here
        int maxLen=0,sum=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==0) maxLen=max(maxLen,i+1);
            if(mpp.find(sum)!=mpp.end())
            maxLen=max(maxLen,i-mpp[sum]);
            if(mpp.find(sum)==mpp.end())
            mpp[sum]=i;
        }
        return maxLen;
    }
};