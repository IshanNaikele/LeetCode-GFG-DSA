class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
       int n=arr.size(),q=queries.size(),prefixXOR=0;
       vector<int>store(n,0);
        for(int i=0;i<n;i++) 
        {
            prefixXOR^=arr[i];
            store[i]=prefixXOR;
        }  
        vector<int>ans;
        for(int i=0;i<q;i++)
        {
            int left=queries[i][0],right=queries[i][1];
            if(left==0) ans.push_back(store[right]);
            else        ans.push_back(store[right]^store[left-1]);
        }

        return ans;
    }
};