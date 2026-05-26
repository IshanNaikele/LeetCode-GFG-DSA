class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int>mpp;
        int count=0;
        for(char ch:tasks) 
        {
            mpp[ch]++;
            count=max(count,mpp[ch]);
        }
        int ans=(count-1)*(n+1);

        for(auto &it:mpp)    if(it.second==count) ans++;
        
        if(tasks.size()>ans) ans=tasks.size();
        return ans;
    }
};