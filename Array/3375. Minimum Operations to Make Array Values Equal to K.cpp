class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_set<int>unique;
        for(int num:nums)
        {
            if(num>k) unique.insert(num);
            if(num<k) return -1;
        }
        return unique.size();
    }
};