class Solution 
{
public:
 
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<long long>>prev(2,vector<long long >(k+1,0));
        vector<vector<long long>>curr(2,vector<long long >(k+1,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int count=1;count<=k;count++)
                {
                    int profit=0;
                    if(buy)
                    profit=max(-prices[index]+prev[0][count],prev[1][count]);
                    else
                    profit=max(prices[index]+prev[1][count-1],prev[0][count]);

                    curr[buy][count]=profit;
                }
            }
            prev=curr;
        }
        return prev[1][k]; 
    }
};