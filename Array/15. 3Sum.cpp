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