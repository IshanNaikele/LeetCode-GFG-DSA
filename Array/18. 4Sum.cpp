class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && arr[i]==arr[i-1])
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && arr[j]==arr[j-1] ) continue;
                int start=j+1,end=n-1;
                while(start<end)
                {
                    long long sum=(long long)arr[start]+arr[end]+arr[i]+arr[j];
                    if(sum==target)
                    {
                        ans.push_back({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                        while(start<end && arr[end]==arr[end+1]) end--;
                        while(start<end && arr[start]==arr[start-1]) start++;
                    }
                    else if(sum>target)   end--;     
                    else                  start++;      
                }   
            }
        }
        
        return ans;
    }
};