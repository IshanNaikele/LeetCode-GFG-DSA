class Solution {
  public:
    int findKRotation(vector<int> &arr) 
    {
        // Code Here
        int start=0,end=arr.size()-1,n=arr.size(),index=-1;
        
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]>=arr[n-1]) 
               start=mid+1;
            else 
            {
                index=mid;
                end=mid;
            }
        }
        return start;
    }
};
