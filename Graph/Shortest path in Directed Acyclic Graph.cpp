class Solution 
{
    public:
    
    void dfs(vector<vector<pair<int,int>>>&adj,vector<int>&visited,stack<int>&st,int src)
    {
        int V=adj.size();
        visited[src]=1;
        
        for(auto node:adj[src])
        {
            int v=node.first;
            if(visited[v]==0)  dfs(adj,visited,st,v);
        }
        
        st.push(src);
    }
    
    vector<int>formDistArray(vector<vector<pair<int,int>>>&adj,stack<int>&st)
    {
        int V=adj.size();
        vector<int>dist(V,INT_MAX);
        
        dist[0]=0;
        
        while(!st.empty())
        {
            int src=st.top();
            int prevDist=dist[src];
            st.pop();
            if(dist[src]!=INT_MAX){
                for(auto p:adj[src])
                    dist[p.first]=min(dist[p.first],prevDist+p.second);
            }
        }
        return dist;
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back({v,weight});
        }
        vector<int>visited(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
            if(visited[i]==0)   dfs(adj,visited,st,i);
        
        vector<int>dist=formDistArray(adj,st);
        for(int i=0;i<V;i++)
        {
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};
