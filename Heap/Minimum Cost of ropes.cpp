class Solution {
  public:
    int minCost(vector<int>& arr) 
    {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        
        int cost=0;
        while(pq.size()>1)
        {
            int sum=pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            
            cost+=sum;
            pq.push(sum);
        }
        
        return cost;
    }
};
