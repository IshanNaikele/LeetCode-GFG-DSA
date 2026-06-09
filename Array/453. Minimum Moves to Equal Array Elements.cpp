class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int minElement=INT_MAX,operation=0;
        for(int num:nums) minElement=min(minElement,num);
        for(int num:nums) operation+=(num-minElement);
        return operation;
    }
};