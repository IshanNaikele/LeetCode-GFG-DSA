class Solution {
public:
    int minNumberOperations(vector<int>& target) 
    {
        int n=target.size(),ans=0;
        ans+=target[0];
        for(int i=1;i<n;i++)
        {
            if(target[i]>target[i-1])
            ans+=(abs(target[i]-target[i-1]));
        }
        return ans;
    }
};