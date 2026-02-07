class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<long long>pq(gifts.begin(),gifts.end());

        while(k--)
        {
            long long gift=pq.top();
            pq.pop();
            pq.push(sqrt(gift));
        }
        long long total_gifts=0;
        while(!pq.empty())
        {
            total_gifts+=pq.top();
            pq.pop();
        }
        return total_gifts;
    }
};