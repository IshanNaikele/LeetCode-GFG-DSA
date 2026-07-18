class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {

        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);

        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int price=flights[i][2];

            adj[u].push_back({v,price});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int stops=p.first;
            int u=p.second.first;
            int dt=p.second.second;
            
            if(stops>k) continue;
            for(auto it:adj[u])
            {
                int v=it.first;
                int wt=it.second;
                
                if(dist[v]>dt+wt )
                {
                    dist[v]=dt+wt;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};