class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mpp;
        set<vector<int>>unique;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int compliment=(arr[i]+arr[j])*-1;
                if(mpp.find(compliment)!=mpp.end())
                   {
                       if(compliment<=arr[i])
                          unique.insert({compliment,arr[i],arr[j]});
                        else if(compliment>=arr[j])
                          unique.insert({arr[i],arr[j],compliment});
                        else
                          unique.insert({arr[i],compliment,arr[j]});
                   }
            }
            mpp[arr[i]]++;
        }
        vector<vector<int>>ans(unique.begin(),unique.end());
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++)
        {
            if(i!=0 && arr[i]==arr[i-1]) continue;
            int start=i+1,end=n-1;
            while(start<end)
            {
                int sum=arr[start]+arr[end]+arr[i];
                if(sum==0)
                {
                    ans.push_back({arr[i],arr[start],arr[end]});
                    start++;
                    end--;
                    while(start<end && arr[end]==arr[end+1]) end--;
                    while(start<end && arr[start]==arr[start-1]) start++;
                }
                else if(sum>0)   end--;     
                else             start++;      
            }   
        }
        
        return ans;
    }
};