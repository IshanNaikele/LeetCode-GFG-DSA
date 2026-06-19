class Solution {
  public:
    int countFreq(vector<vector<int>> &mat,int num)
    {
        int row=mat.size(),col=mat[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            int start=0,end=col-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                
                if(mat[i][mid]<=num) start=mid+1;
                else                 end=mid-1;
            }
            count+=(start);
        }
        return count;
    }
    
    int binarySearch(vector<vector<int>> &mat )
    {
        int row=mat.size(),col=mat[0].size();
        int count=(row*col)/2;
        int start=INT_MAX,end=INT_MIN;
        
        for(int i=0;i<row;i++)
        {
            start=min(start,mat[i][0]);
            end=max(end,mat[i][col-1]);
        }
        
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int freq=countFreq(mat,mid);
            
            
            if(freq>count)  end=mid-1;
            else            start=mid+1;
        }
        return start;
    }
    int median(vector<vector<int>> &mat) 
    {
        // code here
        return binarySearch(mat);
    }
};
