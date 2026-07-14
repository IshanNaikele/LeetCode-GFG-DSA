class Solution {
  public:
    void bfsTraversal(vector<vector<int>>&adj,vector<int>&ans,vector<int>&visited)
    {
        queue<int>q;
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(int num:adj[top])
            {
                if(visited[num]==0)
                q.push(num);
                visited[num]=1;
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) 
    {
        // code here
        int n=adj.size();
        vector<int>ans;
        vector<int>visited(n,0);
        bfsTraversal(adj,ans,visited);
        return ans;
    }
};