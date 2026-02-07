class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int remain=pq.top();
            pq.pop();
            remain-=pq.top();
            pq.pop();
 
            pq.push(remain);
        }
        return pq.top();
    }
};
