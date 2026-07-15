class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>&visited,int src)
    {
        queue<int>q;
        q.push(src);
        visited[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int num:graph[node])
            {
                if(visited[num]==0)
                {
                    q.push(num);
                    visited[num]=visited[node]*-1;
                }
                else
                {
                    if(visited[num]!=visited[node]*-1) return true;
                }
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v=graph.size();
        vector<int>visited(v,0);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==0)
            {
                if(bfs(graph,visited,i)) return false;
            }
        }
        return true;
    }
};