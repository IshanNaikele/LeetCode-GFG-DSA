class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) 
    {
        // Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++)
        {
            int start=i+1,end=n-1;
            
            while(start<end)
            {
                int sum=arr[start]+arr[end]+arr[i];
                if(sum==target)
                return true;
                else if(sum>target) end--;
                else                start++;
            }
        }
        return false;
    }
};