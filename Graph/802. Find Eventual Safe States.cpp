class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathVisited,vector<int>&safeNodes,int src )
    {
        visited[src]=1;
        pathVisited[src]=1;
        for(int node:adj[src])
        {
            if(visited[node]==0){
               if(dfs(adj,visited,pathVisited,safeNodes,node)){ 
                    safeNodes[node]=0;
                    return true;
               }
            } 
            else if(pathVisited[node]==1) {
                safeNodes[node]=0;
                return true; 
            }
        }
        pathVisited[src]=0;
        safeNodes[src]=1;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V=graph.size();
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        vector<int>safeNodes(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++)
            if(visited[i]==0)    if(dfs(graph,visited,pathVisited,safeNodes,i)) continue;
        
        for(int i=0;i<V;i++)
            if(safeNodes[i]==1) ans.push_back(i);
        
        return ans;
    }
};