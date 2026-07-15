class Solution {
  public:
    
    void dfs(vector<vector<int>>&adj,vector<int>&visited,stack<int>&st,int src)
    {
        visited[src]=1;
        for(int node:adj[src])
        {
            if(visited[node]==0) 
              dfs(adj,visited,st,node);
        }
        st.push(src);
    }
    
    vector<int>solve(vector<vector<int>>&adj,vector<int>&visited,stack<int>&st)
    {
        int V=adj.size();
        
        for(int i=0;i<V;i++){
            if(visited[i]==0)   
            dfs(adj,visited,st,i);
        }
        
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>visited(V,0);
        stack<int>st;
        vector<int>ans=solve(adj,visited,st);
        return ans;
    }
};