class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)  target[i]-=nums[i];
        int prev=0;
        long long opr=0;
        for(int i=0;i<n;i++)
        {
            int curr=target[i];
            if((curr>0 && prev<0) || (curr<0 && prev>0))      opr+=abs(curr);
            else if(abs(curr)>abs(prev))                      opr+=abs(curr-prev);      
            prev=curr;
        }
        return opr;
    }
};