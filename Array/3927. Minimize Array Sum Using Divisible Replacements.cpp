class Solution {
public:
    long long minArraySum(vector<int>& nums) 
    {
        int n=nums.size() ;
        int maxElement=INT_MIN;
        long long sum=0;
        map<long long ,long long>mpp;

        for(int num:nums)
        {
            mpp[num]++;
            maxElement=max(maxElement,num);
        }

        for(auto &it:mpp)
        {
            if(it.second==0) continue;
            long long ele=it.first;
            for(long long curr=ele;curr<=maxElement;curr+=ele)
            {
                if(mpp.count(curr) && mpp[curr]>0){
                  sum+=(mpp[curr]*ele);
                  mpp[curr]=0;
                }
            }
        }
        return sum;
    }
};