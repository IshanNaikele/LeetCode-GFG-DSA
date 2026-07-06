class Solution {
public:
    int atMostKOddSubarray(vector<int>& nums,int k)
    {
        int n=nums.size(),left=0;
        int oddOccurence=0,count=0;;
        for(int right=0;right<n;right++)
        {
            int num=nums[right];
            if(num%2==1) oddOccurence++;

            while(oddOccurence>k)
            {
                if(nums[left]%2==1) oddOccurence--;
                left++;
            }
            
            count+=(right-left+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return atMostKOddSubarray(nums,k)-atMostKOddSubarray(nums,k-1);
    }
};