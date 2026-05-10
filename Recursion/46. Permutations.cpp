class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<bool>&visited,vector<int>&temp)
    {
        if(temp.size()==nums.size()) 
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                temp.push_back(nums[i]);
                solve(nums,ans,visited,temp);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<bool>visited(nums.size(),0);
        vector<int>temp;
        solve(nums,ans,visited,temp);
        return ans;
    }
};