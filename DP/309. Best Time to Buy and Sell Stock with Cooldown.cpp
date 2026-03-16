class Solution {
public:
    int t[5001][2];
    int solve(vector<int>prices,int day,bool buy)
    {
        int n=prices.size(),profit=0;
        if(day>=n) return 0;
        
        if(t[day][buy]!=-1) return t[day][buy];
        if(buy)
        {
            int take=solve(prices,day+1,false)-prices[day];
            int notTake=solve(prices,day+1,true);
            profit=max({profit,take,notTake});
        }
        else
        {
            int sell=prices[day]+solve(prices,day+2,true);
            int notSell=solve(prices,day+1,false);
            profit=max({profit,sell,notSell});
        }
        return t[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        memset(t,-1,sizeof(t));
        return solve(prices,0,true);
    }
};


 class Solution {
public:
     
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n==0 || n==1) return 0;
        vector<int>t(n,0);
        t[0]=0;
        t[1]=max(prices[1]-prices[0],0);
        for(int i=2;i<n;i++)
        {
            t[i]=t[i-1];
            for(int j=0;j<i;j++)
            {
                int todayProfit=prices[i]-prices[j];
                int prevProfit=j>1?t[j-2]:0;
                t[i]=max(t[i],todayProfit+prevProfit);
            }
        }
        return t[n-1];
    }
};