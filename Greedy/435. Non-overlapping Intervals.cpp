class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int count=0,n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(end>intervals[i][0])  
            {
                end = min(end, intervals[i][1]);
                count++;
            }
            else                     start=intervals[i][0],end=intervals[i][1];
            
        }
        return count;
    }
};