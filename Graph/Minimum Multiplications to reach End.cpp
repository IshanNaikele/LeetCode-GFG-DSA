class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) 
    {
        // code here
        int n=arr.size();
        vector<int>dist(1000,INT_MAX);
        dist[start]=0;
        
        queue<pair<int,int>>q;
        q.push({0,start});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int minSteps=p.first;
            int value=p.second;
            if(value==end) return minSteps;
            for(int i=0;i<n;i++)
            {
                int newValue=(value*arr[i])%1000;
                if(dist[newValue]==INT_MAX){
                    q.push({minSteps+1,newValue});
                    dist[newValue]=minSteps;
                }
            }
        }
        
        return (dist[end]==INT_MAX)?-1:dist[end];
    }
};    