class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>>job;
        int n=deadline.size();
         
        for(int i=0;i<n;i++)   job.push_back({profit[i],deadline[i]});
        
        sort(job.begin(),job.end(),greater<pair<int,int>>());
        int maxDeadline=0;
        for(int x:deadline) maxDeadline=max(maxDeadline,x);
        vector<bool>visited(maxDeadline,0);
        
        int prof=0,total=0;
        for(int i=0;i<n;i++)
        {
            int tim=job[i].second;
            if(visited[tim-1]==0)
            {
                prof+=job[i].first;
                total++;
                visited[tim-1]=1;
            }
            else{
            for(int j=tim-2;j>=0;j--)
            {
                if(visited[j]==0)
                {
                    prof+=job[i].first;
                    total++;
                    visited[j]=1;
                    break;
                }
            }
            }
        }
        return {total,prof};
    }
};