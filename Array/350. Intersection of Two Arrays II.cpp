class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>store(1001,0);
        vector<int>ans;
        for(int num:nums1)  store[num]++;
      
        for(int num:nums2)
        {
            if(store[num]>0)
            {
                ans.push_back(num);
                store[num]--;
            }
        }
        return ans;
    }
};