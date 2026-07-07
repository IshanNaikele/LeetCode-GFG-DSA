//Approach 1 :- 
class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int k,int target,int index)
    {
        int n=nums.size();
       
        if(temp.size()==k)
        {
            if(target==0)
            ans.push_back(temp);
            return;
        }
         
        if(target<0 || index==n) return ;
        for(int i=index;i<n;i++)
        {
            if(nums[i]>target) break;
            temp.push_back(nums[i]);
            solve(nums,temp,ans,k,target-nums[i],i+1);
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int>temp;
        vector<vector<int>>ans;
        if(k>n) return ans;
        vector<int>nums;
        for(int i=0;i<9;i++) nums.push_back(i+1);
        solve(nums,temp,ans,k,n,0);
        return ans;
    }
};

//Approach 2 (Optimal) :-
class Solution {
public:
    void solve(int start,vector<int>&temp,vector<vector<int>>&ans,int k,int target)
    {
        if(temp.size()==k)
        {
            if(target==0)
            ans.push_back(temp);
            return;
        }
         
        if(target<0 ) return ;
        for(int i=start;i<=9;i++)
        {
            if(i>target) break;
            temp.push_back(i);
            solve(i+1,temp,ans,k,target-i);
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int>temp;
        vector<vector<int>>ans;
        int start=1;
        solve(start,temp,ans,k,n);
        return ans;
    }
};
