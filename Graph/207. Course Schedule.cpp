class Solution {
public:
    vector<int> bfs(vector<vector<int>>&adj,vector<int>&indegree)
    {
        int V=adj.size();
        queue<int>q;
        for(int i=0;i<V;i++) 
        {
            if(indegree[i]==0) 
                q.push(i);
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
                if(indegree[node]==0 )
                    q.push(node);
            }
        }
        return ans;
    }

    bool canFinish(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        
        vector<int>ans=bfs(adj,indegree);
        return ans.size()==V;
    }
};