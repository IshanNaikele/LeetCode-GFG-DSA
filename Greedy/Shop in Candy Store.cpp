class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) 
    {
        // Code here
        sort(prices.begin(),prices.end());
        int n=prices.size(),minMoney=0,maxMoney=0;
        int skip=0,prev=0;
        for(int i=0;i<n;i++)
        { 
            minMoney+=prices[i];
            maxMoney+=prices[n-i-1];
            skip+=k+i-prev;
            prev=i;
            if(skip>=n-1) break;
             
        }
        return {minMoney,maxMoney};
    }
};