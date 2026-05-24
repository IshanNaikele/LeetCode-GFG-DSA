class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        vector<vector<int>>v;
        vector<int>ans;
        int n=tasks.size();
        for(int i=0;i<n;i++)           v.push_back({tasks[i][0],tasks[i][1],i});
        
        sort(v.begin(),v.end());
        long long timer=v[0][0];
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        while(!pq.empty() || i<n )
        {
            while(i<n && timer>=v[i][0])
            {
                pq.push({v[i][1],v[i][2]});
                i++;
            }

            if(pq.empty() && i<n)
            timer=v[i][0];
            else
            {
                ans.push_back(pq.top().second);
                timer+=pq.top().first;
                pq.pop();
            }
        }
        return ans;
    }
};