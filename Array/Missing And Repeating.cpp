class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) 
    {
        // code here
        int n=nums.size(),repeating=-1,missing=-1;
        for(int num:nums)
        {
            int index=((num-1)%n);
            nums[index]+=n;
        }
        for(int i=0;i<n;i++)
        {
            int occurence=(nums[i]-1)/n;
            if(occurence==2)      repeating=i+1;
            if(occurence==0)      missing=i+1;
        }
        return {repeating,missing};
    }
};