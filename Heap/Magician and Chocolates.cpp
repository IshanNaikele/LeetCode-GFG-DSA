int Solution::nchoc(int A, vector<int> &B) 
{
     priority_queue<int>pq(B.begin(),B.end());
     long long maxChoco=0,mod=1e9+7;
     while(A--)
     {
          int currChoco=pq.top();
          pq.pop();
          pq.push(currChoco/2);
          maxChoco=(maxChoco+currChoco)%mod;
     }
     return int(maxChoco%mod);
}
