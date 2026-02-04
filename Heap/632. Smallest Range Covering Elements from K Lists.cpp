class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        priority_queue<
                       pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>
                      >pq;
        int maxElement=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i][0]>maxElement)
            maxElement=nums[i][0];
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
        }
        vector<int>ans;
        pair<int,pair<int,int>>element;
        element=pq.top();
        ans={element.first,maxElement};
        int difference=maxElement-pq.top().first;
        int i,j,num;
        while(!pq.empty())
        {
            element=pq.top();
            num=element.first;
            i=element.second.first;
            j=element.second.second;
            pq.pop();
            int currDiff=maxElement-num;
            if(difference>currDiff)
            {
                difference=currDiff;
               ans={num,maxElement};
            }
            if(j+1<nums[i].size())
            {
                if(maxElement<nums[i][j+1]) maxElement=nums[i][j+1];
                pq.push(make_pair(nums[i][j+1],make_pair(i,j+1)));
            }
            else 
            break;
        }
        return ans;
    }
};