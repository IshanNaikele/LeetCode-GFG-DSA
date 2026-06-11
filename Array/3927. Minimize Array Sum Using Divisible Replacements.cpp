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

class Solution {
public:
    long long minArraySum(vector<int>& nums) 
    {
        int maxElement=INT_MIN;
        for(int num:nums) maxElement=max(maxElement,num);

        vector<long long>store(maxElement+1,0);
        for(int num:nums)
           store[num]++;
        
        long long sum=0;
        int n=store.size();
        for(int i=0;i<n;i++)
        {
            if(store[i]==0) continue;
            long long ele=i;
            for(long long  curr=ele;curr<=maxElement;curr+=ele)
            {
                if(store[curr]>0)
                {
                    sum+=(store[curr]*ele);
                    store[curr]=0;
                }
            }
        }
        return sum;
    }
};