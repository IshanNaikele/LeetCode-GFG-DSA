class Solution {
  public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int node)
    {
        visited[node]=1;
        for(int num:adj[node])
        {
            if(visited[num]==0)
            dfs(adj,visited,num);
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) 
    {
        // code here
        int n=edges.size(),count=0;
        vector<vector<int>>adj(V);
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0){
               dfs(adj,visited,i);
               count++;
            }
        }
        
        return count;
    }
};