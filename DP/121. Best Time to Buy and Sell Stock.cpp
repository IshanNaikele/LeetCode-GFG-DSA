class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0,maxProfit=0,minPrice=INT_MAX;
        for(int price:prices)
        {
            minPrice=min(price,minPrice);
            maxProfit=max(maxProfit,price-minPrice);
        }
        return maxProfit; 
    }
};