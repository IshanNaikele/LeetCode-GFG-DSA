class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& nums)
    {
        // code here
        int n=nums.size();
        for(int num:nums)
        {
            int index=(num-1)%n;
            nums[index]+=n;
        }
        for(int i=0;i<n;i++)
        {
            int occurence=(nums[i]-1)/n;
            nums[i]=occurence;
        }
        return nums;
    }
};
