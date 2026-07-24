class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) 
    {
        // code here
        int n=arr.size();
        vector<vector<int>>train;
        for(int i=0;i<n;i++)
            train.push_back({arr[i],dep[i]});
        sort(train.begin(),train.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(train[0][1]);
        
        for(int i=1;i<n;i++)
        {
            int tim=pq.top();
            if(tim<train[i][0])
               pq.pop();
              
            pq.push(train[i][1]);
        }
        return pq.size();
    }
};
