class Solution 
{
public:
    void dfsTraversal(vector<vector<int>>&isConnected,vector<int>&visited,int node)
    {
        visited[node]=1;
        int n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            if(isConnected[node][i]==1 && visited[node]==0)
            dfsTraversal(isConnected,visited,node);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size(),count=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {   
            if(visited[i]==0)
            {
                dfsTraversal(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};