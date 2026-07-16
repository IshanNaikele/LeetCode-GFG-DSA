class Solution {
  public:
    string bfs(vector<vector<int>>&adj,vector<int>&indegree,vector<int>&present)
    {
        queue<int>q;
        int totalChars = 0;

        for (int i = 0; i < 26; i++) 
        {
            if (present[i]) {
                totalChars++;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        
       
        string ans="";
        while(!q.empty())
        {
            int src=q.front();
            q.pop();
            ans.push_back(src+'a');
            for(int node:adj[src])
            {
                indegree[node]--;
                if(indegree[node]==0) q.push(node);
            }
        }
        if(ans.size()!=totalChars) return "";
        return ans;
    }
    string findOrder(vector<string> &words) 
    {
        // code here
        vector<int> present(26, 0);

        // Mark all characters present
        for (string &word : words) {
            for (char ch : word)
                present[ch - 'a'] = 1;
        }
        
        int V=words.size();
        vector<vector<int>>adj(26);
        vector<int>indegree(26);
        for(int i=0;i<words.size()-1;i++)
        {
            string s1=words[i];
            string s2=words[i+1];
            
            int m=s1.size();
            int n=s2.size();
            int minSize=min(m,n);
            int j=0;
            for(j=0;j<minSize;j++)
            {
                if(s1[j]!=s2[j])  {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    break;
                }
            }
            if(j==minSize && s1.size()>s2.size())
                return "";
        }
        return bfs(adj,indegree,present);
    }
};