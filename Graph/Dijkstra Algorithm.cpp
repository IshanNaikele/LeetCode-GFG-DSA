class Solution {
  public:
   
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) 
    {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int u=p.second;
            
            for(auto it:adj[u])
            {
                int v=it.first;
                int weight=it.second;
                
                if(dist[v]>dist[u]+weight)
                {
                    dist[v]=dist[u]+weight;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};