// User function Template for C++

bool find4Numbers(int arr[], int n, int target) 
{ 
    sort(arr,arr+n);
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int start=j+1,end=n-1;
            while(start<end)
            {
                int sum=arr[start]+arr[end]+arr[i]+arr[j];
                if(sum==target) return true;
                else if(sum>target) end--;
                else                start++;
            }
        }
    }
    return false;
}