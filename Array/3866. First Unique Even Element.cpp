class Solution {
public:
    int firstUniqueEven(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>freq(101,0);
        for(int i=0;i<n;i++)   freq[nums[i]]++;

        for(int i=0;i<n;i++)
        {
            if(freq[nums[i]]==1 && nums[i]%2==0)
            {
                return nums[i];
            }
        }
        return -1;
    }
};