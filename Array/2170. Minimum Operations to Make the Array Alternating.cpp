class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) return 0;
        unordered_map<int,int>mpp1,mpp2;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) mpp1[nums[i]]++;
            else       mpp2[nums[i]]++;
        }

        int even=0,odd=0;
        if(n%2==0) 
        {
            even=n/2;
            odd=n/2;
        }
        else
        {
            even=(n/2)+1;
            odd=n/2;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>>pq1,pq2;
        for(auto &it:mpp1) pq1.push({it.second,it.first});
        for(auto &it:mpp2) pq2.push({it.second,it.first});

        pair<int,int>temp1=pq1.top();
        pq1.pop();
        pair<int,int>temp2=pq2.top();
        pq2.pop();
        int ans=0;
        if(temp1.second==temp2.second)
        {
            int opr1,opr2;
            if(!pq1.empty())
            opr1=even-pq1.top().first;
            else
            opr1=even;

            opr1+=(odd-temp2.first);

            if(!pq2.empty())
            opr2=odd-pq2.top().first;
            else 
            opr2=odd;

            opr2+=(even-temp1.first);

            ans=min(opr1,opr2);
        }
        else
         ans=(even-temp1.first)+(odd-temp2.first);

        return ans;
    }
};