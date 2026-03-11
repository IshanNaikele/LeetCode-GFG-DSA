class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int n=arr.size(),count=0,M=1e9+7;
        int even=1,odd=0,prefixSum=0;
        for(int i=0;i<n;i++)
        {
            prefixSum+=arr[i];
            if(prefixSum%2==1)   count=(count+even)%M;
            else                 count=(count+odd)%M;

            if(prefixSum%2==0) even++;
            else               odd++;
        }
        return count;
    }
};