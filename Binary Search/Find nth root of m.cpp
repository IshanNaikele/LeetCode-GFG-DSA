class Solution {
  public:
    int nthRoot(int n, int m) 
    {
        // Code here
        if(m==0) return 0;
        if(m==1) return 1;
        if(n==1) return m;
        int start=1,end=m/n,mid;
        int run=n;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            long long ans=1;
            int run=n;
            while(run--) ans*=mid;
            
            if(ans==m)       return mid;
            else if(ans>m)   end=mid-1;
            else             start=mid+1;
        }
        return -1;
    }
};