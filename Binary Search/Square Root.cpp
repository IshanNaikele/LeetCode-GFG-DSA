class Solution {
  public:
    int floorSqrt(int x) 
    {
        // code here
        if(x==0) return 0;
        if(x<=3) return 1; 
        int start=0,end=x/2,mid;

        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(mid==x/mid) return mid;
            else if(mid>x/mid) end=mid-1;
            else               start=mid+1;
        }
        return end;
    }
};