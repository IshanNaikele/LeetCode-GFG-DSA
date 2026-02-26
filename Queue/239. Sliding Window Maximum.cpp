class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k-1;i++)  
        {
            if(dq.empty()) dq.push_back(i);
            else    
            {
                while(!dq.empty() && nums[dq.back()]<nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }

        for(int i=k-1;i<n;i++)
        {
             
            while(!dq.empty() && nums[i]>nums[dq.back()])
            dq.pop_back();

            dq.push_back(i);
            if(dq.front() < i-k+1)   dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};