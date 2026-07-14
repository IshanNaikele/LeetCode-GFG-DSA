class Solution 
{
  public:
    void dfsTraversal(vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans,int node)
    {
        visited[node]=1;
        ans.push_back(node);
        for(int num:adj[node])
        {
            if(visited[num]==0)
            dfsTraversal(adj,visited,ans,num);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) 
    {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<int>visited(n,0);
        dfsTraversal(adj,visited,ans,0);
        return ans;
    }
};