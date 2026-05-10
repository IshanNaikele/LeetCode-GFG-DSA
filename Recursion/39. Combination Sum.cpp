class Solution 
{
public:
    void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&temp,int index)
    {
        if(target==0) 
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            if(target-candidates[i]>=0)
            {
                temp.push_back(candidates[i]);
                solve(candidates,target-candidates[i],ans,temp,i); 
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(candidates,target,ans,temp,index);
        return ans;
    }
};