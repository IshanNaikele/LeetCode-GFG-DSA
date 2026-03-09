class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) 
    {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        
        int maxTime=0;
        int n=mices.size();
        for(int i=0;i<n;i++)   maxTime=max(maxTime,abs(mices[i]-holes[i]));
        
        return maxTime;
    }
};