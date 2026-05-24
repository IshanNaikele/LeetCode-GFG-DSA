
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        vector<vector<double>>v;
        int n=val.size();
        for(int i=0;i<n;i++)    v.push_back({(double)val[i]/wt[i],val[i],wt[i]});
        sort(v.begin(),v.end(),greater<>());
        double ans=0;
        int i=0;
        while(capacity>0 && i<n)
        {
            if(v[i][2]<=capacity)
            ans+=v[i][1];
            else
            {
                double temp=v[i][0] ;
                temp*=capacity;
                ans+=temp;
            }
            
            capacity-=v[i][2];
            i++;
        }
        return ans;
    }
};
