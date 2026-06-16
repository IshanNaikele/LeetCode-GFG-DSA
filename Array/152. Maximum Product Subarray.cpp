class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxProd=INT_MIN,n=nums.size();
        int prefixProd=1,suffixProd=1;
        for(int i=0;i<n;i++)
        {
            prefixProd*=nums[i];
            suffixProd*=nums[n-i-1];
            maxProd=max({prefixProd,suffixProd,maxProd});
            if(prefixProd==0) prefixProd=1;
            if(suffixProd==0) suffixProd=1;
        }
        return maxProd;
    }
};