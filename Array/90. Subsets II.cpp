class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int index)
    {
        int n=nums.size();
        
        ans.push_back(temp);

        for(int i=index;i<n;i++)
        {

            if(i>index && nums[i]==nums[i-1])
            continue;
            temp.push_back(nums[i]);
            solve(nums,temp,ans,i+1 );
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,temp,ans,0);
        return ans;
    }
};