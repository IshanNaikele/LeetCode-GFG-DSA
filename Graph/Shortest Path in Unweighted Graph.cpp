class Solution {
  public:
     
    int bfs(vector<vector<int>>&adj,vector<int>&visited,int source,int dest)
    {
        queue<int>q;
        q.push(source);
        visited[source]=1;
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int src=q.front();
                if(src==dest) return count;
                q.pop();
                for(int node:adj[src])
                {
                    if(visited[node]==0)
                    {
                        q.push(node);
                        visited[node]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) 
    {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        
        return bfs(adj,visited,src,dest);
    }
};
