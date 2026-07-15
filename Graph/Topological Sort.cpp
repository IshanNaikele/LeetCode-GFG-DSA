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

class Solution {
  public:
    
    vector<int> bfs(vector<vector<int>>&adj,vector<int>&visited,vector<int>&indegree)
    {
        int V=adj.size();
        queue<int>q;
        for(int i=0;i<V;i++) 
        {
            if(indegree[i]==0) 
            {
                q.push(i);
                visited[i]=1;
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int src=q.front();
            ans.push_back(src);
            q.pop();
            
            for(int node:adj[src])
            {
                indegree[node]--;
                if(indegree[node]==0 && visited[node]==0) {
                    visited[node]=1;
                    q.push(node);
                }
            }
        }
        return ans;
    }
    
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
         
        vector<int>visited(V,0);
        vector<int>ans=bfs(adj,visited,indegree);
        return ans;
    }
};