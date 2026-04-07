class Solution {
public:
    
    void subseq(vector<int>nums,int start,int end,vector<int>&temp,vector<vector<int>>&result)
    {
        if(start>end) 
        {
            result.push_back(temp);
            return ;
        }
        subseq(nums,start+1,end,temp,result);
        temp.push_back(nums[start]);
        subseq(nums,start+1,end,temp,result);

        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int start=0,end=nums.size()-1;
        vector<int>temp;
        vector<vector<int>>result;
        subseq(nums,start,end,temp,result);
        return result;
    }
};