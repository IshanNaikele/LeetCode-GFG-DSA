class Solution 
{
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&visited,int source,int destination)
    {
        if(source == destination)
        return true;
        visited[source]=1;
        for(int node:adj[source])
        {
            if(visited[node]==0)
            {
                visited[node]=1;
                dfs(adj,visited,node,destination);
            }
        }
        return visited[destination];
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>>adj(n);
        int edg=edges.size();
        for(int i=0;i<edg;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        return dfs(adj,visited,source,destination);
    }
};