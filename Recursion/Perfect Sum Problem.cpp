class Solution {
  public:
    void subseq(vector<int>&arr,int index,int target,int &count)
    {
        int n=arr.size();
        
        if(index>=n)  
        { 
            if(target==0) count++;
            return;
        }
        //Not Included
        subseq(arr,index+1,target,count);
        //Included 
        subseq(arr,index+1,target-arr[index],count);
        
    }
    int perfectSum(vector<int>& arr, int target) 
    {
        // code here
        int index=0,count=0;
        subseq(arr,index,target,count);
        return count;
    }
};