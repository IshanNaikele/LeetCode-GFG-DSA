class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) 
    {
        // Your code goes here
        priority_queue<long long>pq;
        
        for(int i=0;i<N;i++)
        {
            pq.push(A[i]);
            if(pq.size()>=K2) pq.pop();
        }
        
        long long sum=0;
        while(pq.size()>K1)
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};