class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) 
    {
        // code here
        vector<pair<int,int>>vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({start[i],finish[i]});
        }
        
        sort(vec.begin(),vec.end(),[] (const pair<int,int>&a,const pair<int,int>&b)
        {
            return a.second<b.second;
        });
        
        int maxMeeting=1;
        vector<pair<int,int>>ans;
        ans.push_back({vec[0].first,vec[0].second});
        for(int i=1;i<vec.size();i++)
        {
            int start=vec[i].first,end=vec[i].second;
            int n=ans.size();
            int prevStart=ans[n-1].first,prevEnd=ans[n-1].second;
            
            if(prevEnd<start)
            {
                ans.push_back({start,end});
                maxMeeting++;
            }
        }
        return maxMeeting;
    }
};