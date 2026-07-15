class Solution {
  public:
    
    bool bfs(int src,vector<vector<int>>&adj,vector<int>&visited)
    {
        int V=adj.size();
        visited[src]=1;
        queue<pair<int,int>>q;
        q.push({-1,src});
        while(!q.empty())
        {
            auto top=q.front();
            int from=top.first;
            int curr=top.second;
            q.pop();
            for(auto it:adj[curr])
            {
                if(visited[it]==1 && it!=from) return true;
                if(visited[it]==0)
                {
                    q.push({curr,it});
                    visited[it]=1;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        // Code here
        vector<vector<int>>adj(V);
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i, adj, visited))
                    return true;
            }
        }
        
        return false;
    }
};